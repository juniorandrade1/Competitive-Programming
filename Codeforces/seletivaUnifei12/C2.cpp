#include <bits/stdc++.h>
#define LOGN 23
#define MAXN (int)1e5
#define INF 0x3F3F3F3F
#define EPS 1e-9
#define pb push_back
#define mp make_pair
#define MOD 1000000007LL

using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef priority_queue<ii, vii, greater<ii> > pq;

int n;
vi graph[1000010];
map<string, int> mapa;
int maxd, depth[1000010];

void dfs(int u){
  depth[u] = 1;
  for(int j = 0; j < graph[u].size(); j++){
    int v = graph[u][j];
    if(!depth[v]) dfs(v);
    depth[u] = max(depth[u], depth[v]+1);
    maxd = max(maxd,depth[u]);
  }
}

void toposort(){
  for(int i = 0; i < n; i++)
    if(!depth[i]) dfs(i);
}

int main(){
  while(scanf("%d",&n)!=EOF && n){
    mapa.clear();
    for(int i = 0; i < n; i++) {
      graph[i].clear();
      depth[i] = 0;
    }
    char s[20];
    for(int i = 0; i < n; i++){
      scanf("%s",s);
      string disc(s);
      mapa[disc] = i;
      int q;
      scanf("%d",&q);
      for(int j = 0; j < q; j++){
  scanf("%s",s);
  string dep(s);
  graph[i].pb(mapa[dep]);
      }
    }
    toposort();
    printf("%d\n",maxd);
  }  
  return 0;
}