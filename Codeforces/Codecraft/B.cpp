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

const int N = 500000;

int n;
ll v[N];
int is[N];
int maxi = 1;

void crivo() {
  for(int i = 2; i < N; ++i) if(!is[i]) for(int j = 1; j * i < N; ++j) is[i * j] = i;
}

int qtdDiv[N];
set<int>s;

void factorize(int x) {
  s.clear();
  while(x > 1) {
    s.insert(is[x]);
    x /= is[x];
  }
  for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
    qtdDiv[*it]++;
    maxi = max(maxi, qtdDiv[*it]);
  }
}

int main() {
  crivo();
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%lld", v + i);
    factorize(v[i]);
  }
  printf("%d\n", maxi);
  return 0;
}