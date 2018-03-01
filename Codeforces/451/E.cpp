#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int v[N];
vector< int > allSQ;

int main() {
  for(int i = 0; ; ++i) {
    allSQ.push_back(i * i);
    if(i * i > (int)1e9) break;
  }
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", v + i);
  vector< int > sq, nsq;
  for(int i = 0; i < n; ++i) {
    int id = lower_bound(allSQ.begin(), allSQ.end(), v[i]) - allSQ.begin();
    if(allSQ[id] == v[i]) {
      sq.push_back(v[i] == 0 ? 2 : 1);
    }
    else {
      int xa = abs(allSQ[id] - v[i]);
      int xb = abs(v[i] - allSQ[id - 1]);
      nsq.push_back(min(xa, xb));
    }
  }
  sort(sq.rbegin(), sq.rend());
  sort(nsq.rbegin(), nsq.rend());
  long long ans = 0;
  for(int i = n / 2; i < sq.size(); ++i) ans += sq[i];
  for(int i = n / 2; i < nsq.size(); ++i) ans += nsq[i];
  printf("%lld\n", ans);
  return 0; 
}