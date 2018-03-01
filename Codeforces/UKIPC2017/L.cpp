#include <bits/stdc++.h>

using namespace std;

const int N = 1000011;

struct Lizard {
  int x, y, h;
  long long w;
  Lizard(){};
  void read() {
    scanf("%d %d %d", &x, &y, &h);
  }
  bool operator < (Lizard l) {
    if(x != l.x) return x < l.x;
    if(y != l.y) return y < l.y;
    return w < l.w;
  }
};

Lizard l[N];

int main() {
  int tx, ty; scanf("%d %d", &tx, &ty);
  int n; scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    l[i].read();
    l[i].x -= tx;
    l[i].y -= ty; 
    l[i].w = (long long)l[i].x * l[i].x + (long long)l[i].y * l[i].y;
    int g = __gcd(abs(l[i].x), abs(l[i].y));
    l[i].x /= g;
    l[i].y /= g;
  }
  sort(l, l + n);
  int ans = 0;
  for(int i = 0; i < n; ++i) {
    int j = i;
    set<int>s;
    while(j < n && l[i].x == l[j].x && l[i].y == l[j].y) {
      set<int>::iterator it = s.lower_bound(l[j].h);
      if(it != s.end()) s.erase(it);
      s.insert(l[j].h);
      j++;
    }
    ans += (int)s.size();
    i = j - 1;
  }
  printf("%d\n", ans);
  return 0; 
}