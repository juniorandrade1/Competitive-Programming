#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ll, ll > ii;
typedef vector< ll > vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s))
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 401;

ll pdMin[N][N], pdMax[N][N];
bool memo[N][N];
int n;
char op[N];
ll v[N];

void go(int l, int r) {
  if(l == r) {
    pdMax[l][r] = pdMin[l][r] = v[l];
    memo[l][r] = 1;
    return;
  }
  if(memo[l][r]) return;
  pdMax[l][r] = -LINF; pdMin[l][r] = LINF; memo[l][r] = 1;
  for(int i = l; i < r; ++i) {
    go(l, i); go(i + 1, r);
    if(op[i] == '?') {
      pdMax[l][r] = max(pdMax[l][r], pdMax[l][i] + pdMax[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMin[l][i] + pdMax[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMax[l][i] + pdMin[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMin[l][i] + pdMin[i + 1][r]);

      pdMin[l][r] = min(pdMin[l][r], pdMax[l][i] + pdMax[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMin[l][i] + pdMax[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMax[l][i] + pdMin[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMin[l][i] + pdMin[i + 1][r]);

      pdMax[l][r] = max(pdMax[l][r], pdMax[l][i] - pdMax[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMin[l][i] - pdMax[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMax[l][i] - pdMin[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMin[l][i] - pdMin[i + 1][r]);

      pdMin[l][r] = min(pdMin[l][r], pdMax[l][i] - pdMax[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMin[l][i] - pdMax[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMax[l][i] - pdMin[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMin[l][i] - pdMin[i + 1][r]);

      pdMax[l][r] = max(pdMax[l][r], pdMax[l][i] * pdMax[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMin[l][i] * pdMax[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMax[l][i] * pdMin[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMin[l][i] * pdMin[i + 1][r]);

      pdMin[l][r] = min(pdMin[l][r], pdMax[l][i] * pdMax[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMin[l][i] * pdMax[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMax[l][i] * pdMin[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMin[l][i] * pdMin[i + 1][r]);
    }
    else if(op[i] == '+') {
      pdMax[l][r] = max(pdMax[l][r], pdMax[l][i] + pdMax[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMin[l][i] + pdMax[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMax[l][i] + pdMin[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMin[l][i] + pdMin[i + 1][r]);

      pdMin[l][r] = min(pdMin[l][r], pdMax[l][i] + pdMax[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMin[l][i] + pdMax[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMax[l][i] + pdMin[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMin[l][i] + pdMin[i + 1][r]);
    }
    else if(op[i] == '-') {
      pdMax[l][r] = max(pdMax[l][r], pdMax[l][i] - pdMax[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMin[l][i] - pdMax[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMax[l][i] - pdMin[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMin[l][i] - pdMin[i + 1][r]);

      pdMin[l][r] = min(pdMin[l][r], pdMax[l][i] - pdMax[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMin[l][i] - pdMax[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMax[l][i] - pdMin[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMin[l][i] - pdMin[i + 1][r]);
    }
    else {
      pdMax[l][r] = max(pdMax[l][r], pdMax[l][i] * pdMax[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMin[l][i] * pdMax[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMax[l][i] * pdMin[i + 1][r]);
      pdMax[l][r] = max(pdMax[l][r], pdMin[l][i] * pdMin[i + 1][r]);

      pdMin[l][r] = min(pdMin[l][r], pdMax[l][i] * pdMax[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMin[l][i] * pdMax[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMax[l][i] * pdMin[i + 1][r]);
      pdMin[l][r] = min(pdMin[l][r], pdMin[l][i] * pdMin[i + 1][r]);
    }
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%lld %c", v + i, op + i);
    v[i + n] = v[i];
    op[i + n] = op[i];
  }
  for(int i = 0; i < n; ++i) {
    go(i, i + n - 1);
    printf("%lld%lld", abs(pdMin[i][i + n - 1]), abs(pdMax[i][i + n - 1]));
  }
  printf("\n");
  return 0;
}