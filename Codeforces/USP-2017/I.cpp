#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ll, ll > ii;
typedef vector< ll > vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s))
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pi acos(-1.0)
#define eps 1e-5


const int N = 4002;
const int M = 202;

int n, m;
double a[N][M], b[N], c[M], d[N][M];
int ix[N + M]; 

double simplex() {
	++m;
	int r = n, s = m - 1;
	memset(d, 0, sizeof(d));
	for (int i = 0; i < n + m; ++i) ix[i] = i;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j) d[i][j] = -a[i][j];
		d[i][m - 1] = 1;
		d[i][m] = b[i];
		if (d[r][m] > d[i][m]) r = i;
	}
	for (int j = 0; j < m - 1; ++j) d[n][j] = c[j];
	d[n + 1][m - 1] = -1;
	for (double dd;; ) {
		if (r < n) {
			int t = ix[s]; ix[s] = ix[r + m]; ix[r + m] = t;
			d[r][s] = 1.0 / d[r][s];
			for (int j = 0; j <= m; ++j) if (j != s) d[r][j] *= -d[r][s];
			for (int i = 0; i <= n + 1; ++i) if (i != r) {
				for (int j = 0; j <= m; ++j) if (j != s) d[i][j] += d[r][j] * d[i][s];
				d[i][s] *= d[r][s];
			}
		}
		r = -1; s = -1;
		for (int j = 0; j < m; ++j) if (s < 0 || ix[s] > ix[j]) {
			if (d[n + 1][j] > eps || (d[n + 1][j] > -eps && d[n][j] > eps)) s = j;
		}
		if (s < 0) break;
		for (int i = 0; i < n; ++i) if (d[i][s] < -eps) {
			if (r < 0 || (dd = d[r][m] / d[r][s] - d[i][m] / d[i][s]) < -eps 
				|| (dd < eps && ix[r + m] > ix[i + m])) r = i;
		}
		if (r < 0) return -1;
	}
	if (d[n + 1][m] < -eps) return -1;
	double ans = 0;
	for (int i = m; i < n + m; ++i) { 
		if (ix[i] < m - 1) ans += d[i - m][m] * c[ix[i]];
	}
	return ans;
}


int main() {
	scanf("%d %d", &m, &n);
	for(int i = 0; i < m; ++i) scanf("%lf", c + i);
	for(int i = 0; i < n; ++i) {
		int l, r, w; scanf("%d %d %d", &l, &r, &w);
		for(int j = l - 1; j <= r - 1; ++j) a[i][j] = 1;
		b[i] = w;
	}
	printf("%.lf\n", simplex());
	return 0;
}