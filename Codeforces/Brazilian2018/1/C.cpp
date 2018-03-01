#include <bits/stdc++.h>

using namespace std;

const int N = 111;

char s[N], t[N];
int ls, lt;
int pd[N][N];
vector< int > sa, sb;

void rec(int a, int b) {
  if(a == ls || b == lt) return;
  if(s[a] == t[b] && pd[a][b] == pd[a + 1][b + 1] + 1) {
    sa.push_back(a + 1);
    sb.push_back(b + 1);
    rec(a + 1, b + 1);
    return;
  }
  if(pd[a + 1][b] == pd[a][b]) rec(a + 1, b);
  else rec(a, b + 1);
}

int main() {
  scanf(" %s %s", s, t);
  ls = strlen(s);
  lt = strlen(t);
  for(int i = ls - 1; i >= 0; --i) {
    for(int j = lt - 1; j >= 0; --j) {
      pd[i][j] = max(pd[i + 1][j], pd[i][j + 1]);
      if(s[i] == t[j]) pd[i][j] = max(pd[i][j], pd[i + 1][j + 1] + 1);
    }
  }
  printf("%d\n", pd[0][0]);
  rec(0, 0);
  for(int i = 0; i < (int)sa.size(); ++i) printf("%d ", sa[i]);
  printf("\n");
  for(int i = 0; i < (int)sb.size(); ++i) printf("%d ", sb[i]);
  return 0;
}