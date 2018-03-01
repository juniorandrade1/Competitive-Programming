#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 750 + 10;
const ll MOD = (ll)1e9 + 7LL;

inline int addMod(ll a, ll b, ll md = MOD) {
  a += b;
  if(a >= md) a -= md;
  return a;
}

inline int mulMod(ll a, ll b, ll md = MOD) {
  return ((a % md) * (b % md)) % md;
}

inline int powMod(ll b, ll p, ll md = MOD) {
  int ans = 1;
  while(p) {
    if(p & 1) ans = mulMod(ans, b);
    b = mulMod(b, b);
    p >>= 1;
  }
  return (int)ans;
}

int fat[N], invFat[N];

inline void preprocess() {
  fat[0] = invFat[0] = 1;
  for(int i = 1; i < N; ++i) {
    fat[i] = mulMod(fat[i - 1], i);
    invFat[i] = powMod(fat[i], MOD - 2);
  }
}

inline int choose(int n, int k) {
  if(n < k) swap(n, k);
  return mulMod(fat[n], mulMod(invFat[k], invFat[n - k]));
}

int solve(vector<int> &numbers) {
  int first_element = numbers[0];
  vector<int> dp(numbers[0], 0);
  dp[first_element - 1] = 1;
  for (int t = 1; t < (int)numbers.size(); t += 1) {
    int number = numbers[t];
    int num_elements = (int)dp.size();
    vector<int> next(num_elements + number, 0);
    for (int bad_adjacent = 0; bad_adjacent < num_elements; bad_adjacent += 1) {
      if (dp[bad_adjacent] == 0) continue;
      for (int num_splits = 1; num_splits <= min(number, 1 + num_elements); num_splits += 1) {
        for (int chosen_bad = 0; chosen_bad <= min(num_splits, bad_adjacent); chosen_bad += 1) {
            int good_adjacent = num_elements + 1 - bad_adjacent;
            int chosen_good = num_splits - chosen_bad;
            if (chosen_good < 0) continue;
            if (chosen_good > good_adjacent) continue;
            int new_bad_adjacent = bad_adjacent - chosen_bad + (number - num_splits);
            int num_ways = mulMod(choose(number - 1, num_splits - 1), mulMod(choose(good_adjacent, chosen_good), choose(bad_adjacent, chosen_bad)));
            num_ways = mulMod(num_ways, dp[bad_adjacent]);  
            next[new_bad_adjacent] = addMod(next[new_bad_adjacent], num_ways);        
        }
      }
    }
    dp = next;
  }
  return dp[0];
}


int main() {
  preprocess();
  int n; scanf("%d", &n);
  map< int, int > cnt;
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    for(int i = 2;; ++i) {
      int is = (i * i);
      if(is > x) break;
      while(x % is == 0) x /= is;
    }
    cnt[x]++;
  }
  vector< int > v;
  for(auto it : cnt) v.emplace_back(it.second);
  printf("%d\n", solve(v));
  return 0;
}
