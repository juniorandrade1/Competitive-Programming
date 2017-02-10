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

const int N = 123456;

int n;

void arquivo() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

vi ans;
set< ii > allDragons;

int main() {
  arquivo();
  scanf("%d", &n);
  for(int i = 2; i <= n; ++i) {
    char c;
    ll coin;
    scanf(" %c %lld", &c, &coin);
    if(i == n) {
      if(allDragons.size() < coin) {
        puts("-1");
        exit(0);
      }
      else {
        ll sum = 0;
        while(allDragons.size()) {
          ans.pb((*allDragons.begin()).S);
          sum += (*allDragons.begin()).F;
          allDragons.erase(allDragons.begin());
        }
        printf("%lld\n", sum);
        sort(ans.begin(), ans.end());
        printf("%d\n", (int)ans.size());
        for(int i = 0; i < (int)ans.size(); ++i) {
          printf("%lld ", ans[i]);
        }
        printf("\n");
        exit(0);
      }
    }
    else {
      if(c == 'd') allDragons.insert(ii(coin, i));
      else while(allDragons.size() >= coin) allDragons.erase(allDragons.begin());
    }
  }



  return 0;
}