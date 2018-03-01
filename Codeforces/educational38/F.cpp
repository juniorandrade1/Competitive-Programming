#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

typedef long long ll;

const int N = 5000;

char s[N];
int n;
int p = 0;
int dp[N][1 << 12];

int func(int pos, int mask) {
  if(pos == n) return (1 << p) - 1 == mask ? 0 : INF;
  if(dp[pos][mask] != -1) return dp[pos][mask];
  int ret = func(pos + 1, mask);
  if(ret != INF) ret = s[pos];
  for(int i = 0; i < p; ++i) {
    if(pos + (1 << i) > n) break;
    if((mask >> i) & 1) continue;
    ret = min(ret, func(pos + (1 << i), mask ^ (1 << i)));
  }
  return dp[pos][mask] = ret;
}

void back(int pos, int mask) {
  if(pos == n) return;
  if(func(pos + 1, mask) != INF) {
    if(func(pos, mask) == s[pos]) {
      printf("%c", s[pos]);
      back(pos + 1, mask);
      return;
    }
  }
  for(int i = 0; i < p; ++i) {
    if((mask >> i) & 1) continue;
    if(pos + (1 << i) > n) break;
    if(func(pos + (1 << i), mask ^ (1 << i)) == func(pos, mask)) {
      back(pos + (1 << i), mask ^ (1 << i));
      return;
    }
  }
}

int main() {
  scanf(" %s", s);
  n = strlen(s);
  while((1 << p) <= n) p++;
  p--;
  memset(dp, -1, sizeof dp);
  int sol = func(0, 0);
  back(0, 0);
  return 0;
}