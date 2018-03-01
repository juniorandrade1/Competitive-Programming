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

const int N = 100011;

ii join(ii a, ii b) {
  vi all; all.pb(a.F); all.pb(a.S); all.pb(b.F); all.pb(b.S);
  sort(all.rbegin(), all.rend());
  return ii(all[0], all[1]);
}

int n;
int p[N];
ii a[N];
int cnt[N];

int main() {
  scanf("%d", &n);
  a[i] = ii(0, 0);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", p + i);
    ii f = ii(p[i], 0);
    a[i] = join(a[i - 1], f);
  }
  for(int i = 1; i <= n; ++i) if(a[i].F == p[i]) cnt[a[i].F]++;
  for(int i = 1; i <= n; ++i) if(a[i].S == p[i]) cnt[p[i]]--;
  int mx = *max_element(cnt, cnt + n + 1);
  for(int i = 1; i <= n; ++i) {
    if(mx == cnt[i]) {
      printf("%d\n", i);
      exit(0);
    }
  }
  return 0;
}