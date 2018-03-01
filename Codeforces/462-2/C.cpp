#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2020;

int n;
int v[N];
int c[N][2];
int pd[N][N][2];

int getQ(int l, int r, int id) {
  if(r < l) return 0;
  return c[r][id] - c[l - 1][id];
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", v + i);
    v[i]--;
    c[i][0] = c[i - 1][0] + (v[i] == 0);
    c[i][1] = c[i - 1][1] + (v[i] == 1);
  }
  int ans = max(c[n][0], c[n][1]);
  for(int i = 0; i <= n; ++i) {
    ans = max(ans, getQ(1, i, 0) + getQ(i + 1, n, 1));
  }
  for(int len = 0; len < n; ++len) {
    for(int l = 1; l + len <= n; ++l) {
      int r = l + len;
      if(len == 0) {
        pd[l][r][0] = (v[l] == 0);
        pd[l][r][1] = (v[l] == 1);
      }
      else {
        pd[l][r][0] = pd[l][r - 1][0];
        pd[l][r][1] = pd[l][r - 1][1];
        if(v[r] == 0) {
          pd[l][r][0] = max(pd[l][r][0], pd[l][r - 1][0] + 1);
          pd[l][r][0] = max(pd[l][r][0], pd[l][r - 1][1] + 1);
        }
        else {
          pd[l][r][1] = max(pd[l][r][1], pd[l][r - 1][1] + 1);
        }
      }
    }
  }
  for(int i = 1; i <= n; ++i) {
    for(int j = i; j <= n; ++j) {
      ans = max(ans, getQ(1, i - 1, 0) + max(pd[i][j][0], pd[i][j][1]) + getQ(j + 1, n, 1));
    }
  }
  printf("%d\n", ans);
  return 0;
}