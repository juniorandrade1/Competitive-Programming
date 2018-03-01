#include <bits/stdc++.h>

using namespace std;

const int N = 100001;

typedef long long ll;

struct Node {
  string s;
  ll a, b;
  Node(string _s, ll _a, ll _b) {
    s = _s;
    a = _a;
    b = _b;
  }
  bool operator < (Node foo) const {
    return a * foo.b < b * foo.a;
  }
};

int n;
char s[N];
vector< Node > v;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf(" %s", s);
    int len = strlen(s);
    int ca = 0, cb = 0;
    for(int j = 0; j < len; ++j) {
      ca += s[j] == 's';
      cb += s[j] == 'h';
    }
    v.push_back(Node((string)s, ca, cb));
  }
  sort(v.rbegin(), v.rend());
  ll ans = 0;
  ll qtd = 0;
  for(int i = 0; i < v.size(); ++i) {
    for(int j = 0; j < v[i].s.size(); ++j) {
      if(v[i].s[j] == 's') qtd++;
      else ans += qtd;
    }
  }
  printf("%lld\n", ans);
  return 0;
}