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

const int N = 1000010;

int n, r;
vi g[N];
int h[N], in[N], out[N], nodeCounter = 1;
int a[N];
vii ba;


void dfs(int x, int ult) {
	ba.pb(mp(h[x], a[x]));
	in[x] = nodeCounter++;
	for(int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if(y == ult) continue;
		h[y] = h[x] + 1;
		dfs(y, x);
	}
	out[x] = nodeCounter;
}

vii tr[N];
vi minC[N];

void build(int no, int l, int r) {
	if(l == r) {
		tr[no].pb(ba[l - 1]);
		minC[no].pb(INF);
		for(int i = 0; i < tr[no].size(); ++i) minC[no].pb(min(minC[no][i], tr[no][i].second));
		return;
	}
	int nxt = (no << 1), mid = (l + r) >> 1;
	build(nxt, l, mid); build(nxt + 1, mid + 1, r);
	tr[no].resize(tr[nxt].size() + tr[nxt + 1].size());
	merge(tr[nxt].begin(), tr[nxt].end(), tr[nxt + 1].begin(), tr[nxt + 1].end(), tr[no].begin());
	minC[no].pb(INF);
	for(int i = 0; i < tr[no].size(); ++i) minC[no].pb(min(minC[no][i], tr[no][i].second));
}

int query(int no, int l, int r, int i, int j, int k) {
	if(r < i || l > j) return INF;
	if(l >= i && r <= j) {
		int id = upper_bound(tr[no].begin(), tr[no].end(), ii(k, 0)) - tr[no].begin();
		return minC[no][id];
	}
	int nxt = (no << 1), mid = (l + r) >> 1;
	return min(query(nxt, l, mid, i, j, k), query(nxt + 1, mid + 1, r, i, j, k));
}

int main() {
	scanf("%d %d", &n, &r);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i);
	for(int i = 0; i + 1 < n; ++i) {
		int x, y; scanf("%d %d", &x, &y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(r, r);	
	build(1, 1, n);
	int m; scanf("%d", &m);
	int last = 0;
	while(m--) {
		int p, q; scanf("%d %d", &p, &q);
		int x = (p + last) % n + 1, k = (q + last) % n + 1;
		last = query(1, 1, n, in[x], out[x], h[x] + k);
		printf("%d\n", last);
	}
	return 0;
}