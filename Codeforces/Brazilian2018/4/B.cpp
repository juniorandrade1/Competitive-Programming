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

const int N = 30;

int vis[2 * N + 2][2 * N + 2];
char resp[N];

bool tryMove(string s) {
  printf("%s\n", s.c_str());
  fflush(stdout);
  scanf(" %s", resp);
  if(strcmp(resp, "BLOCKED") == 0) return false;
  if(strcmp(resp, "EMPTY") == 0) return true;
  exit(0);
}

void go(int x, int y) {
  if(vis[x][y]) return;
  vis[x][y] = 1;
  if(tryMove("NORTH")) {
    go(x + 1, y);
    if (!tryMove("SOUTH")) exit(0);
  }
  if(tryMove("SOUTH")) {
    go(x - 1, y);
    if (!tryMove("NORTH")) exit(0);
  }
  if(tryMove("EAST")) {
    go(x, y + 1);
    if (!tryMove("WEST")) exit(0);
  }
  if(tryMove("WEST")) {
    go(x, y - 1);
    if (!tryMove("EAST")) exit(0);
  }
}

int main() {
  go(N, N);
  printf("DONE\n");
  fflush(stdout);
  return 0;
}