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

const int N = 200020;

int n, k, p;
int v[N];
char s[N];
int pd[N];
int ans[N];


int main() {
  scanf("%d %d %d", &n, &k, &p);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", v + i);
    v[i + n] = v[i];
  }
  k = min(k, n);
  vi aux;
  for(int i = 1; i < 2 * n; ++i) {
    pd[i] = pd[i - 1] + v[i];
    if(i >= k) aux.pb(pd[i] - pd[i - k]);
  }
  int qtd = n - k + 1;
  multiset<int>bst;
  int sz = 0;
  for(int i = 0; i < aux.size(); ++i) {
    bst.insert(aux[i]);
    if(bst.size() > qtd) bst.erase(bst.find(aux[i - qtd]));
    if(bst.size() == qtd) ans[++sz] = *(bst.rbegin());
  }
  assert(sz == n);
  int stPos = 1;
  scanf(" %s", s);
  int len = strlen(s);
  for(int i = 0; i < len; ++i) {
    assert(stPos >= 1 && stPos <= n);
    if(s[i] == '?') printf("%d\n", ans[stPos]);
    else stPos--;
    if(stPos < 1) stPos += n;
  }
  return 0;
}