#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

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
#define EPS 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
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

    void read() {
      scanf("%lf %lf", &x, &y);
    }
    double dis(Point p) {
      return hypot(x - p.x, y - p.y);
    }

    Point operator - (Point p) {
      return Point(p.x - x, p.y - y);
    }
    Point operator + (Point p) {
      return Point(p.x + x, p.y + y);
    }
    Point operator / (double d) {
      return Point(x / d, y / d);
    }
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

struct seg {
  Point p1, p2;
  seg(Point a, Point b) {
    p1 = a;
    p2 = b;
  }
  bool areSegIntersect(seg oth) {
    Line l1, l2;
    PointsToLine(p1, p2, &l1);
    PointsToLine(oth.p1, oth.p2, &l2);
    Point it;
    if(areIntersect(l1, l2, &it) == false) return false;
    double d11 = it.dis(p1) + it.dis(p2);
    double d12 = p1.dis(p2);
    double d21 = it.dis(oth.p1) + it.dis(oth.p2);
    double d22 = oth.p1.dis(oth.p2);
    return fabs(d11 - d12) < EPS && fabs(d21 - d22) < EPS;
    
  }
};


const int N = 500;

Point poly[N];
Point p;

int main() {
  int n; scanf("%d", &n);
  p.read();
  for(int i = 0; i < n; ++i) poly[i].read();

  double per = 0;
  for(int i = 0; i < n; ++i) per += poly[i].dis(poly[(i + 1) % n]);

  double oth = 0;
  for(int i = 0; i < n; ++i) {
    int qtdInt1 = 0, qtdInt2 = 0, qtdInt3 = 0;

    seg s1 = seg(p, poly[(i + 1) % n]);
    seg s2 = seg(poly[i], p);
    Point foo = poly[i] - poly[(i + 1) % n];
    Point foo2 = poly[i] + (foo / 2);
    seg s3 = seg(p, foo2);

    for(int j = 0; j < n; ++j) {
      seg s4 = seg(poly[j], poly[(j + 1) % n]);
      qtdInt1 += s1.areSegIntersect(s4);
      qtdInt2 += s2.areSegIntersect(s4);
      qtdInt3 += s3.areSegIntersect(s4);
    }
    Line l1, l2;
    PointsToLine(p, poly[i], &l1);
    PointsToLine(poly[i], poly[(i + 1) % n], &l2);
    if(qtdInt3 <= 1 && !areParallel(l1, l2)) oth += poly[i].dis(poly[(i + 1) % n]);

  }

  printf("%.5lf\n", (oth * 100.) / per);
  return 0;
}