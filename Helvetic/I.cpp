#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long ll;

const int N = 2 * 100010;
const int NS = 1; //Numero de palavras da
 
int cn, cd, ns, en = 1, lst;
string S[NS]; int si = -1;
/* sufn[si][i] no do sufixo S[si][i...] */
vector<int> sufn[N];
 
struct node {
  int l, r, si;
  int p, suf, ct;
  map<char, int> adj;
  node() : l(0), r(-1), suf(0), p(0) {}
  node(int L, int R, int S, int P) : l(L), r(R), si(S), p(P), ct(0) {}
  inline int len() { return r - l + 1; }
  inline int operator[](int i) { return S[si][l + i]; }
  inline int& operator()(char c) { return adj[c]; }
} t[N];
 
inline int new_node(int L, int R, int S, int P) {
  t[en] = node(L, R, S, P);
  return en++;
}
 
void add_string(string s) {
  s += '$';
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

char str[N];
ll ans = 0;

inline ll sq(ll x) {
  return x * x;
}



ll dfs(int x, int len) {
  ll qtd = 0;
  for(map<char, int>::iterator it = t[x].adj.begin(); it != t[x].adj.end(); it++) {
    qtd += dfs(it->S, t[it->S].len());
  }
  if(t[x].adj.empty()) qtd = 1, len--;
  if(len >= 0) ans += sq(qtd) * len;
  return qtd;
}

inline void main2() {
  sufn[0].clear();
  for(int i = 0; i < en; ++i) t[i] = node();
  cn = 0, cd = 0, ns = 0, en = 1, lst = 0;
  si = -1;
  scanf(" %s", str);
  add_string((string)str);
  ans = 0;
  dfs(0, 0);
  printf("%lld\n", ans);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}