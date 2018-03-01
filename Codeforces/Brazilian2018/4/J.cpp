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

const int N = 100010;

string arr[2] = {"AEIOU", "BCDFGHJKLMNPQRSTVWXYZ"};

char s[N];
int g[26][26];
int cor[26];
int exi[26];
vi tb[2];

int dfs(int x) {
  tb[cor[x]].pb(x);
  for(int i = 0; i < 26; ++i) {
    if(i == x) continue;
    if(g[x][i]) {
      if(cor[i] == -1) {
        cor[i] = 1 - cor[x];
        dfs(i);
      }
      else if(cor[i] == cor[x]) return false;
    }
  }
  return true;
}

string str;

vector< pair< vi, vi > > allCmp;
int pd[30][30][30];

int func(int pos, int cv, int cc) {
  if(pos == allCmp.size()) return cv == 0 && cc == 0;
  if(pd[pos][cv][cc] != -1) return pd[pos][cv][cc];
  int sf = allCmp[pos].F.size();
  int ss = allCmp[pos].S.size();
  int ret = 0;
  if(sf <= cv && ss <= cc) ret |= func(pos + 1, cv - sf, cc - ss);
  if(ss <= cv && sf <= cc) ret |= func(pos + 1, cv - ss, cc - sf);
  return pd[pos][cv][cc] = ret;
}

ii sol[30];
int countV = 0, countC = 0;

void back(int pos, int cv, int cc) {
  if(pos == allCmp.size()) return;
  int sf = allCmp[pos].F.size();
  int ss = allCmp[pos].S.size();
  if(sf <= cv && ss <= cc && func(pos + 1, cv - sf, cc - ss)) {
    for(int i = 0; i < sf; ++i) sol[allCmp[pos].F[i]] = ii(0, countV++);
    for(int i = 0; i < ss; ++i) sol[allCmp[pos].S[i]] = ii(1, countC++);
    back(pos + 1, cv - sf, cc - ss);
    return;
  }
  if(ss <= cv && sf <= cc && func(pos + 1, cv - ss, cc - sf)) {
    for(int i = 0; i < sf; ++i) sol[allCmp[pos].F[i]] = ii(1, countC++);
    for(int i = 0; i < ss; ++i) sol[allCmp[pos].S[i]] = ii(0, countV++);
    back(pos + 1, cv - ss, cc - sf);
    return;
  }
}

vector< string > vet;

int main() {
  freopen("javanese.in", "r", stdin);
  freopen("javanese.out", "w", stdout);
  while(scanf(" %[^\n]", s) != EOF) {
    vet.pb((string)s);
    char *v = strtok(s, " ");
    while(v != NULL) {
      int n = strlen(v);
      for(int i = 0; i + 1 < n; ++i) {
        int x = v[i] - 'A';
        int y = v[i + 1] - 'A';
        if(x < 0 || x >= 26 || y < 0 || y >= 26) continue;
        g[x][y] = 1;
        g[y][x] = 1;
      }
      v = strtok(NULL, " ");
    }
  }
  for(int i = 0; i < 26; ++i) {
    if(g[i][i]) {
      puts("impossible");
      return 0;
    }
  }
  int vc = 0, cc = 0;
  memset(cor, -1, sizeof cor);
  for(int i = 0; i < 26; ++i) {
    if(cor[i] != -1) continue;
    cor[i] = 0;
    tb[0].clear(); tb[1].clear();
    int ok = dfs(i);
    if(!ok) {
      puts("impossible");
      return 0;
    }
    allCmp.pb(mp(tb[0], tb[1]));
  }
  memset(pd, -1, sizeof pd);
  if(func(0, 5, 21)) {
    back(0, 5, 21);
    for(int z = 0; z < vet.size(); ++z) {
      for(int i = 0; i < vet[z].size(); ++i) {
        if(vet[z][i] >= 'A' && vet[z][i] <= 'Z') {
          int x = vet[z][i] - 'A';
          printf("%c", arr[sol[x].F][sol[x].S]);
        }
        else printf("%c", vet[z][i]);
      }
      printf("\n");
    }
    
  }
  else puts("impossible");

  return 0;
}