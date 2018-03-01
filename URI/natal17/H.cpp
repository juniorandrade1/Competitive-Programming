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

const int N = 100;

int n, m;
vector< string > p;
char s[N];

inline bool exists(string a, string b) {
  if(a.size() < b.size()) return false;
  for(int i = 0; i < 1; ++i) {
    int j = 0;
    while(j < b.size() && a[i + j] == b[j]) j++;
    if(j == b.size()) {
      return true;
    }
  }
  return false;
}

inline bool solve(string str) {
  reverse(str.begin(), str.end());
  for(int i = 0; i < n; ++i) {
    if(exists(str, p[i])) return false;
  }
  return true;
}

inline void main2() {
  p.clear();
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf(" %s", s);
    p.pb((string)s);
  }
  for(int i = 0; i < n; ++i) reverse(p[i].begin(), p[i].end());
  scanf("%d", &m);
  while(m--) {
    scanf(" %s", s);
    puts(solve(s) ? "Prossiga" : "Abortar");
  }
}

int main() {
  int t; scanf("%d", &t);
  for(int i = 0; i < t; ++i) {
    if(i) printf("\n");
    main2();
  }
  return 0;
}