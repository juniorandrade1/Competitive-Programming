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

const int N = 100010;

struct no {
  int v;
  int l, r;
};

int n;
no vet[N];
int killed[N];

inline void main2() {
  scanf("%d", &n);
  queue< ii > q;
  for(int i = 0; i < n; ++i) {
    scanf("%d", &vet[i].v);
    vet[i].l = i - 1;
    vet[i].r = i + 1;
    killed[i] = 0;
  }
  for(int i = 0; i + 1 < n; ++i) if(vet[i].v > vet[i + 1].v) {
    q.push(mp(i + 1, 0)); //will be killed
    killed[i + 1] = 1;
  }
  int step = 0;
  while(!q.empty()) {
    ii foo = q.front(); q.pop();
    step = foo.S;
    int x = foo.F;
    int lstX = vet[x].l;
    int nxtX = vet[x].r;
    if(lstX >= 0) vet[lstX].r = nxtX;
    if(nxtX < n) {
      vet[nxtX].l = lstX;
      if(lstX >= 0 && vet[lstX].v > vet[nxtX].v && !killed[nxtX]) {
        q.push(mp(nxtX, foo.S + 1));
        killed[nxtX] = 1;
      }
    }
  }
  printf("%d\n", step + 1);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}