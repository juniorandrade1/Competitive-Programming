#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

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
#define Pi 2*acos(0)
#define eps 1e-6

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
//////////////////////

const int N = 100000;

string s[6][6];
map< char, vector< string > > foo;
char lol[] = {'V', 'A', 'N', 'E'};
vector< string > sol;

int main() {
  for(int i = 0; i < 5; ++i) 
    for(int j = 0; j < 5; ++j) cin >> s[i][j];

      for(int i = 0; i < 5; ++i) 
    for(int j = 0; j < 5; ++j) {
      char c; cin >> c;
      foo[c].pb(s[i][j]);
    }
    int qtd = 0;
    for(int z = 0; z < 4; ++z) {
      sort(foo[lol[z]].begin(), foo[lol[z]].end());
      for(int i = 0; i < foo[lol[z]].size(); ++i) {
        cout << foo[lol[z]][i] << " ";
        qtd++;
        //if(qtd % 5 == 0) cout << endl;
      }
      cout << endl;
    }

  return 0;
}