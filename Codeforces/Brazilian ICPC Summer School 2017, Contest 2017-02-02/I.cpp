#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< int, int > ii;
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


void arquivo() {
  freopen("transform.in", "r", stdin);
  freopen("transform.out", "w", stdout);
}

struct rotation {
  int a, b, c;
  rotation(){};
  rotation(int _a, int _b, int _c) {
    a = _a;
    b = _b;
    c = _c;
  }
};

const int N = 101;

char lol[] = {'A', 'C', 'G', 'T'};

int getIdx(char c) {
  for(int i = 0; i < 4; ++i) if(c == lol[i]) return i;
}

int getDiff(int a, int b) {
  if(b < a) b += 4;
  return b - a;
}

int ro[N];
char s[N], t[N];
int n;
char pd[N][N][N][N];
bitset<N>memo[N][N][N];
vector< rotation > rotationNeed[4];


char func(int pos, int r1, int r2, int r3) {
  if(pos == n) return 0;
  if(memo[pos][r1][r2][r3]) return pd[pos][r1][r2][r3];
  int ret = n;
  int rotAtual = (r1 + (r2 * 2) + (r3 * 3)) % 4;
  int need = getDiff(rotAtual, ro[pos]);
  for(int z = 0; z < rotationNeed[need].size(); ++z) {
    int i = rotationNeed[need][z].a;
    int j = rotationNeed[need][z].b;
    int k = rotationNeed[need][z].c;
    if(r1 + i < 0 || r2 + j < 0 || r3 + k < 0) continue;
    int nr1 = r1 + i, nr2 = r2 + j, nr3 = r3 + k;
    int atRot = (nr1 + (nr2 * 2) + (nr3 * 3)) % 4;
    while(atRot < 0) atRot += 4;
    int cost = (i > 0) + (j > 0) + (k > 0);
    if(atRot == ro[pos]) ret = min(ret, func(pos + 1, nr1, nr2, nr3) + cost);
  }
  memo[pos][r1][r2][r3] = 1;
  return pd[pos][r1][r2][r3] = ret;
}

int op[3][N];
int pp[3];

void back(int pos, int r1, int r2, int r3) {
  if(pos == n) {
    while(pp[0]) printf("%d %d 1\n", op[0][--pp[0]], n);
    while(pp[1]) printf("%d %d 2\n", op[1][--pp[1]], n);
    while(pp[2]) printf("%d %d 3\n", op[2][--pp[2]], n);
    return;
  }
  int ret = pd[pos][r1][r2][r3];
  int rotAtual = (r1 + (r2 * 2) + (r3 * 3)) % 4;
  int need = getDiff(rotAtual, ro[pos]);
  for(int z = 0; z < rotationNeed[need].size(); ++z) {
    int i = rotationNeed[need][z].a;
    int j = rotationNeed[need][z].b;
    int k = rotationNeed[need][z].c;
    if(r1 + i < 0 || r2 + j < 0 || r3 + k < 0) continue;
    int nr1 = r1 + i, nr2 = r2 + j, nr3 = r3 + k;
    int atRot = (nr1 + (nr2 * 2) + (nr3 * 3)) % 4;
    while(atRot < 0) atRot += 4;
    int cost = (i > 0) + (j > 0) + (k > 0);
    if(atRot == ro[pos] && func(pos + 1, nr1, nr2, nr3) + cost == ret) {
      if(i > 0) op[0][pp[0]++] = (pos + 1);
      else if(i < 0) printf("%d %d 1\n", op[0][--pp[0]], pos);
      if(j > 0) op[1][pp[1]++] = (pos + 1);
      else if(j < 0) printf("%d %d 2\n", op[1][--pp[1]], pos);
      if(k > 0) op[2][pp[2]++] = (pos + 1);
      else if(k < 0) printf("%d %d 3\n", op[2][--pp[2]], pos);
      back(pos + 1, nr1, nr2, nr3);
      return;
    }
  }
}

int main() {
  arquivo();
  for(int i = -1; i <= 1; ++i) {
    for(int j = -1; j <= 1; ++j) {
      for(int k = -1; k <= 1; ++k) {
        int r = (i + j * 2 + k * 3) % 4;
        while(r < 0) r += 4;
        rotationNeed[r].pb(rotation(i, j, k));
      }
    }
  }

  scanf(" %s %s", s, t);
  n = strlen(s);
  for(int i = 0; i < n; ++i) {
    int d = getDiff(getIdx(s[i]), getIdx(t[i]));
    ro[i] = d;
  }
  printf("%d\n", func(0, 0, 0, 0));
  back(0, 0, 0, 0);
  return 0;
}