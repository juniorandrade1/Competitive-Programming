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

const int N = 200020;

vi v;

void print(int shift, int x) {
  for (int i = 1; i < x; i++) {
    printf("%d ", shift + i + 1);
  }
  printf("%d ", shift + 1);
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ll n; scanf("%lld", &n);
  if(n == 1) {
    puts("1\n1");
    return 0;
  }
  ll sum = 0;
  for(int i = 2; i <= 1e5; ++i) {
    ll lol = 1;
    while(n % i == 0) {
      n /= i;
      lol *= i;
    }
    if(lol > 1) {
      v.pb(lol);
      sum += lol;
    }
  }
  if(n > 1 || sum > 1e5) puts("No solution");
  else {
   
    ll sft = 0;
    printf("%lld\n", sum);
    for(int i = 0; i < v.size(); ++i) {
      print(sft, v[i]);
      sft += v[i];
    }
    printf("\n");
  }
  return 0;
}