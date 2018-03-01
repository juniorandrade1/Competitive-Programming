#include <bits/stdc++.h>

using namespace std;

#define pi acos(-1.0)

typedef long long ll;

const int N = 101;

int n;
double w, s;
double h[N];

inline double go(int idx) {
  double bl = pi, br = 0;
  double sl = 0, sr = 0;
  for(int i = idx - 1; i >= 0; --i) {
    sl -= s;
    sl -= w;
    bl = min(bl, atan2(h[i], sl));
  }
  for(int i = idx + 1; i < n; ++i) {
    sr += s;
    sr += w;
    br = max(br, atan2(h[i], sr));
  }
  double p = (bl - br) / pi;
  return 16 * 60 * p;
}

inline void main2() {
  scanf("%d %lf %lf", &n, &w, &s);
  int idx = 0;
  for(int i = 0; i < n; ++i) {
    scanf("%lf", h + i);
    if(h[i] == 0) idx = i;
  }
  double ans = go(idx);
  printf("%.10lf\n", ans);
}

int main() {
  //printf("(-1, 0) = %.10lf\n", atan2(0, -1));
  //printf("(1, 0) = %.10lf\n", atan2(0, 1));
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}