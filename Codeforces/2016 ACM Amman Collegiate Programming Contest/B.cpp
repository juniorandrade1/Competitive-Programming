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

int qtd[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

char s[N];
int n;

inline void main2(){
  scanf("%d %s", &n, s);
  int tot = 0;
  for(int i = 0; i < n; ++i) {
    tot += qtd[s[i] - '0'];
  }
  int need = n * 2;
  int at = 9;
  for(int i = 0; i < n; ++i) {
    int newNeed = (n - i - 1) * 2;
    int topNeed = (n - i - 1) * 7;
    while(tot - qtd[at] < newNeed || tot - qtd[at] > topNeed) at--;
    s[i] = at + '0';
    tot -= qtd[at];
  }
  printf("%s\n", s);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}