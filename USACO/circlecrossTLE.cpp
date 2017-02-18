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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

void arquivo() {
  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);
}

const int N = 100500;

bitset<N / 2> arr;
int n;
int v[N];
int ok[N / 2];

int main() {
  arquivo();
  scanf("%d", &n);
  for(int i = 0; i < 2 * n; ++i) scanf("%d", v + i);
  ll ans = 0;
  int j = 1;
  for(int i = 0; i < 2 * n; ++i) {
    if(ok[v[i]] == 0) {
      ll at = 0;
      ok[v[i]] = 1;
      j = i + 1;
      arr.reset();
      while(v[i] != v[j]) {
        arr.flip(v[j]);
        if(arr[v[j]]) at++;
        else at--;
        j++;
      }
      ans += at;
    }
  }
  printf("%lld\n", ans / 2LL);
  return 0;
}