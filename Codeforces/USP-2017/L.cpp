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

#define pi acos(-1.0)

const int N = 1000001;
const int M = 101;

typedef char HType;

char s[N];
char p[N];
int pd[N][M];

int main(){
  int n, m, K;
  scanf("%d %d %d", &m, &n, &K);
  scanf("%s", p + 1);
  scanf("%s", s + 1);
  memset(pd, INF, sizeof pd);
  pd[0][0] = 0;
  int sol = INF;
  for(int i = 1; i <= n; i++) {
    pd[i][0] = 0;
    for(int j = 1; j <= m; j++) {
      if(s[i] == p[j]) pd[i][j] = min(pd[i][j], pd[i - 1][j - 1]);
      pd[i][j] = min(pd[i][j], pd[i - 1][j - 1] + 1);
      pd[i][j] = min(pd[i][j], pd[i - 1][j] + 1);
      pd[i][j] = min(pd[i][j], pd[i][j - 1] + 1);
    }
    sol = min(sol, pd[i][m]);
  }
  if(sol <= K) cout << "S" << endl;
  else cout << "N" << endl;
}