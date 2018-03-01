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

vector< string > foo;
string s, t;

string a(int i, int j) {
  string sol = "";
  for(int z = i; z <= j; ++z) sol.push_back(s[z]);
    return sol;
}

string b(int i, int j) {
  string sol = "";
  for(int z = i; z <= j; ++z) sol.push_back(t[z]);
  return sol;
}

int main() {
  cin >> s >> t;
  for(int i = 0; i < s.size(); ++i) {
    for(int j = 0; j < t.size(); ++j) {
      foo.push_back(a(0, i) + b(0, j));
    }
  }
  sort(foo.begin(), foo.end());
  cout << foo[0] << endl;
  return 0;
}