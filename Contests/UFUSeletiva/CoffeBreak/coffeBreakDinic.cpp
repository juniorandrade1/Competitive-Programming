// Junior Andrade

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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int N = 500;

int n, m;
char v[N][N];
vector< ii > tables, teams;
int countTables = 0, countTeams = 0;
int idxNodes[N][N];
int disTables[N][N];

inline bool inRange(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

void dijkstra(int _i, int _j) {
  memset(disTables, INF, sizeof disTables);
  pq< pair<int, ii> > q; q.push(mp(0, mp(_i, _j)));
  disTables[_i][_j] = 0;
  while(!q.empty()) {
    pair<int, ii> foo = q.top(); q.pop();
    int x = foo.S.F, y = foo.S.S;
    int w = -foo.F;
    if(disTables[x][y] != w) continue;
    for(int i = 0; i < 4; ++i) {
      int xx = dx[i] + x, yy = dy[i] + y;
      if(!inRange(xx, yy)) continue;
      if(v[xx][yy] == '#') {
        if(disTables[xx][yy] > disTables[x][y]) disTables[xx][yy] = disTables[x][y];
      }
      else {
        int cost = (v[xx][yy] == 'T') ? 0 : (v[xx][yy] - '0');
        if(disTables[xx][yy] > disTables[x][y] + cost) {
          disTables[xx][yy] = disTables[x][y] + cost;
          q.push(mp(-disTables[xx][yy], mp(xx, yy)));
        }
      }
    }
  }
}




typedef ll FTYPE;

const int MAXV = 100 * 100 * 2;
const FTYPE FINF = LINF;

struct Edge {
  int to;
  FTYPE cap;
  Edge(int t, FTYPE c) { to = t; cap = c; }
};

vector<int> adj[MAXV];
vector<Edge> edge;
int ptr[MAXV], dinic_dist[MAXV];

inline void addEdge(int u,int v,FTYPE c) {
  adj[u].push_back(edge.size());
  edge.push_back(Edge(v,c));
  adj[v].push_back(edge.size());
  edge.push_back(Edge(u,0)); 
}

bool dinic_bfs(int _s,int _t) {
  memset(dinic_dist,-1,sizeof(dinic_dist));
  dinic_dist[_s] = 0;
  queue<int> q;
  q.push(_s);
  while(!q.empty() && dinic_dist[_t] == -1) {
    int v = q.front();
    q.pop();
    for(size_t a=0;a<adj[v].size();++a) {
      int ind = adj[v][a];
      int nxt = edge[ind].to;
      if(dinic_dist[nxt] == -1 && edge[ind].cap) {
        dinic_dist[nxt] = dinic_dist[v] + 1;
        q.push(nxt);
      }
    }
  }
  return dinic_dist[_t] != -1;
}

FTYPE dinic_dfs(int v,int _t,FTYPE flow) {
  if(v == _t) return flow;
  for(int &a = ptr[v];a<(int)adj[v].size();++a) {
    int ind = adj[v][a];
    int nxt = edge[ind].to;
    if(dinic_dist[nxt] == dinic_dist[v] + 1 && edge[ind].cap) {
      FTYPE got = dinic_dfs(nxt,_t,min(flow,edge[ind].cap));
      if(got) {
        edge[ind].cap -= got;
        edge[ind^1].cap += got;
        return got;
      }
    }
  }
  return 0;
}

FTYPE dinic(int _s,int _t) {
  FTYPE ret = 0, got;
  while(dinic_bfs(_s,_t)) {
    memset(ptr,0,sizeof(ptr));
    while((got = dinic_dfs(_s,_t,FINF))) ret += got;
  }
  return ret;
}

inline void dinic_clear() {
  for(int a=0;a<MAXV;++a) adj[a].clear();
  edge.clear();
}

int disBetweenTeamsAndTables[N][N];

inline bool go(int top) {
  dinic_clear();
  int source = countTeams + countTables, sink = source + 1;
  for(int i = 0; i < countTeams; ++i) addEdge(source, i, 1);
  for(int i = 0; i < countTables; ++i) addEdge(i + countTeams, sink, 1);
  for(int i = 0; i < countTeams; ++i) {
    for(int j = 0; j < countTables; ++j) {
      if(disBetweenTeamsAndTables[i][j] > top) continue;
      addEdge(i, j + countTeams, 1);
    }
  }
  return dinic(source, sink) == countTeams;
}

inline void init() {
  countTeams = 0;
  countTables = 0;
  teams.clear();
  tables.clear();
}

inline string intToString(int x) {
  string f = "";
  while(x) {
    f.pb((x % 10) + '0');
    x /= 10;
  }
  while(f.size() < 2) f.pb('0');
  reverse(f.begin(), f.end());
  return f;
}

inline ll solve() {
  for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
    if(v[i][j] == 'T') {
      teams.pb(ii(i, j));
      idxNodes[i][j] = countTeams++;
    }
    else if(v[i][j] == '#') {
      tables.pb(ii(i, j));
      idxNodes[i][j] = countTables++;
    }
  } 
  for(int i = 0; i < teams.size(); ++i) {
    dijkstra(teams[i].F, teams[i].S);
    for(int j = 0; j < tables.size(); ++j) {
      disBetweenTeamsAndTables[i][j] = disTables[tables[j].F][tables[j].S];
    }
  }
  int lo = 0, hi = 100 * 100;
  while(lo < hi) {
    int mid = (lo + hi) >> 1;
    if(!go(mid)) lo = mid + 1;
    else hi = mid;
  }
  if(go(lo)) return lo;
  else return -1;
}

// input keyboard
inline void input() {
  init();
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) scanf(" %s", v[i]);
  printf("%lld\n", solve());
}

// input / generator
inline void inputByGenerator(int idx) {
  init();
  debug("%d\n", idx);
  FILE *in, *out;
  string sIn = "in/" + intToString(idx);
  string sOut = "out/" + intToString(idx);
  in = fopen(sIn.c_str(), "w");
  out = fopen(sOut.c_str(), "w");
  n = (rand() % idx) + 1;
  m = (rand() % idx) + 1;
  fprintf(in, "%d %d\n", n, m);
  //printf("%d %d\n", n, m);
  int cT = 0, cM = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      char c;
      while(1) {
        int val = (rand() % 12);
        c = (val + '0');
        if(val < 10) break;
        if(val == 10 && cT < idx) {
          c = 'T';
          cT++;
          break;
        }
        else if(val == 11 && cM < idx) {
          c = '#';
          cM++;
          break;
        } 
      }
      v[i][j] = c;
      fprintf(in, "%c", c);
      //printf("%c", c);
    }
    fprintf(in, "\n");
    //printf("\n");
  }


  fprintf(out, "%lld\n", solve());
  fclose(in);
  fclose(out);
}

int main() {
  srand(time(NULL));
  //for(int i = 1; i <= 100; ++i) inputByGenerator(i);  
  input();
  return 0;
}
