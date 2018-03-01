#include <bits/stdc++.h>

using namespace std;

#define pi acos(-1.0)

typedef long long ll;

const int N = 301;
const int P = 10;

int va, vb, na, nb;
vector< int > ga[N], gb[N];
int sa[N], sb[N];
double pdPlayA[P][12 * 3 + 1], pdPlayB[P][12 * 3 + 1];

void backA(int o, int id, int sum) {
  if(id == ga[o].size()) {
    if(sum >= 0) pdPlayA[o][sum]++;
    return;
  }
  for(int i = 1; i <= ga[o][id]; ++i) {
    backA(o, id + 1, i + sum);
  }
}

void backB(int o, int id, int sum) {
  if(id == gb[o].size()) {
    if(sum >= 0) pdPlayB[o][sum]++;
    return;
  }
  for(int i = 1; i <= gb[o][id]; ++i) {
    backB(o, id + 1, i + sum);
  }
}

inline void preprocess() {
  memset(pdPlayA, 0, sizeof pdPlayA);
  for(int i = 0; i < na; ++i) {
    double all = 1;
    sa[i] = 0;
    for(int j = 0; j < ga[i].size(); ++j) {
      all *= ga[i][j];
      sa[i] += ga[i][j];
    }
    backA(i, 0, 0);
    for(int j = 0; j <= sa[i]; ++j) pdPlayA[i][j] /= all;
  }
  memset(pdPlayB, 0, sizeof pdPlayB);
  for(int i = 0; i < nb; ++i) {
    double all = 1;
    sb[i] = 0;
    for(int j = 0; j < gb[i].size(); ++j) {
      all *= gb[i][j];
      sb[i] += gb[i][j];
    }
    backB(i, 0, 0);
    for(int j = 0; j <= sb[i]; ++j) pdPlayB[i][j] /= all;
  }
}

double pd[N][N][2];
short memo[N][N][2];

double solve(int qa, int qb, int pl) {
  if(qa <= 0) return 0.0;
  if(qb <= 0) return 1.0;
  if(memo[qa][qb][pl]) return pd[qa][qb][pl];
  double ret;
  if(pl == 0) {
    ret = 0;
    for(int i = 0; i < na; ++i) {
      double at = 0;
      for(int j = 1; j <= sa[i]; ++j) {
        at += solve(qa, qb - j, pl ^ 1) * pdPlayA[i][j];
      }
      ret = max(ret, at);
    }
  }
  else {
    ret = 1.0;
    for(int i = 0; i < nb; ++i) {
      double at = 0;
      for(int j = 1; j <= sb[i]; ++j) {
        at += solve(qa - j, qb, pl ^ 1) * pdPlayB[i][j];
      }
      ret = min(ret, at);
    }
  }
  memo[qa][qb][pl] = 1;
  return pd[qa][qb][pl] = ret;
}

inline void main2() {
  scanf("%d %d %d %d", &va, &vb, &na, &nb);
  for(int i = 0; i < na; ++i) {
    ga[i].clear();
    int d; scanf("%d", &d);
    while(d--) {
      int x; scanf("%d", &x);
      ga[i].push_back(x);
    }
  }
  for(int i = 0; i < nb; ++i) {
    gb[i].clear();
    int d; scanf("%d", &d);
    while(d--) {
      int x; scanf("%d", &x);
      gb[i].push_back(x);
    }
  }
  preprocess();
  memset(memo, 0, sizeof memo);
  printf("%.10lf\n", solve(va, vb, 0));
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}