#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Fraction {
  ll num, den;
  Fraction(){};
  Fraction(ll _num, ll _den) {
    ll g = abs(__gcd(_num, _den));
    num = _num / g;
    den = _den / g;
  }
  bool operator < (Fraction other) const {
    return num * other.den < other.num * den;
  }
  bool operator == (Fraction other) const {
    return num * other.den == other.num * den;
  }
};

struct Point {
  ll x, y, t;
  Point(){};
  void read() {
    scanf("%lld %lld %lld", &x, &y, &t);
  }
};

const int N = 123456;

int n;
map<Fraction, vector< Point > > all;
vector< pair<int, int> > solution;

bool distCmp(Point a, Point b) {
  ll ad = (a.x * a.x) + (a.y * a.y);
  ll bd = (b.x * b.x) + (b.y * b.y);
  return ad < bd;
}

int main() {
  int test = 1;
  while(scanf("%d", &n) != EOF && n > 0) {
    all.clear();
    solution.clear();
    for(int i = 0; i < n; ++i) {
      Point p; p.read();
      all[Fraction(p.x, p.y)].push_back(p);
    }
    for(map<Fraction, vector< Point > >::iterator it = all.begin(); it != all.end(); it++) {
      int greater = -1;
      sort(it->second.begin(), it->second.end(), distCmp);
      for(int i = 0; i < it->second.size(); ++i) {
        if(it->second[i].t <= greater) {
          solution.push_back(make_pair(it->second[i].x, it->second[i].y));
        }
        greater = max(greater, it->second[i].t);
      }
    }
    sort(solution.begin(), solution.end());
    printf("Data set %d:\n", test++);
    if(solution.size() == 0) puts("All the lights are visible.");
    else {
      puts("Some lights are not visible:");
      for(int i = 0; i < solution.size(); ++i) {
        printf("x = %d, y = %d", solution[i].first, solution[i].second);
        if(i + 1 == solution.size()) printf(".\n");
        else printf(";\n");
      }
    }
  }
  return 0;
}