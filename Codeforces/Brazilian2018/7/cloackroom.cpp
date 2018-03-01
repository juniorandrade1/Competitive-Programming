#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;

struct Event {
  int a, b, c, id;
  Event(int _a, int _b, int _c, int _id) {
    a = _a;
    b = _b;
    c = _c;
    id = _id;
  }
  bool operator < (Event other) const {
    if(a != other.a) return a < other.a;
    else return id < other.id;
  }
};

const int N = 100001;

int dp[N];

inline void insertElement(int a, int b, int c) {
  for(int i = N - 1; i >= c; --i) dp[i] = max(dp[i], min(dp[i - c], b));
}

int n, q;
vector< Event > ev;
bool solution[N * 10];

int main() {
  dp[0] = INF;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int c, a, b; scanf("%d %d %d", &c, &a, &b);
    ev.push_back(Event(a, b, c, -1));
  }
  scanf("%d", &q);
  for(int i = 0; i < q; ++i) {
    int m, k, s; scanf("%d %d %d", &m, &k, &s);
    ev.push_back(Event(m, m + s, k, i));
  }
  sort(ev.begin(), ev.end());
  for(int i = 0; i < ev.size(); ++i) {
    if(ev[i].id == -1) insertElement(ev[i].a, ev[i].b, ev[i].c);
    else solution[ev[i].id] = (dp[ev[i].c] <= ev[i].b);
  }
  for(int i = 0; i < q; ++i) puts(solution[i] == false ? "TAK" : "NIE");
  return 0;
}