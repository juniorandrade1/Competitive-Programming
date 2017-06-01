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

const int N = 200020;
const int M = 26;

int n;
char s[N];
char c;
int tr[N][26], sz = 1;
int type[N];
bool fim[N];

inline void addString() {
  int t = (c == '+') ? 1 : 2;
  int at = 0;
  int len = strlen(s);
  type[at] |= t;
  for(int i = 0; i < len; ++i) {
    int x = (s[i] - 'a');
    if(tr[at][x] == -1)  tr[at][x] = sz++;
    at = tr[at][x];
    type[at] |= t;
  }
  if(t == 2) fim[at] = 1;
}

vector<string>sol;
bool zica = false;

void dfs(int x, string foo) {
  if(type[x] == 2) {
    if(foo != "") sol.pb(foo);
    return;
  }
  if(type[x] != 3) return;
  if(fim[x]) zica = true;
  for(int i = 0; i < 26; ++i) {
    if(tr[x][i] == -1) continue;
    string ai = foo; ai.pb(i + 'a');
    dfs(tr[x][i], ai);
  }
}

int main() {
  memset(tr, -1, sizeof tr);
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf(" %c %s", &c, s);
    addString();
  }
  dfs(0, "");
  if(zica) puts("-1");
  else {
    printf("%d\n", (int)sol.size());
    for(int i = 0; i < (int)sol.size(); ++i) printf("%s\n", sol[i].c_str());
  }
  return 0;
}