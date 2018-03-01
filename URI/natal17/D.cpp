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

const int N = 100010;

struct Presente {
  int id;
  ll h, w, l;
  Presente(){};
  void read() {
    scanf("%d %lld %lld %lld", &id, &h, &w, &l);
  }
  bool operator < (Presente other) const {
    ll v0 = h * w * l;
    ll v1 = other.h * other.w * other.l;
    if(v0 != v1) return v0 > v1;
    else return id < other.id;
  }
};

int n, k;
Presente p[N];

bool cmpId(Presente a, Presente b) {
  return a.id < b.id;
}

inline void main2() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i) p[i].read();
  sort(p, p + n);
  sort(p, p + k, cmpId);
  for(int i = 0; i < k; ++i) {
    if(i) printf(" ");
    printf("%d", p[i].id);
  }
  printf("\n");
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}