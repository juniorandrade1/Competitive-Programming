#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back  

struct Point {
  ll x, y;
  Point(){};
  Point(ll _x, ll _y) {
    x = _x;
    y = _y;
  }
  ll operator % (Point other) { return x * other.y - other.x * y; }
  ll operator * (Point other) { return x * other.x + y * other.y; }
  Point operator - (Point other) { return Point(x - other.x, y - other.y); }
  Point operator + (Point other) { return Point(x + other.x, y + other.y); }
};

const int N = 1010;

Point p[N];

int main() {
  int n; scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int y; scanf("%d", &y);
    p[i] = Point(i + 1, y);
  }
  for(int s = 0; s < 2; ++s) {
    for(int i = 0; i < n; ++i) {
      if(s == i) continue;
      vector< Point > notLine;
      for(int j = 0; j < n; ++j) {
        if((p[i] - p[s]) % (p[j] - p[s]) == 0) continue;
        notLine.pb(p[j]);
      }
      if(notLine.size() == 0) continue;
      if(notLine.size() == 1) {
        puts("Yes");
        exit(0);
      }
      bool ok = true;
      for(int j = 2; j < notLine.size() && ok; ++j) {
        if((notLine[1] - notLine[0]) % (notLine[j] - notLine[0]) != 0) ok = false;
      }
      ok &= ((notLine[1] - notLine[0]) % (p[i] - p[s])) == 0;
      if(ok) {
        puts("Yes");
        exit(0);
      }
    }
  }
  puts("No");
  return 0;
}