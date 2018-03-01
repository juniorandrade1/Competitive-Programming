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

const int N = 4001;

typedef char HType;

const int P1 = 31, P2 = 37, MOD = (int)1e9 + 7;

struct Hash {
  ll h1, h2;
  Hash(ll a = 0, ll b = 0) { h1 = a; h2 = b; }
  void append(HType c) {
    h1 = (P1*h1 + c) % MOD;
    h2 = (P2*h2 + c) % MOD;
  }
  bool operator== (Hash that) const {
    return h1 == that.h1 && h2 == that.h2;
   }
  bool operator!= (Hash that) const {
    return h1 != that.h1 || h2 != that.h2;
  }
  Hash operator* (Hash that) const {
    return Hash((h1*that.h1)%MOD, (h2*that.h2)%MOD);
  }
  Hash operator- (Hash that) const {
    return Hash( (h1 - that.h1 + MOD)%MOD, (h2 - that.h2 + MOD)%MOD);
  }
  bool operator < (Hash that) const {
    if(h1 != that.h1) return h1 < that.h1;
    return h2 < that.h2;
  }
  
};

Hash pot[N];

vector<Hash> build_hash(int n, string &v) {
  pot[0] = Hash(1,1);
  vector<Hash> ret;
  Hash acc;
  for(int i = 0; i < n; i++) {
    acc.append(v[i]);
    ret.push_back(acc);
    if(i > 0) pot[i] = pot[i-1] * Hash(P1, P2);
  }
  return ret;
}

inline Hash get_hash(int l, int r, vector<Hash> &hashv) {
  if(l == 0) return hashv[r];
  return hashv[r] - hashv[l-1] * pot[r-l+1];
}

inline bool isVowel(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

vector< string > word;
char s[N];
string text = "";
map< Hash, ii > lst;

string getString(string str) {
  int i = 0, j = str.size() - 1;
  while(i <= j) {
    if(isVowel(str[i])) break;
    i++;
  }
  while(i <= j) {
    if(isVowel(str[j])) break;
    j--;
  }

  string foo = "";
  for(int z = i; z <= j; ++z) foo.pb(toupper(str[z]));
  return foo;

}

string getString(string str, int l, int r) {
  string f = "";
  for(int i = l; i <= r; ++i) f.pb(str[i]);
  return f;
}


int tr[N][30];
int end[N];
int curT = 1;

void addString(string &str) {
  int x = 0;
  for(int i = 0; i < str.size(); ++i) {
    int c = str[i] - 'A';
    if(tr[x][c] == 0) {
      tr[x][c] = curT++;
    }
    x = tr[x][c];
  }
  end[x] = 1;
}

map< Hash, set< Hash > > contAmb;

int main() {
  freopen("kina.in", "r", stdin);
  freopen("kina.out", "w", stdout);
  while(scanf(" %s", s) != EOF) {
    if(word.size()) text += " ";
    string ax = getString((string)s);
    text += ax;
    word.pb(ax);
    addString(ax);
  }
  int n = text.size();
  vector< Hash > textHs = build_hash(n, text);  
  for(int len = 1; len <= n; ++len) {
    for(int i = 0; i + len - 1 < n; ++i) {
      if(s[i] == ' ') continue;
      if(s[i + len - 1] == ' ') continue;
      Hash hs = get_hash(i, i + len - 1, textHs);
      if(lst.find(hs) == lst.end()) lst[hs] = ii(i, 1);
      else {
        ii foo = lst[hs];
        if(foo.F + len <= i) lst[hs] = ii(i, foo.S + 1);
      }
    }
  }

  for(int i = 0; i < (int)word.size(); ++i) {
    Hash hs;
    Hash st;
    for(int j = i; j < (int)word.size(); ++j) {
      hs.append(word[j][0]);
      if(j != i) st.append(' ');
      for(int k = 0; k < word[j].size(); ++k) st.append(word[j][k]);
      if(contAmb[hs].size() >= 2) continue;
      contAmb[hs].insert(st);
    }
  }
  ll ans = 0;
  int l, r;
  for(int i = 0; i < word.size(); ++i) {
    Hash hs;
    Hash st;
    ll szall = 0;
    int x = 0;
    for(int j = i; j < word.size(); ++j) {
      hs.append(word[j][0]);
      if(x >= 0) {
        x = tr[x][word[j][0] - 'A'];
        if(x == 0) x = -1;
      }
      if(j != i) st.append(' ');
      for(int k = 0; k < word[j].size(); ++k) {
        st.append(word[j][k]);
        szall += isVowel(word[j][k]);
      }
      if(lst.find(st) == lst.end()) continue;
      if(x >= 0 && end[x]) continue;
      if(contAmb[hs].size() > 1) continue;
      ll sza = j - i + 1;
      ll q = lst[st].S;
      ll add = sza * q;
      ll sub = szall * (q - 1);
      ll atResp = sub - add;
      if(q > 1) {
        if(atResp >= ans) {
          ans = atResp;
          l = i;
          r = j;
        }
      }
    }
  }
  printf("%lld\n", ans);
  if(ans) {
    for(int i = l; i <= r; ++i) printf("%c", word[i][0]);
    printf("\n");
  }
  return 0;
}