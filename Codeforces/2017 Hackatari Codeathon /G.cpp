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

void arquivo() {
  freopen("crossroad.in", "r", stdin);
  freopen("crossroad.out", "w", stdout);
}

const int N = 100001;

int n, s;
int v[N];
double p[N];


int main() {
  //arquivo();
  scanf("%d %d", &n, &s);
  for(int i = 1; i <= n; ++i) scanf("%d", v + i);
  for(int i = 1; i <= n; ++i) scanf("%lf", p + i);
  double ans = 0;
  int left, right;
  left = right = n;  
  double t = 0;
  for(int i = n - 1; i >= 1; --i) {
    while(v[left] < v[i]) {
      t += (1 - p[left]);
      left--;
    }
    while(v[right] + s <= v[i]) {
      t -= (1 - p[right]);
      right--;
    }
    ans += t * p[i];
  }
  printf("%.10lf\n", ans);
  return 0;
}