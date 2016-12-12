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
#define S second
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 1e4 + 10;

int n;
vector< string > cod;
vector< string > posCod;
char s[N];
int lens;

ll pB1[N];
const ull B1 = 43;

inline ull remap(char c) {
  if(c == 'A') return 1;
  if(c == 'C') return 2;
  if(c == 'T') return 3;
  if(c == 'G') return 4;
  assert(false);
}

inline void init() {
  cod.clear();
  posCod.clear();
}

inline ull recalculateHash(int outS, int lens) {
  ull foo = 0;
  for(int i = max(outS - lens, 0); i < outS; ++i) {
    foo *= B1;
    foo += remap(s[i]);//(ull)(s[i] - 'A' + 1);
  }
  return foo;
}

inline void process(int id, ull hashRna) {
  ull atHash = 0;
  int outS = 0;
  for(int i = 0; i < cod[id].size(); ++i) {
    s[outS++] = cod[id][i];
    atHash *= B1; atHash += remap(s[outS - 1]);//(ull)(s[outS - 1] - 'A'+ 1);
    if(outS > lens) atHash -= (pB1[lens] * remap(s[outS - lens - 1]));//(s[outS - lens - 1] - 'A'+ 1));
    if(outS >= lens && atHash == hashRna) { //deu Match
      outS = max(0, outS - lens);
      atHash = recalculateHash(outS, lens);
    }
  } 
  string out = "";
  for(int i = 0; i < outS; ++i) out.pb(s[i]);

  bool ok = 1;
  atHash = 0;
  for(int i = 0; i < out.size() && ok; ++i) {
    atHash *= B1;
    atHash += remap(out[i]);
    if(i > lens - 1) atHash -= (pB1[lens] * remap(out[i - lens]));
    if(i >= lens - 1 && atHash == hashRna) ok = 0;
  }
  assert(ok);

  posCod.pb(out);
}

unordered_map<ull, int>existsInAll;

inline bool isOK(int sz) {
  existsInAll.clear();
  for(int id = 0; id < posCod.size(); ++id) {
    ull atHash = 0;
    int outS = 0;
    for(int i = 0; i < posCod[id].size(); ++i) {
      atHash *= B1; atHash += remap(posCod[id][i]);//(ull)(posCod[id][i] - 'A' + 1);
      if(i > sz - 1) atHash -= (pB1[sz] * remap(posCod[id][i - sz]));//(posCod[id][i - sz] - 'A' + 1));
      if(i >= sz - 1) existsInAll[atHash] |= (1 << id);
    }
  }
  for(unordered_map<ull,int>::iterator it = existsInAll.begin(); it != existsInAll.end(); it++) {
    if(__builtin_popcount(it->S) == posCod.size()) return true;
  }
  return false;
}

unordered_map< ull, ii > auxVet;

string solve(int sz) {
  existsInAll.clear();
  auxVet.clear();
  for(int id = 0; id < posCod.size(); ++id) {
    ull atHash = 0;
    int outS = 0;
    for(int i = 0; i < posCod[id].size(); ++i) {
      atHash *= B1; atHash += remap(posCod[id][i]);//(ull)(posCod[id][i] - 'A' + 1);
      if(i > sz - 1) atHash -= (pB1[sz] * remap(posCod[id][i - sz]));//(posCod[id][i - sz] - 'A' + 1));
      if(i >= sz - 1) {
        existsInAll[atHash] |= (1 << id);
        auxVet[atHash] = ii(id, i);
      }
    }
  }
  string lst = "Z";
  for(unordered_map<ull,int>::iterator it = existsInAll.begin(); it != existsInAll.end(); it++) {
    if(__builtin_popcount(it->S) == posCod.size()) {
      int st = auxVet[it->F].S - sz + 1;
      int fs = auxVet[it->F].S;
      int id = auxVet[it->F].F;
      string lol = "";
      for(int j = st; j <= fs; ++j) lol.pb(posCod[id][j]);
      if(lst > lol) lst = lol;
    }
  }
  return lst;
}

int main() {
  pB1[0] = 1LL;
  for(int i = 1; i < N; ++i) pB1[i] = pB1[i - 1] * B1;
  while(scanf("%d", &n) != EOF) {
    init();
    for(int i = 0; i < n; ++i) {
      scanf(" %s", s);
      cod.pb((string)s);
    }
    scanf(" %s", s);
    lens = strlen(s);
    ull hashRna = 0;
    for(int i = 0; i < lens; ++i) hashRna *= B1, hashRna += remap(s[i]);//(ull)(s[i] - 'A' + 1);
    for(int i = 0; i < n; ++i) process(i, hashRna);
    int lo = 0, hi = INF;
    for(int i = 0; i < n; ++i) hi = min(hi, (int)posCod[i].size());
    while(lo < hi) {
      int mid = (lo + hi + 1) >> 1;
      if(isOK(mid)) lo = mid;
      else hi = mid - 1;
    }

    string solution = solve(lo);
    printf("%s\n", solution.c_str());
  }
  return 0;
}