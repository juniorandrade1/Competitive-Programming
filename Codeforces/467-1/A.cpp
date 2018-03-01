#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline long double go(ll k, ll d, long double totTime) {
  long double ans = 0;
  ll qtd = (k + d - 1) / d;
  ll timeNeed = qtd * d;
  ll qtdTot = totTime / timeNeed;
  ll cmpTime = qtdTot * timeNeed;
  long double timeStoveOn = k * qtdTot;
  long double timeStoveOff = cmpTime - timeStoveOn;
  long double rstTime = totTime - cmpTime;
  if(rstTime <= k) {
    timeStoveOn += rstTime;
  }
  else {
    timeStoveOn += k;
    rstTime -= k;
    timeStoveOff += rstTime;
  }
  return timeStoveOn * 2.0 + timeStoveOff;
}

int main() {
  ll k, d, t; scanf("%lld %lld %lld", &k, &d, &t);
  double lo = 0, hi = 2 * 1e18 + 1;
  for(int i = 0; i < 500; ++i) {
    double md = (lo + hi) * 0.5;
    if(go(k, d, md) <= 2.0 * t) lo = md;
    else hi = md;
  }
  printf("%.20lf\n", lo);
  return 0;
}