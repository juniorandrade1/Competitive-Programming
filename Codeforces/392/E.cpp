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
#define PI acos(-1)
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 200020;

int n;
int deg[N];
ll pai[N], p[N], w[N], id[N];
ll sub[N];

ll pesoQueVem[N];

int main() {
  scanf("%d", &n);
  for(int i = 1; i < n; ++i) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    deg[a]++;
    pai[b] = a;
    w[b] = c;
    p[b] = d;
    id[i] = b;
  }

  queue<int>q;
  for(int i = 1; i <= n; ++i) if(deg[i] == 0) q.push(i);
  while(!q.empty()) {
    int x = q.front(); q.pop();
    if(x == 1) break;
    if(pesoQueVem[x] > p[x]) {
      puts("-1");
      return 0;
    }

    ll diff = min(p[x] - pesoQueVem[x], min(p[x], w[x] - 1));
    sub[x] = diff;
    p[x] -= diff;
    w[x] -= diff;
    pesoQueVem[pai[x]] = pesoQueVem[x] + w[x];
    deg[pai[x]]--;
    if(deg[pai[x]] == 0) q.push(pai[x]);
  }
  printf("%d\n", n);
  for(int i = 1; i < n; ++i) {
    int ix = id[i];
    printf("%lld %d %lld %lld\n", pai[ix], ix, w[ix], p[ix]);
  }

  return 0;
}