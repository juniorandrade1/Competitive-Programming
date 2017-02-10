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

const int N = 200200;

int bit[N];

void add(int x) {
  x += 2;
  while(x < N) {
    bit[x]++;
    x += LSONE(x);
  }
}

int get(int x) {
  x += 2;
  int ret = 0;
  while(x) {
    ret += bit[x];
    x -= LSONE(x);
  }
  return ret;
}

int rangeSum(int l, int r) {
  return get(r) - get(l - 1);
}

int n, q;
int a[N], b[N];
int winnerIs;

vi g[N];
vi inv[N];
int k[N];
int kk[N];
int s1[N], s2[N];
int out[N];
vi appearA[N];
int fstApp[N];
set<int>tot;

int main() {
  memset(fstApp, -1, sizeof fstApp);
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d %d", a + i, b + i);
    if(fstApp[a[i]] == -1) fstApp[a[i]] = b[i];
    appearA[a[i]].pb(i);
    tot.insert(a[i]);

  }
  scanf("%d", &q);
  queue<int>que;
  for(int i = 0; i < q; ++i) {
    scanf("%d", k + i);
    int qtd = 0;
    for(int j = 0; j < k[i]; ++j) {
      int x; scanf("%d", &x);
      if(appearA[x].size() == 0) {
        qtd++;
      }
      else {
        g[i].pb(x);
        inv[x].pb(i);
      }
    }
    k[i] -= qtd;
    if(k[i] == 0) que.push(i);
  } 
  
  int winnerIs = n - 1;
  while(winnerIs >= 0) {
    if(out[a[winnerIs]]) winnerIs--;
    else {
      int idxWinner = a[winnerIs];
    
      while(!que.empty()) {
        int x = que.front(); que.pop();
        s1[x] = a[winnerIs];
        s2[x] = b[winnerIs];
      }

      for(int i = 0; i < inv[idxWinner].size(); ++i) {
        k[inv[idxWinner][i]]--;
        if(k[inv[idxWinner][i]] == 0) que.push(inv[idxWinner][i]);
      }

      int nxt = winnerIs - 1;
      while(nxt >= 0 && (out[nxt] || idxWinner == a[nxt])) nxt--;
      out[idxWinner] = 1;
      winnerIs = nxt;
    }
  }

  while(!que.empty()) {
    int x = que.front(); que.pop();
    set<int>aux = tot;
    for(int i = 0; i < g[x].size(); ++i) aux.erase(aux.find(g[x][i]));
    if(aux.size() == 1) {
      int idx = *aux.begin();
      s1[x] = idx;
      s2[x] = fstApp[idx];
    }
  }


  for(int i = 0; i < q; ++i) printf("%d %d\n", s1[i], s2[i]);
  return 0;
}