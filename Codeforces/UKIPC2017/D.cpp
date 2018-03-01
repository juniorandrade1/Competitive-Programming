#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

char s[N];
int n;
vector< pair<int, int> > sol;

int main() {
  scanf(" %s", s);
  n = strlen(s);
  for(int i = 0; i < n; ++i) {
    int id = -1;
    int mn = s[i];
    for(int j = i + 1; j < n; ++j) {
      if(s[j] < mn) {
        mn = s[j];
        id = j;
      }
    }
    if(id != -1) {
      swap(s[i], s[id]);
      sol.push_back(make_pair(id + 1, i + 1));
    }
  }
  for(int i = (int)sol.size() - 1; i >= 0; --i) printf("%d %d\n", sol[i].first, sol[i].second);
  return 0;
}