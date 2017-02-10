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
#define PI 2*acos(0)
#define EPS 1e-3

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
//////////////////////

struct Point_i
{
    int x; int y;
    Point_i(int _x, int _y){ x = _x; y = _y;}
};

struct Point
{
    double x,y;
    Point(){}
    Point(double _x, double _y){ x = _x; y = _y; }

    bool operator < (const Point other)
    {
        if(fabs(x - other.x) > EPS) return x < other.x;
        return y < other.y;
    }
    bool operator == (const Point other){ 
    return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); }

    struct Point* operator = (const Point *other){ 
    x = other->x; y = other->y; return this; }
};

bool areSame(Point_i p1, Point_i p2){
   return p1.x == p2.x && p1.y == p2.y; }
   
bool areSame(Point p1, Point p2){ 
  return fabs(p1.x - p2.x) < EPS && fabs(p1.y - p2.y) < EPS; }

double dist(Point p1, Point p2){ 
  return hypot(p1.x - p2.x, p1.y - p2.y); 
}

Point rotate(Point p, double theta)
{
    double rad = DEG_to_RAD(theta);
    return Point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}

// ax + by + c = 0
struct Line
{
    double a,b,c;
};

void PointsToLine(Point p1, Point p2, Line *l)
{
    if(p1.x == p2.x){
        l->a = 1.0; l->b = 0.0; l->c = -p1.x;
    } else{
        l->a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l->b = 1.0;
        l->c = -(double)(l->a * p1.x) - (l->b * p1.y);
    }
}

bool areParallel(Line l1, Line l2)
{
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(Line l1, Line l2)
{
    return areParallel(l1,l2) && (fabs(l1.c - l2.c) < EPS);
}

bool areIntersect(Line l1, Line l2,Point *p)
{
    if(areSame(l1,l2))   return false;
    if(areParallel(l1,l2)) return false;

    p->x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if(fabs(l1.b) > EPS){
        p->y = -(l1.a * p->x + l1.c) / l1.b;
    } else{
        p->y = -(l2.a * p->x + l2.c) / l2.b;
    }

    return true;
}

// returs the distance from p to the Line defined by
// two Points A and B ( A and B must bedifferent)
// the closest Point is stored in the 4th parameter (by reference)
double distToLine(Point p, Point A,Point B, Point *c)
{
    double scale = (double)
    ((p.x - A.x) * (B.x - A.x) + (p.y - A.y) * (B.y - A.y)) /
    ((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
    
    c->x = A.x + scale * (B.x - A.x);
    c->y = A.y + scale * (B.y - A.y);
    return dist(p, *c);
}

double distToLineSegment(Point p, Point A,Point B, Point *c)
{
    if( (B.x - A.x) * (p.x - A.x) + (B.y - A.y) * (p.y - A.y) < EPS)
    {
        c->x =  A.x; c->y = A.y;
        return dist(p,A);
    }
    if( (A.x - B.x) * (p.x - B.x) + (A.y - B.y) * (p.y - B.y) < EPS){
        c->x = B.x; c->y = B.y;
        return dist(p,B);
    }
    return distToLine(p,A,B,c);
}

// The cross product of pq,pr
double cross(Point p, Point q, Point r){ 
  return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x); }

// returns true if Point r is on the same Line as the Line pq
bool collinear(Point p, Point q,Point r){ 
  return fabs(cross(p,q,r)) < EPS; }

bool ccw(Point p, Point q, Point r){ return cross(p,q,r) > 0; }

//////////////////////////////////// Vetor

struct vec
{
    double x, y;
    vec(double _x, double _y){ x = _x, y = _y;}
};

vec toVector(Point p1, Point p2){ return vec(p2.x - p1.x, p2.y - p1.y);}

vec scaleVector(vec v, double s){ return vec(v.x * s, v.y * s); }

Point translate(Point p, vec v){ return Point(p.x + v.x, p.y + v.y); }

////////////////////////////////// Fim_Vetor

bool Point_sort_x(Point a, Point b){
    if( abs(a.x - b.x) < EPS)  return a.y < b.y;
    return (a.x < b.x);
}

struct circle
{
  Point p;
  double r;
  circle(){};
  circle( Point a, double b )
  {
    p = a;
    r = b;
  }
  double passa( circle foo )
  {
    return dist(p,foo.p)-(r+foo.r);
  }
  void read()
  {
    scanf("%lf %lf %lf",&p.x,&p.y,&r);
  }
};


const int N = 303;

vector< circle > v;
circle ship;
int n;
vi g[N];
vi S;
int vis[N];
int yes;

void dfs( int x, int ult = -1 )
{
  S.pb(x);
  vis[x] = 1;
  for(int i=0;i<g[x].size();++i)
  {
    int y = g[x][i];
    if( y == ult ) continue;
    if( vis[y] )
    {
      if( S.size() <= 1 )continue;
      //debug("-> %d %d\n",y,x);
      int pos, neg, zero;
      pos = neg = zero = 0;

      double c = cross(v[y].p,v[x].p,ship.p);
      pos = c>0;
      neg = c<0;
      zero |= fabs(c)<EPS;


      int id = S.size()-1;
      do
      {
        //debug("-> %d %d\n",S[id],S[id-1]);
        c = cross(v[S[id]].p,v[S[id-1]].p,ship.p);
        pos = c>0;
        neg = c<0;
        zero |= fabs(c)<EPS;
        id--;
      }
      while( S[id-1] != y && id > 1);
      //debug("-> %d %d\n\n",S[id],y);

      c = cross(v[S[id]].p,v[y].p,ship.p);
      pos = c>0;
      neg = c<0;

      if( pos != neg || zero ) yes = 0;
      
    }
    else dfs(y,x);
  }
  S.pop_back();
}


int main()
{
  //ios::sync_with_stdio(0);
  //freopen("out.in","r",stdin);
  //freopen("out.out","w",stdout);
  scanf("%d",&n);
  for(int i=0;i<n;++i)
  {
    double a,b,c; scanf("%lf %lf %lf",&a,&b,&c);
    v.pb(circle(Point(a,b),c));
  }
  ship.read();
  for(int i=0;i<n;++i)
  {
    for(int j=i+1;j<n;++j)
    {
      double foo = v[i].passa(v[j]);
      if( EPS <= ship.r*2.-foo ){
        g[i].pb(j), g[j].pb(i);
        debug("ar = %d %d\n",i + 1,j + 1);
      }
    }
  }
  yes = 1;
  for(int i=0;i<n && yes;++i)
  {
    if( !vis[i] ){
      dfs(i);
    }
  }
  printf("%s\n",(yes)?"YES":"NO");


  return 0;
}