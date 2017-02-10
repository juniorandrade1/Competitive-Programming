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
#define pi acos(-1.0)
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

struct Point {
  ll x, y, id;
  Point(){};
  Point(ll _x, ll _y) {
    x = _x;
    y = _y;
  }
  void read(int _id) {
    scanf("%lld %lld", &x, &y);
    id = _id;
  }
  ll Mdistance(Point p) {
    return abs(x - p.x) + abs(y - p.y);
  }
};

const int N = 100010;

Point p[N];
int n;
vector< pair<ll, ii> > edge;

bool cmpX(Point a, Point b) {
  if(a.x != b.x) return a.x < b.x;
  else return a.y < b.y;
}

bool cmpY(Point a, Point b) {
  if(a.y != b.y) return a.y < b.y;
  else return a.x < b.x;
}

bool cmpXY(Point a, Point b) {
  return a.x + a.y < b.x + b.y;
}

int pset[N];
int fnd(int i) { return (pset[i] == i) ? i : (pset[i] = fnd(pset[i])); }
void uni(int i, int j) { pset[fnd(i)] = fnd(pset[j]); }
bool same(int i, int j) { return fnd(i) == fnd(j); }

map< ii, bool > exists;


int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) p[i].read(i);
  sort(p, p + n, cmpXY);

  return 0;
}