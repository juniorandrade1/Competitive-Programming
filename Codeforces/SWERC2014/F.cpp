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

const int N = 100001;

struct rectangle {
  ll x, y, w, h;
  rectangle(){};
  rectangle(int _x, int _y, int _w, int _h) {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
  }
};

int n;
vector< rectangle > v;

struct ufind {
  int pset[N];
  ll sset[N];
  ufind(){};
  ufind(int _n) {
    for(int i = 0; i < _n; ++i) {
      pset[i] = i;
      sset[i] = v[i].w * v[i].h;
    }
  }
  int fnd(int i) { return (pset[i] == i) ? i : (pset[i] = fnd(pset[i])); }
  void uni(int i, int j) {
    int x = fnd(i), y = fnd(j);
    if(x != y) {
      sset[y] += sset[x];
      sset[x] = 0;
      pset[x] = y;
    }
  }
  ll getArea(int i) {
    return sset[fnd(i)];
  }
};

int inside[N];
ufind sets;


inline void processHorizontal() {
  vii sweep;
  for(int i = 0; i < v.size(); ++i) {
    int xi = v[i].x;
    int xf = v[i].x + v[i].w;
    sweep.pb(ii(xi, i));
    sweep.pb(ii(xf, i));
  }
  sort(sweep.begin(), sweep.end());
  for(int i = 0; i < sweep.size(); ++i) {
    int j = i;
    while(j < sweep.size() && sweep[j].F == sweep[i].F) j++;
    vi in, out;
    for(int k = i; k < j; ++k) {
      if(inside[sweep[k].S]) in.pb(sweep[k].S);
      else out.pb(sweep[k].S);
    }
    for(int k = 0; k < in.size(); ++k)  {
      for(int l = 0; l < out.size(); ++l) {
        int posIn = in[k];
        int posOut = out[l];
        if((v[posIn].y >= v[posOut].y && v[posIn].y <= v[posOut].y + v[posOut].h) || 
          (v[posIn].y + v[posIn].h >= v[posOut].y && v[posIn].y + v[posIn].h <= v[posOut].y && v[posOut].h)) sets.uni(posIn, posOut);

        swap(posIn, posOut);
        if((v[posIn].y >= v[posOut].y && v[posIn].y <= v[posOut].y + v[posOut].h) || 
          (v[posIn].y + v[posIn].h >= v[posOut].y && v[posIn].y + v[posIn].h <= v[posOut].y && v[posOut].h)) sets.uni(posIn, posOut);
      }
    }
    for(int k = i; k < j; ++k) inside[sweep[k].S] ^= 1;
    i = j - 1;
  }
}


inline void processVertical() {
  for(int i = 0; i < v.size(); ++i) {
    swap(v[i].x, v[i].y);
    swap(v[i].w, v[i].h);
  }
  processHorizontal();
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int x, y, w, h; scanf("%d %d %d %d", &x, &y, &w, &h);
    v.pb(rectangle(x, y, w, h));
  }
  sets = ufind(n);
  processHorizontal();
  processVertical();
  ll ans = 0;
  for(int i = 0; i < n; ++i) ans = max(ans, sets.getArea(i));
  printf("%lld\n", ans);
  return 0;
}