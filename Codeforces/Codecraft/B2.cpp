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
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 1e5 + 10;

int n;
ll v[N];
int is[N];

void crivo() {
  for(int i = 2; i < N; ++i) if(!is[i]) for(int j = 1; j * i < N; ++j) is[i * j] = i;
}

map<int, int> qtdDiv;
map<int, int> cnt;
vii aux;

void back(int pos, int at) {
  if(pos == aux.size()) {
    qtdDiv[at]++;
    return;
  }
  ll f = 1;
  for(int i = 0; i <= aux[pos].S; ++i) {
    back(pos + 1, f);
    f *= aux[pos].F;
  }
}

void findDivisors(int x) {
  cnt.clear();
  if(x == 1) {
    qtdDiv[1]++;
    return;
  }
  while(x > 1) {
    cnt[is[x]]++;
    x /= is[x];
  }
  aux.clear();
  for(map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) aux.pb(mp(it->F, it->S));
  back(0, 1);
}

int main() {
  crivo();
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%lld", v + i);
    findDivisors(v[i]);
  }

  for(int i = N - 1; i >= 0; --i) {
    if(qtdDiv[i] > 1) {
      printf("%d\n", i);
      return 0;
    }
  }
  
  return 0;
}