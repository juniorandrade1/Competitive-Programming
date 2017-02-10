#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef int ull;
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

const int N = 31;
const int M = 200001;

int n, m;
char c;
ll id;
ii mat[N][M];
int swapIdx[N];
int inv[N];

ll remap(char character) {
  if(character == 'R') return 4;
  if(character == 'W') return 3;
  if(character == 'G') return 2;
  if(character == 'S') return 1;
  assert(false);
}

inline void main2(int test) {
  if(test != 1) printf("\n");
  ull cnt = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      scanf(" [%lld] %c", &id, &c);
      if(c == 'R') cnt += (ull)id;
      mat[i][j] = ii(remap(c), id);
    }
    inv[i] = i;
  }
  ull sol = 0;
  for(int z = 0; z < m; ++z) {
    while(1) {
      int dd = 0;
      for(int j = 0; j + 1 < n; ++j) {
        int idxF = inv[j];
        int idxS = inv[j + 1];
        if(mat[idxF][z] > mat[idxS][z]) {
          dd = 1;
          swap(inv[j], inv[j + 1]);
          sol++;
        }
      }
      if(dd == 0) break;
    }
  }
  printf("Instance %02d:\n%d %d\n", test, sol, cnt);
}

int main() {
  int test = 1;
  while(scanf("%d %d", &n, &m) != EOF) main2(test++);
  return 0;
}