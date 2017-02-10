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

const int N = 1234567;

char s[N];

vector< string > v;
int depth[N];
vi g[N];
int counterNxt = 0;
int maxiDepth = 0;

int getNum(string foo) {
  int aux = 0;
  for(int i = 0; i < foo.size(); ++i) {
    aux *= 10;
    aux += foo[i]-'0';
  }
  return aux;
}

int dfs(int pos) {
  maxiDepth = max(maxiDepth, depth[pos]);
  int num = getNum(v[pos + 1]);
  int size = 1;
  while(num--) {
    depth[pos + 2 * size] = depth[pos] + 1;
    size += dfs(pos + 2 * size);
  }
  return size;
}


int main() {
  scanf(" %s", s);
  char *f = strtok(s, ",");
  while(f != NULL) {
    v.pb((string)f);
    f = strtok(NULL, ",");
  }
  for(int i = 0; i < v.size(); i += 2) {
    if(depth[i] == 0) {
      depth[i] = 1;
      counterNxt = i;
      dfs(i);
    }
  }
  for(int i = 0; i < v.size(); i += 2) g[depth[i]].pb(i);
  printf("%d\n", maxiDepth);
  for(int i = 1; i <= maxiDepth; ++i) {
    for(int j = 0; j < g[i].size(); ++j) printf("%s ", v[g[i][j]].c_str());
    printf("\n");
  }
  return 0;
}