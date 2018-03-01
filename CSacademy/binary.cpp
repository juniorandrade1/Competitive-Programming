#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
//////////////////////

void arquivo() {
  freopen("","r",stdin);
  freopen("","w",stdout);
}

const int N = 200010;

int n;
int v[N];
int bit[N];
int csum[N];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", v + i);
    if(v[i] == 1) v[i] = -1;
    else v[i] = 1;
    csum[i] = csum[i - 1] + v[i];
  }
  set< int > s;
  for(int i = 1; i <= n; ++i) {
    s.insert(csum[i - 1]);
    int l = csum[i] - *s.rbegin();
    int r = csum[i] - *s.begin();
    l += N / 2;
    r += N / 2;
    bit[l]++;
    bit[r + 1]--;
  }
  int ans = 0;
  for(int i = 1; i < N; ++i) {
    bit[i] += bit[i - 1];
    if(i == N / 2) continue;
    ans += (bit[i] > 0);
  }
  printf("%d\n", ans + 1);
  return 0;
} 