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

const int N = 805000;

int n;
char s[N][11];
int tr[N][26];
int fim[N];
int qtd = 1;
int len;
int dis[N];
int pai[N];

queue<int>q; 

void dfs(int x, int id, int tam, int diff) {
  if(diff >= 2) return;
  if(tam == len) {
    int y = fim[x];
    if(dis[y] > dis[id] + 1) {
      dis[y] = dis[id] + 1;
      q.push(y);
      pai[y] = id;
    }
    return;
  }
  for(int i = 0; i < 26; ++i) {
    if(tr[x][i] == 0) continue;
    dfs(tr[x][i], id, tam + 1, diff + (i != (s[id][tam] - 'a')));
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf(" %s", s[i]);
    len = strlen(s[i]);
    int f = 0;
    for(int j = 0; j < len; ++j) {
      int c = s[i][j] - 'a';
      if(tr[f][c] == 0) tr[f][c] = qtd++;
      f = tr[f][c];
    }
    fim[f] = i;
  }
  for(int i = 0; i < n; ++i) {
    dis[i] = INF;
    pai[i] = -1;
  }

  q.push(0);
  dis[0] = 0;
  while(!q.empty()) {
    int x = q.front(); q.pop();
    dfs(0, x, 0, 0);
  }

  if(dis[n - 1] == INF) puts("FAIL");
  else {
    int id = n - 1;
    vi sol;
    while(id >= 0) {
      sol.pb(id);
      if(id == 0) break;
      id = pai[id];
    }
    reverse(sol.begin(), sol.end());
    printf("%d\n", (int)sol.size());
    for(int i = 0; i < (int)sol.size(); ++i) printf("%s\n", s[sol[i]]);
  }

  return 0;
}