#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


const int N = 100010;

const ll GAP = -10000000000LL;

set<ll> bst;
ll score[N];
int n, m;

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) {
    int a, b; scanf("%d %d", &a, &b);
    if(a == 1) {
      score[a] += GAP + b;
      set<ll> ax;
      for(set<ll>::iterator it = bst.begin(); it != bst.end(); it++) {
	if(score[a] < score[*it]) ax.insert(*it);
      }
      bst = ax;
    }
    else {
      score[a] += GAP + b;
      if(bst.find(a) != bst.end()) bst.erase(bst.find(a));
      if(score[a] < score[1]) bst.insert(a);
    }
    printf("%d\n", (int)bst.size() + 1);
  }
  return 0;
}
