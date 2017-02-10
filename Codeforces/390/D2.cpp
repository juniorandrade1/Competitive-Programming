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

const int N = 1000000;

int n, k;
int L[N], R[N];

struct est {
  int x, id, type;
  est(){};
  est(int _x, int _id, int _type) {
    x = _x;
    id = _id;
    type = _type;
  }
  bool operator < (est foo) const {
    if(x != foo.x) return x < foo.x;
    return type > foo.type;
  }
};

vector< est > ev;

map< int, int > norm;
map< int, int > revN;
set<int> normS;
int normQ = 1;
int q[N];

int main() {
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; ++i) {
    scanf("%d %d", L + i, R + i);
    normS.insert(L[i]);
    normS.insert(R[i]);
  }
  for(set<int>::iterator it = normS.begin(); it !=  normS.end(); it++) {
    norm[*it] = normQ;
    norm[normQ++] = *it;
  }

  for(int i = 0; i < n; ++i) {
    L[i] = norm[L[i]];
    R[i] = norm[R[i]];
    q[L[i]]++;
    q[R[i] + 1]--;
  }

  for(int i = 1; i < N; ++i) q[i] += q[i - 1];

  return 0;
}