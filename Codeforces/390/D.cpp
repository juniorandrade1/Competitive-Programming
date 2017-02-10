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

const int N = 1000000;

int n, k;
ll L[N], R[N];

struct est {
  ll x, id, type;
  est(){};
  est(int _x, int _id, int _type) {
    x = _x;
    id = _id;
    type = _type;
  }
  bool operator < (est foo) const {
    if(x != foo.x) return x < foo.x;
    return type > foo.type;
  }
};

vector< est > ev;
set<int>active;

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i) {
    scanf("%lld %lld", L + i, R + i);
    ev.pb(est(L[i], i, 1));
    ev.pb(est(R[i], i, -1));
  }
  sort(ev.begin(), ev.end());
  ll bst = 0;
  int r = 0;
  active.clear();
  for(int i = 0; i < ev.size(); ++i) {
    while(r <= i)  {
      if(ev[r].type == 1) active.insert(ev[r].id); else active.erase(active.find(ev[r].id));
      r++;
    }
    while(r < ev.size() && active.size() >= k) {
      if(ev[r].type == 1) active.insert(ev[r].id);
      else {
        if(active.size() == k) break;
        active.erase(active.find(ev[r].id));
      }
      r++;
    }
    if(active.size() >= k) bst = max(bst, ev[r].x - ev[i].x + 1LL);
  }


  r = 0;
  active.clear();
  for(int i = 0; i < ev.size(); ++i) {
    while(r <= i)  {
      if(ev[r].type == 1) active.insert(ev[r].id); else active.erase(active.find(ev[r].id));
      r++;
    }
     while(r < ev.size() && active.size() >= k) {
      if(ev[r].type == 1) active.insert(ev[r].id);
      else {
        if(active.size() == k) break;
        active.erase(active.find(ev[r].id));
      }
      r++;
    }
    if(active.size() >= k) if(bst == ev[r].x - ev[i].x + 1) {
      printf("%lld\n", bst);
      for(set<int>::iterator it = active.begin(); it != active.end(); it++) printf("%d ", (*it) + 1);
      printf("\n");
      exit(0);
    }
  }

  printf("0\n");
  for(int i = 1; i <= k; ++i) printf("%d ", i);
  printf("\n");
  return 0;
}