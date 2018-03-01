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

const int N = 100010;

char s[N];
int n;

inline bool isChar(char c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

inline bool isOp(char c) {
  return c == '[' || c == ']' || c == '&' || c == '*';
}

inline bool isSpace(char c) {
  return c == ' ';
}

inline bool isComma(char c) {
  return c == ',';
}

inline string findType() {
  string ans = "";
  for(int i = 0; i < n; ++i) {
    if(isSpace(s[i])) break;
    ans.pb(s[i]);
  }
  return ans;
}

inline int findTypeIndex() {
  for(int i = 0; i < n; ++i) {
    if(isSpace(s[i])) return i;
  }
}

inline int findCommaIndex(int st) {
  for(int i = st; i < n; ++i) {
    if(s[i] == ',' || s[i] == ';') return i;
  }
}

int main() {
  freopen("isharp.in", "r", stdin);
  freopen("isharp.out", "w", stdout);
  scanf(" %[^\n]", s);
  n = strlen(s);
  string tp = findType();
  for(int i = findTypeIndex(); i < n - 1; ++i) {
    if(s[i] == ';') break;
    int nxt = findCommaIndex(i);
    string op = "";
    string vb = "";
    for(int j = i; j < nxt; ++j) {
      if(isOp(s[j])) op.pb(s[j]);
      else if(!isSpace(s[j]))vb.pb(s[j]);
    }
    reverse(op.begin(), op.end());
    for(int j = 0; j < op.size(); ++j) {
      if(op[j] == ']') op[j] = '[';
      else if(op[j] == '[') op[j] = ']';
    }
    printf("%s%s %s;\n", tp.c_str(), op.c_str(), vb.c_str());
    i = nxt;
  }


  return 0;
}