#include <bits/stdc++.h>
 
 
int wrongSolver(std::vector <unsigned int> a) {
  int n = a.size();
  std::vector<unsigned int> prefSum(n), sufSum(n);
  prefSum[0] = a[0];
  for (int i = 1; i < n; i++) {
    prefSum[i] = prefSum[i - 1] + a[i];
  }
  sufSum[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    sufSum[i] = sufSum[i + 1] + a[i];
  }
  unsigned int mn = prefSum[0] + sufSum[0];
  int where = 1;
  for (int i = 1; i < n; i++) {
    unsigned int val = prefSum[i] + sufSum[i];
    if (val < mn) {
      mn = val;
      where = i + 1;
    }
  }
  return where;
}

int correctSolver(std::vector <unsigned int> a) {
  int n = a.size();
  std::vector<long long> prefSum(n), sufSum(n);
  prefSum[0] = a[0];
  for (int i = 1; i < n; i++) {
    prefSum[i] = prefSum[i - 1] + a[i];
  }
  sufSum[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    sufSum[i] = sufSum[i + 1] + a[i];
  }
  long long mn = prefSum[0] + sufSum[0];
  int where = 1;
  for (int i = 1; i < n; i++) {
    long long val = prefSum[i] + sufSum[i];
    if (val < mn) {
      mn = val;
      where = i + 1;
    }
  }
  return where;
}

using namespace std;
 
typedef long long ll;

bool go(int n, ll val) {
  vector< unsigned int > a;
  ll sum = 0;
  for(int i = 0; i + 1 < n; ++i) {
    a.push_back(val);
    sum += val;
    if(sum >= (1LL << 32)) sum -= (1LL << 32);
  }
  a.push_back(((1LL << 32) - sum) >> 1);
  int mx = 0;
  for(int i = 0; i < a.size(); ++i) mx = max(mx, (int)a[i]);
  if(wrongSolver(a) != correctSolver(a) && mx <= 100000) return true;
  return false;
}
 
inline void main2() {
  int n; scanf("%d", &n);
  ll val = 0;
  for(int i = 0; i <= 100000; ++i) {
    ll foo = (ll)(n - 1) * i;
    foo %= (1LL << 32);
    ll need = (((1LL << 32) - foo) >> 1);
    if(need > 100000) continue;
    if(go(n, i)) {
      val = i;
      break;
    }
  }
  ll sum = 0;
  for(int i = 0; i < n - 1; ++i) {
    if(i) printf(" ");
    printf("%d", val);
    sum += val;
    sum %= (1LL << 32);
  }
  printf(" %lld\n", ((1LL << 32) - sum) >> 1);
  
}
 
int main() {
  srand(time(NULL));
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
} 