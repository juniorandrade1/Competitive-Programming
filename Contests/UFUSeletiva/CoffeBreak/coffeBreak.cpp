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

int flow[N * 3][N * 3];
vii g[N * 3];
ll dis[N];
int p[N];

inline void clearFlow() {
  for(int i = 0; i < 3 * N; ++i) {
    memset(flow[i], 0, sizeof flow[i]);
    g[i].clear();
  }
}

inline void addEdge(int x, int y, int f, int w) {
  flow[x][y] += f;
  g[x].pb(mp(y, w));
  g[y].pb(mp(x, -w));
}

inline bool dij(int _s, int _t) {
  for(int i = 0; i < countTables + countTeams + 2; ++i) {
    dis[i] = LINF;
    p[i] = -1;
  }
  dis[_s] = 0; pq<ii>q; q.push(ii(0, _s));
  while(!q.empty()) {
    ii foo = q.top(); q.pop();
    int x = foo.S;
    ll w = -foo.F;
    if(dis[x] != w) continue;
    for(int i = 0; i < g[x].size(); ++i) {
      int y = g[x][i].F;
      ll cst = g[x][i].S;
      if(flow[x][y] <= 0) continue;
      if(dis[y] > dis[x] + cst) {
        dis[y] = dis[x] + cst;
        q.push(mp(-dis[y], y));
        p[y] = x;
      }
    }
  }
  return dis[_t] != LINF;
}

ii mcmf(int _s, int _t) {
  ll cost = 0, flw = 0;
  while(dij(_s, _t)) {
    int foo = _t;
    while(foo != _s) {
      flow[p[foo]][foo]--;
      flow[foo][p[foo]]++;
      foo = p[foo];
    }
    cost += dis[_t];
    flw++;
  }
  return ii(flw, cost);
}

int disBetweenTeamsAndTables[N][N];

inline bool go(int top) {
  clearFlow();
  int source = countTeams + countTables, sink = source + 1;
  for(int i = 0; i < countTeams; ++i) addEdge(source, i, 1, 0);
  for(int i = 0; i < countTables; ++i) addEdge(i + countTeams, sink, 1, 0);
  for(int i = 0; i < countTeams; ++i) {
    for(int j = 0; j < countTables; ++j) {
      if(disBetweenTeamsAndTables[i][j] > top) continue;
      addEdge(i, j + countTeams, 1, disBetweenTeamsAndTables[i][j]);
    }
  }
  ii sol = mcmf(source, sink);
  return sol.F == countTeams;
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

inline void input() {
  init();
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) scanf(" %s", v[i]);
  printf("%lld\n", solve());
}


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
    }
    fprintf(in, "\n");
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
