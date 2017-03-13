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

const int N = 10;

vector< string > v;
set< char > allChars;
int idx[30];
char s[100000];
int n;
int perm[N];


inline int go() {
  for(int i = 0; i < n; ++i) {
    int val = perm[idx[v[i][0] - 'A']];
    if(val == 0) return 0;
  }  
  ll sum = 0;
  for(int i = 0; i + 1 < n; ++i) {
    ll at = 0;
    for(int j = 0; j < v[i].size(); ++j) {
      at *= 10;
      at += perm[idx[v[i][j] - 'A']];
    }
    sum += at;
  }

  ll need = 0;
  for(int j = 0; j < v[n - 1].size(); ++j) {
    need *= 10;
    need += perm[idx[v[n - 1][j] - 'A']];
  }
  return need == sum;
}

int allCount = 0;
int ans = 0;

void back(int pos, int mask) {
  if(pos == allCount) {
    ans += go();
    return;
  }
  for(int i = 0; i < 10; ++i) {
    if((mask >> i) & 1) continue;
    perm[pos] = i;
    back(pos + 1, mask | (1 << i));
  }
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf(" %s", s);
    v.pb((string)s);
  }
  for(int i = 0; i < n; ++i) for(int j = 0; j < v[i].size(); ++j) allChars.insert(v[i][j]);
  for(set< char > :: iterator it = allChars.begin(); it != allChars.end(); it++) idx[(*it) - 'A'] = allCount++;
  back(0, 0);
  printf("%d\n", ans);
  return 0;
}