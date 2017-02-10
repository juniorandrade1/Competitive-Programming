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
#define PI 2*acos(0)

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

const int N = 100010;
const int M = 20;

set<ii>s;
map<int, int>rev;
int h[N];
int lca[N][M], pd[N][M];
int v[N];

int getAns(int a, int b) {
  int ans = 0;
  if(h[a] < h[b]) swap(a, b);
  int d = h[a] - h[b];
  for(int i = M - 1; i >= 0; --i) if((d >> i) & 1) {
    ans = max(ans, pd[a][i]);
    a = lca[a][i];
  }
  if(a == b) return ans;
  for(int i = M - 1; i >= 0; --i) if(lca[a][i] != lca[b][i]) {
    ans = max(ans, max(pd[a][i], pd[b][i]));
    a = lca[a][i];
    b = lca[b][i];
  }
  return max(ans, max(pd[a][0], pd[b][0]));
}

int main() {
  int n; scanf("%d", &n);
  int x; scanf("%d", &x);
  v[0] = x;
  rev[x] = 0;
  s.insert(ii(x, 0));
  for(int i = 1; i < n; ++i) {
    scanf("%d", &x);
    v[i] = x;
    rev[x] = i;
    s.insert(ii(x, -1));
    set<ii>::iterator it1, it2;
    it1 = s.lower_bound(ii(x, -1));
    it2 = s.lower_bound(ii(x, -1));
    it2++;
    ii at;

    int p = 0;

    if(it1 == s.begin()) {
      at = ii(x, it2->S + 1);
      p = it2->F;
      //printf("%lld ", it2->F);
    }
    else if(it2 == s.end()) {
      it1--;
      at = ii(x, it1->F + 1);
      p = it1->F;
      //printf("%lld ", it1->F);
    }
    else {
      it1--;
      if(it1->S > it2->S) {
        p = it1->F;
        //printf("%lld ", it1->F);
      }
      else {
        p = it2->F;
        //printf("%lld ", it2->F);
      }
      at = ii(x, max(it1->S, it2->S) + 1);
    }

    s.erase(ii(x, -1));
    s.insert(at);

    p = rev[p];

    h[i] = h[p] + 1;
    lca[i][0] = p;
    pd[i][0] = max(v[i], v[p]);
    for(int j = 1; j < M; ++j) {
      lca[i][j] = lca[lca[i][j - 1]][j - 1];
      pd[i][j] = max(pd[i][j - 1], pd[lca[i][j - 1]][j - 1]);
    }
  }

  int a, b; scanf("%d %d", &a, &b);
  a = rev[a]; b = rev[b];

  //debug("-> %d %d\n", a, b);

  printf("%d\n", getAns(a, b));

  //printf("\n");
  return 0;
}