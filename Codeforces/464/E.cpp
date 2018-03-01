#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

double v[N];
double s[N];

int main() {
  int opt = 0;
  int q; scanf("%d", &q);
  double ans = 0;
  int n = 1;
  while(q--) {
    int op; scanf("%d", &op);
    if(op == 1) {
      double x; scanf("%lf", &x);
      v[n] = x;
      s[n] = s[n - 1] + x;
      int lo = 0, hi = n - 1;
      while(lo < hi) {
        int md = (lo + hi) >> 1;
        double a0 = v[n] - ((s[md] + v[n]) / (double)(md + 1));
        double a1 = v[n] - (((s[md + 1] + v[n]) / (double)(md + 2)));
        if(a0 < a1) lo = md + 1;
        else hi = md;
      }
      ans = max(ans, v[n] - ((s[lo] + v[n]) / (double)(lo + 1)));

      n++;
    }
    else printf("%.10lf\n", ans);
  }

  return 0;
}