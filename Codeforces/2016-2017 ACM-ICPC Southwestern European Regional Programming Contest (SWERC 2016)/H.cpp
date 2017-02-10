#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

 
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};  
//////////////////////

const int N = 2000030;

int n;
int cor[N], corCount = 0, sizeTree[N];
set< int > g[N];

void dfs(int x, int ult, int color) {
  cor[x] = color;
  for(set<int>::iterator it = g[x].begin(); it != g[x].end(); it++) {
    if(*it == ult) continue;
    dfs(*it, x, color);
  }
}

void dfs2(int x, int ult, int color) {
  sizeTree[color]++;
  cor[x] = color;
  for(set<int>::iterator it = g[x].begin(); it != g[x].end(); it++) {
    if(*it == ult) continue;
    dfs2(*it, x, color);
  }
}

queue<int> qa, qb;
set<int> visA, visB;


inline void go(int ta, int tb) {
  visA.clear();
  visB.clear();
  int la = cor[ta], lb = cor[tb];
  int countA = 1, countB = 1;
  qa.push(ta); qb.push(tb);
  visA.insert(ta); visB.insert(tb);
  while(!qa.empty() && !qb.empty()) {
    if(countA <= countB) {
      int x = qa.front(); qa.pop();
      for(set<int>::iterator it = g[x].begin(); it != g[x].end(); it++) {
        if(visA.find(*it) != visA.end()) continue;
        countA++;
        qa.push(*it);
        visA.insert(*it);
      }
    }
    else {
      int x = qb.front(); qb.pop();
      for(set<int>::iterator it = g[x].begin(); it != g[x].end(); it++) {
        if(visB.find(*it) != visB.end()) continue;
        countB++;
        qb.push(*it);
        visB.insert(*it);
      }
    }
  }

  if(qa.empty()) {
    
  }
  else {

  }

}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) cor[i] = corCount++, sizeTree[i] = 1;
  while(1) {
    char c; scanf(" %c", &c);
    if(c == 'E') break;
    int a, b; scanf("%d %d", &a, &b);
    a--; b--;
    if(sizeTree[cor[a]] < sizeTree[cor[b]]) swap(a, b);
    if(c == 'C') {
      g[a].insert(b);
      g[b].insert(a);
      sizeTree[cor[a]] += sizeTree[cor[b]];
      sizeTree[cor[b]] = 0;
      dfs(b, a, cor[a]);
    }
    else if(c == 'D') {
      g[a].erase(g[a].find(b));
      g[b].erase(g[b].find(a));
      go(a, b);
    }
    else {
      printf(cor[a] == cor[b] ? "YES\n" : "NO\n");
      fflush(stdout);
    }
  }
  return 0;
}