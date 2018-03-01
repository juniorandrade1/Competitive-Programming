#include <bits/stdc++.h>

using namespace std;

vector< vector< int > > sol;

void back(int x, int lst, vector< int > at) {
  if(x == 0) {
    sol.push_back(at);
    return;
  }
  for(int i = min(x, lst); i >= 1; --i) {
    at.push_back(i);
    back(x - i, i, at);
    at.pop_back();
  }
}

int main() {
  int n; scanf("%d", &n);
  back(n, n, vector< int > ());
  for(int i = 0; i < sol.size(); ++i) {
    for(int j = 0; j < sol[i].size(); ++j) {
      if(j) printf("+");
      printf("%d", sol[i][j]);
    }
    printf("\n");
  }
  return 0;
}