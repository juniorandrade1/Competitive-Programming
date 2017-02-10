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
#define eps 1e-6

const double PI = acos(-1.0);

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 100010;

int n;
ll v[N];

inline void main2() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);
  int l = 0, r = n - 1;
  int qtd = 0;
  while(l < r) {
    if(v[l] == v[r]) {
      l++; r--;
    }
    else if(v[l] < v[r]) {
      v[l + 1] += v[l];
      l++;
      qtd++;
    }
    else {
      v[r - 1] += v[r];
      r--;
      qtd++;
    }
  }
  printf("%d\n", qtd);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}