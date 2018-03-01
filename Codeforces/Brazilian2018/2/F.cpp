#include <bits/stdc++.h>

#define LINF 10000000000000.0

using namespace std;

struct Point {
  double x, y;
  Point(){};
  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }
  void read() {
    scanf("%lf %lf", &x, &y);
  }
  bool operator < (Point o) const {
    if(x != o.x) return x < o.x;
    return y < o.y;
  }
  void print() {
    printf("%.lf %.lf\n", x, y);
  }
};

const int N = 200010;

int n;
Point p[N];

double getD(Point a, Point b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) p[i].read();
  sort(p, p + n);
  Point sa, sb;
  multiset< pair< double, double > > s;
  int lst = 0;
  double bst = HUGE_VAL;
  for(int i = 0; i < n; ++i) {
    while(lst < i && p[i].x - p[lst].x > bst) {
      s.erase(s.find(make_pair(p[lst].y, p[lst].x)));
      lst++;
    }
    multiset< pair< double, double > > :: iterator st = s.lower_bound(make_pair(p[i].y - bst, -HUGE_VAL));
    multiset< pair< double, double > > :: iterator ed = s.upper_bound(make_pair(p[i].y + bst, +HUGE_VAL));
    for(multiset< pair<double, double> > :: iterator it = st; it != ed; it++) {
      double sqD = getD(p[i], Point(it->second, it->first));
      if(sqD < bst) {
        bst = sqD;
        sa = p[i];
        sb = Point(it->second, it->first);
      }
    }
    s.insert(make_pair(p[i].y, p[i].x));
  }
  sa.print();
  sb.print();
  return 0;
}