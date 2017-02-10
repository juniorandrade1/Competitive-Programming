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

const int N = 1e5 + 10;

void arquivo() {
  freopen("pulp.in", "r", stdin);
  freopen("pulp.out", "w", stdout);
}

ii arr[N];
int n;

int main() {
  arquivo();
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%lld %lld", &arr[i].F, &arr[i].S);
  sort(arr, arr + n);

  ll sum = 0;
  int p = 0;
  ll t = 0;
  pq< ll > stories;

  while(p < n || stories.size()) {
    if(stories.size() == 0) {
      if(p < n && arr[p].F > t) t = arr[p].F;
      while(p < n && arr[p].F <= t) stories.push(-arr[p++].S);
      continue;
    }
    else {
      while(p < n && arr[p].F <= t) stories.push(-arr[p++].S);
      ll foo = -stories.top(); stories.pop();
      if(p < n) {
        ll qtd = arr[p].F - t;
        if(foo <= qtd) {
          t += foo;
          sum += t;
        } 
        else {
          t += qtd;
          foo -= qtd;
          stories.push(-foo);
        }
      }
      else {
        t += foo;
        sum += t;
      }
    }
  }
  printf("%lld\n", sum);
  return 0;
}