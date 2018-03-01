#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e9 + 7;
const int LOGN = 17;

vector< int > prime;

inline vector< int > lcm(vector< int > &a, vector< int > &b) {
  vector< int > s;
  for(int i = 0; i < (int)min(a.size(), b.size()); ++i) s.push_back(max(a[i], b[i]));
  return s;
}

inline vector< int > factorize(int &x, vector< int > &sol) {
  sol.resize(prime.size(), 0);
  for(int i = 0; i < (int)prime.size(); ++i) {
    while(x % prime[i] == 0) {
      x /= prime[i];
      sol[i]++;
    }
  }
  return sol;
}

inline bool cmp(const vector< int>  &a,const vector< int > &b) {
  double sa = 0, sb = 0;
  for(int i = 0; i < (int)prime.size(); ++i) {
    for(int j = 0; j < a[i]; ++j) sa += log((double)prime[i]);
    for(int j = 0; j < b[i]; ++j) sb += log((double)prime[i]);
  }
  return sa < sb;
}

template<class T> 
class SparseTable {
public:
  vector< vector< T > > spt;
  int n;
  SparseTable(){};
  SparseTable(int &_n, vector< int > &_v) {    
    n = _n;
    spt.resize(n);
    for(int i = 0; i < n; ++i) spt[i].resize(LOGN);
    for(int i = 0; i < n; ++i) factorize(_v[i], spt[i][0]);  
    for(int j = 1; j < LOGN; ++j) {
      for(int i = 0; i + (1 << j) <= n; ++i) {
        spt[i][j] = join(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  T join(T a, T b) {
    return lcm(a, b);
  }
  T query(int l, int r) {
    int b = 31 - __builtin_clz(r - l + 1);
    return join(spt[l][b], spt[r - (1 << b) + 1][b]);
  }
}; 

inline bool isPrime(int &x) {
  for(int i = 2; i * i <= x; ++i) if(x % i == 0) return false;
  return true;
}

inline void preprocess() {
  int tp = 60;
  for(int i = 2; i <= tp; ++i) if(isPrime(i)) prime.push_back(i);
}

inline int toInt(vector< int > &ax) {
  long long ans = 1;
  for(int i = 0; i < (int)prime.size(); ++i) {
    for(int j = 0; j < ax[i]; ++j) {
      ans *= prime[i];
      ans %= MOD;
    }
  }
  return ans;
}

vector< int > v;
int n, m;
SparseTable< vector< int > > g;
vector< int > sol;
vector< vector< int > > foo;

int main() {
  preprocess();
  scanf("%d %d", &n, &m);
  v.resize(n);
  for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
  g = SparseTable< vector< int >  >(n, v);
  foo.resize(n + 2);
  sol.resize(n + 2);
  for(int i = 0; i < n + 2; ++i) for(int j = 0; j < (int)prime.size(); ++j) foo[i].push_back(7);
  for(int i = 0; i < n; ++i) {
    int st = i;
    vector< int > lst;
    factorize(v[i], lst);
    while(st < n) {
      int lo = st, hi = n - 1;
      while(lo < hi) {
        int md = (lo + hi + 1) >> 1;
        if(lst == g.query(i, md)) lo = md;
        else hi = md - 1;
      }
      int sz = lo - i + 1;
      foo[sz] = min(foo[sz], g.query(i, st), cmp);
      st = lo + 1;
      lst = g.query(i, st);
    }
  }
  for(int i = n; i >= 0; --i) foo[i] = min(foo[i], foo[i + 1], cmp);  
  for(int i = 0; i <= n; ++i) sol[i] = toInt(foo[i]);
  for(int i = 0; i < m; ++i) {
    int x; scanf("%d", &x);
    printf("%d\n", sol[x]);
  }
  return 0;
}