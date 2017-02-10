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

const int N = 100001;

int pset[N];
int fnd(int i){ return (pset[i] == i) ? i : (pset[i] = fnd(pset[i])); }
void uni(int i, int j){ pset[fnd(i)] = fnd(pset[j]); }
void init() { for(int i = 0; i < N; ++i) pset[i] = i; }

struct edge {
  int x, y, r, p, id;
  edge(){};
  edge(int _x, int _y, int _r, int _p, int _id) {
    x = _x;
    y = _y;
    r = _r;
    p = _p;
    id = _id;
  }
};

bool cmpKrusk(edge a, edge b) {
  if(a.r != b.r) return a.r > b.r;
  else return a.p > b.p;
}

bool cmpOutput(edge a, edge b) {
  if(a.r != b.r) return a.r < b.r;
  else return a.p < b.p;
}

int m;
map<int, int>nor;
int n = 0;

int getIdx(int x) {
  if(nor.find(x) == nor.end()) nor[x] = n++;
  return nor[x];
}

vector< edge > vet;

void arquivo() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

int main() {
  arquivo();
  scanf("%d", &m);
  for(int i = 0; i < m; ++i) {
    int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
    a = getIdx(a);
    b = getIdx(b);
    vet.pb(edge(a, b, c, d, i + 1));
  }
  init();
  sort(vet.begin(), vet.end(), cmpKrusk);
  ll ans = 0;
  for(int i = 0; i < m; ++i) {
    if(fnd(vet[i].x) != fnd(vet[i].y)) {
      uni(vet[i].x, vet[i].y);
      ans += vet[i].p;
    }
  }
  printf("%lld\n", ans);
  sort(vet.begin(), vet.end(), cmpOutput);
  for(int i = 0; i < vet.size(); ++i) {
    if(i) printf(" ");
    printf("%d", vet[i].id);
  }
  printf("\n");

  return 0;
}