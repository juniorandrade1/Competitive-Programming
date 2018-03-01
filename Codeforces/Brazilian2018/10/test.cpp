#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define EPS 1e-7
#define PI  3.1415926535897932384626433832795028841971693993
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif


//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};  
//////////////////////

typedef long long CHType;

#define CHINF LINF
struct Line {
  CHType m, b;
  Line(){};
  Line(CHType _m, CHType _b) {
    m = _m;
    b = _b;
  }
  bool operator < (Line other) const {
    if(m != other.m) return m > other.m;
    return b > other.b;
  }
  CHType getVal(CHType x) {
    return m * x + b;
  }
};

struct ConvexHullTrick {
  vector< Line > st;
  bool badLine(Line s, Line t, Line u) {
    if(t.m == u.m) return true;
    return 1.0 * (t.b - s.b) * (s.m - u.m) >= 1.0 * (u.b - s.b) * (s.m - t.m); //don't forget 1.0
  }
  void addLine(Line l) {
    while(st.size() >= 2 && badLine(st[st.size() - 2], st[st.size() - 1], l)) st.pop_back();
    st.push_back(l);
  }
  CHType query(CHType x) {
    if(st.size() == 0) return CHINF;
    int lo = 0, hi = st.size() - 1;
    while(lo < hi) {
      int md = (lo + hi) >> 1;
      if(st[md].getVal(x) <= st[md + 1].getVal(x)) hi = md;
      else lo = md + 1;
    }
    return st[lo].getVal(x);
  }
};

const int N = 1000010;

ConvexHullTrick s;
ll a[N],b[N],pd[N];
ll n;

int main()
{
  //ios::sync_with_stdio(0);
    scanf("%lld",&n);
    for(int i=0;i<n;++i) scanf("%lld",a+i);
    for(int i=0;i<n;++i) scanf("%lld",b+i);
    pd[0] = 0;
    s.addLine(Line(b[0],pd[0]));
    for(int i=1;i<n;++i)
    {
        pd[i] = s.query(a[i]);
        s.addLine(Line(b[i],pd[i]));
    }
    printf("%lld\n",pd[n-1]);
  return 0;
}