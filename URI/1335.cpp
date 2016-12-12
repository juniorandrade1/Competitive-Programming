#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int ull;
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
#define snd second
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 5000000;
const int NS = 66;
int cn, cd, ns, en = 1, lst;
string S[NS]; int si = -1;
vector<int> sufn[NS];

struct node {
  int l, r, si;
  int p, suf, ct;
  map<char, int> adj;
  node() : l(0), r(-1), suf(0), p(0) {
    adj.clear();
  }
  node(int L, int R, int S, int P) : l(L), r(R), si(S), p(P), ct(0) {
    adj.clear();
  }
  inline int len() { return r - l + 1; }
  inline int operator[](int i) { return S[si][l + i]; }
  inline int& operator()(char c) { return adj[c]; }
} t[N];

ll mrk[N];

inline int new_node(int L, int R, int S, int P) {
  mrk[en] = 0;
  t[en] = node(L, R, S, P);
  return en++;
}

void add_string(string s) {
  s += "$";
  S[++si] = s;
  sufn[si].resize(s.size() + 1);
  cn = cd = 0;
  int i = 0; const int n = s.size();
  for(int j = 0; j < n; j++) {
    for(; i <= j; i++) {
      if(cd == t[cn].len() && t[cn](s[j]))
      cn = t[cn](s[j]), cd = 0;
      if(cd < t[cn].len() && t[cn][cd] == s[j]) {
        cd++;
        if(j < s.size() - 1) break;
        else {
          if(i) t[lst].suf = cn;
          for(; i <= j; i++) {
          sufn[si][i] = cn;
          cn = t[cn].suf;
        }
      }
    } else if(cd == t[cn].len()) {
        sufn[si][i] = en;
        if(i) t[lst].suf = en; lst = en;
        t[cn](s[j]) = new_node(j, n - 1, si, cn);
        cn = t[cn].suf;
        cd = t[cn].len();
      } else {
        int mid = new_node(t[cn].l, t[cn].l + cd - 1, t[cn].si, t[cn].p);
        t[t[cn].p](t[cn][0]) = mid;
        if(ns) t[ns].suf = mid;
        if(i) t[lst].suf = en; lst = en;
        sufn[si][i] = en;
        t[mid](s[j]) = new_node(j, n - 1, si, mid);
        t[mid](t[cn][cd]) = cn;
        t[cn].p = mid; t[cn].l += cd;
        cn = t[mid].p;
        int g = cn? j - cd : i + 1;
        cn = t[cn].suf;
        while(g < j && g + t[t[cn](S[si][g])].len() <= j) cn = t[cn](S[si][g]), g += t[cn].len();
        if(g == j) ns = 0, t[mid].suf = cn, cd = t[cn].len();
        else ns = mid, cn = t[cn](S[si][g]), cd = j - g;
      }
    }
  }
}


int n;
char s[N];

map< ll, int > exists;

ll dfs(int x) { 
  for(auto e : t[x].adj) mrk[x] |= dfs(e.second);
  return mrk[x];
}

void solve(int x) {
  if(x != 0) exists[mrk[x]] = x;
  for(auto e : t[x].adj) if(e.first != '$') solve(e.second);
}


inline void initTree(int szTree) {
  si = -1;
  en = 1;
  cn = cd = ns = lst = 0;
  t[0] = node();
  for(int i = 0; i < NS; ++i) sufn[i].clear();
}

int main() {
  while(scanf("%d", &n) != EOF && n > 0) {
    initTree(N);
    for(int i = 0; i < n; ++i) {
      scanf(" %s", s);
      add_string((string)s);
    }
    for(int i = 0; i < n; ++i) for(int ind : sufn[i]) {
      mrk[ind] |= (1LL << i);
    }
    exists.clear();
    dfs(0);
    solve(0);
    printf("%d\n", (int)exists.size());
  }
  return 0;
}