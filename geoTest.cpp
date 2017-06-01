#include <bits/stdc++.h>

using namespace std;

#define pi acos(-1.0)
#define eps 1e-8

double degToRad(double x) {
  return (x * pi) / 180.;
}

struct Point {
  double x, y;
  Point(){};
  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }
  void read(){ scanf("%lf %lf", &x, &y); }
  void print() { printf("(%.10lf %.10lf)\n", x, y); }
  double distance(Point other) { return hypot(x - other.x, y - other.y); }
  Point operator + (Point other) { return Point(x + other.x, y + other.y); }
  Point operator - (Point other) { return Point(x - other.x, y - other.y); }
  Point operator * (double t) { return Point(x * t, y * t); }
  Point operator / (double t) { return Point(x / t, y / t); }
  double operator * (Point q) {return x * q.x + y * q.y;} //a*b = |a||b|cos(ang) //Positivo se o vetor B está do mesmo lado do vetor perpendicular a A
  double operator % (Point q) {return x * q.y - y * q.x;} //a%b = |a||b|sin(ang) //Angle of vectors
  double polar() { return ((y > -eps) ? atan2(y,x) : 2*pi + atan2(y,x)); }
  Point rotate(double t) { return Point(x * cos(t) - y * sin(t), x * sin(t) + y * cos(t)); }
  Point rotateAroundPoint(Point p, double t) { return (*this - p).rotate(t) + p; }
  bool operator < (Point other) const {
    if(other.x != x) return x < other.x;
    else return y < other.y;
  }
};

struct Circle {
  Point c;
  double r;
  Circle(Point _c, double _r) {
    c = _c;
    r = _r;
  }
  bool contains(Point point) { return c.distance(point) < r + eps; }
  bool strictContains(Point point) { return c.distance(point) < r - eps; }
};

struct Line {
  double a, b, c;
  Line(){};
  Line(double _a, double _b, double _c) {
    a = _a;
    b = _b;
    c = _c;
  }
  Line(Point s, Point t) {
    a = t.y - s.y;
    b = s.x - t.x;
    c = -a * s.x - b * s.y;
  }
  Line(Point p, double ang) {
    a = sin(ang);
    b = -cos(ang);
    c = -p.x * a - p.y * b;
  }
  bool parallel(Line other) { return fabs(a * other.b - b * other.a) < eps; }
  bool intersect(Line other, Point &sol) {
    if(this->parallel(other)) return false;
    else {
      double determinant = this->b * other.a - this->a * other.b;
      double x = (this->c * other.b - this->b * other.c) / determinant;
      double y = (this->a * other.c - this->c * other.a) / determinant;
      sol = Point(x, y);
      return true;
    }
  }
  Line perpendicular(Point point) {
    return Line(-b, a, b * point.x - a * point.y);
  }
  double distance(Point r) {
    Point p, q;
    if(fabs(b) < eps) {
      p = Point(-c / a, 0);
      q = Point((-c - b) / a, 1);
    }
    else {
      p = Point(0, -c / b);
      q = Point(1, (-c - a) / b);
    }
    Point A = r - q, B = r - p, C = q - p;
    double a = A * A, b = B * B, c = C * C;
    return fabs(A % B) / sqrt(c);
  }
  bool contains(Point point) {
    return abs(value(point)) < eps;
  }
  double value(Point point) {
    return a * point.x + b * point.y + c;
  }

  vector< Point > circleIntersection(Circle circle) {
    double d = distance(circle.c);
    vector< Point > foo;
    if (d > circle.r + eps) return foo;
    Point intersection;
    intersect(perpendicular(circle.c), intersection);

    if (fabs(d - circle.r) < eps) {
      foo.push_back(intersection);
      return foo;
    }
    double shift = sqrt(circle.r * circle.r - d * d);
    foo.push_back(Point(intersection.x + shift * b, intersection.y - shift * a));
    foo.push_back(Point(intersection.x - shift * b, intersection.y + shift * a));
    return foo;
  }
};


class GeometryUtils{
public:
  static double missileTrajectoryLength(double v, double angle, double g) {
    return (v * v * sin(2 * angle)) / g;
  }
  static double sphereVolume(double radius) {
    return 4 * pi * radius * radius * radius / 3;
  }
  static vector< Point > circleToCircleIntersection(Circle a, Circle b) {
    double distance = a.c.distance(b.c);
    vector< Point > foo;
    if (distance > a.r + b.r + eps || fabs(a.r - b.r) > distance + eps) return foo;
    double p = (a.r + b.r + distance) / 2;
    double height = 2 * sqrt(p * (p - a.r) * (p - b.r) * (p - distance)) / distance;
    double l1 = sqrt(a.r * a.r - height * height);
    double l2 = sqrt(b.r * b.r - height * height);
    if (a.r * a.r + distance * distance < b.r * b.r) l1 = -l1;
    if (a.r * a.r > distance * distance + b.r * b.r) l2 = -l2;
    Point middle = Point((a.c.x * l2 + b.c.x * l1) / (l1 + l2),
        (a.c.y * l2 + b.c.y * l1) / (l1 + l2));
    Line line = Line(a.c, b.c).perpendicular(middle);
    return line.circleIntersection(a);
  }
  static vector< Point > ConvexHull(vector< Point > &polygon) {
    sort(polygon.begin(), polygon.end());
    vector< Point > down, up;
    for(int i = 0; i < polygon.size(); ++i) {
      while(up.size() >= 2 && (up[up.size() - 1] - up[up.size() - 2]) % (polygon[i] - up[up.size() - 1]) > -eps) up.pop_back();
      while(down.size() >= 2 && (down[down.size() - 1] - down[down.size() - 2]) % (polygon[i] - down[down.size() - 1]) < eps) down.pop_back();
      up.push_back(polygon[i]);
      down.push_back(polygon[i]);
    }
    for(int i = (int)down.size() - 2; i > 0; --i) up.push_back(down[i]);
    return up;
  }

  static bool PointInPolygon(vector< Point > &p, Point q) {
    for(int i = 0; i < p.size(); ++i) {
      int j = (i + 1) % p.size();
      if(fabs((q - p[i]) % (p[j] - p[i])) > eps) continue;
      if((q - p[i]) * (p[i] - p[j]) > eps) continue;
      if((q - p[j]) * (p[j] - p[i]) > eps) continue;
      return true;
    }
    bool ok = 0;
    for(int i = 0; i < p.size(); ++i) {
      Point a = p[i], b = p[(i + 1) % p.size()];
      if(fabs(a.x - b.x) < eps) continue;
      if(a.x > b.x) swap(a, b);
      if(q.x < a.x - eps) continue;
      if(q.x > b.x - eps) continue;
      if((q - a) % (b - a) > 0) ok ^= 1;
    }
    return ok;
  }
  static bool intersectLineToSegment(Point p, Point q, Point a, Point b, Point &sol) {
    //Line [p, q] to segment [a, b]
    double na = (a - p) % (q - p), nb = (b - p) % (q - p);
    if(na * nb > eps) return false;
    if(fabs(na - nb) < eps) return false;
    sol = (a + (b - a) * (na / (na - nb)));
    return true;
  }
};

int main() {
  return 0;
}