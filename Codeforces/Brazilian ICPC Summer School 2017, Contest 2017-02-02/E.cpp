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

const int N = 501;

void arquivo() {
  freopen("mayors.in", "r", stdin);
  freopen("mayors.out", "w", stdout);
}

string rgb = "RGB";
int cor[N];
vi g[N];
int n, m;

bool possible(int x, int c) {
  for(int i = 0; i < g[x].size(); ++i) if(cor[g[x][i]] == c) return false;
  return true;
}

int go(int x, int qtd = 1) {
  if(qtd == n) return true;
  for(int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if(cor[y] != -1) continue;
    for(int j = 0; j < 3; ++j) {
      if(possible(y, j)) {
        cor[y] = j;
        if(go(y, qtd + 1)) return true;
        cor[y] = -1;
      }
    }
  }
  return false;
}

int main() {
  arquivo();
  srand(time(NULL));
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; ++i) {
    int a, b; scanf("%d %d", &a, &b); a--; b--;
    g[a].pb(b); g[b].pb(a);
  }

  for(int i = 0; i < 10000; ++i) {
    int nop = 0;
    for(int j = 0; j < n && !nop; ++j) {
      cor[j] = (rand() % 3);
      for(int k = 0; k < g[j].size(); ++k) nop |= (cor[j] == cor[g[j][k]]);
    }
    if(!nop) {
      puts("Plan OK");
      for(int i = 0; i < n; ++i) printf("%c", rgb[cor[i]]);
      printf("\n");
      exit(0);  
    }
    else {
      for(int j = 0; j < n; ++j) cor[j] = -1;
    }
  }

  puts("Plan failed");

  return 0;
}