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
#define PI acos(-1.0)
 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 100010;

int n;
ll v[N];

inline bool go() {
  for(int i = n - 2; i >= 0; --i) {
    int high = v[n - 1] + v[i] - 1;
    int low = v[n - 1] - v[i] + 1;
    int p1 = lower_bound(v, v + n - 1, low) - v;
    int p2 = upper_bound(v, v + n - 1, high) - v;
    if(p2 - p1 == 0) continue;
    if(p2 - p1 > 2) return true;
    else if(p1 == i) continue;
    else return true;
  }


  for(int i = 1; i < n; ++i) {
    int high = v[i] + v[0] - 1;
    int low = v[i] - v[0] + 1;
    int p1 = lower_bound(v + 1, v + n, low) - v;
    int p2 = upper_bound(v + 1, v + n, high) - v;
    if(p2 - p1 == 0) continue;
    if(p2 - p1 > 2) return true;
    else if(p1 == i) continue;
    else return true;
  }


  return false;
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%lld", v + i);
  sort(v, v + n);
  puts(go() ? "YES" : "NO");
  return 0;
}