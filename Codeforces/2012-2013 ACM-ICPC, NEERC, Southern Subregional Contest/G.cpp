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

map< string, int > idx;
int cnt = 0;
char s1[123456], s2[123456];
char ss[123456];

void go() {
  int l = strlen(ss);
  int id = 0;
  int ca, cb;
  ca = cb = 0;
  while(ss[id] != '=') s1[ca++] = ss[id++];
  s1[ca++] = '\0';
  id++;
  while(id < l) s2[cb++] = ss[id++];
  s2[cb++] = '\0';
}

int findIdx(string s) {
  if(idx.find((string)s) == idx.end()) idx[(string)s] = cnt++;
  return idx[(string)s];
}


void arquivo() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

vii aux;
vii aux2;
map< vii, int > cont;

void back(int pos) {
  if(pos == aux.size()) {
    cont[aux2]++;
    return;
  }
  back(pos + 1);
  aux2.pb(aux[pos]);
  back(pos + 1);
  aux2.pop_back();
}

int main() {
  arquivo();
  int n; scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int q; scanf("%d", &q);
    aux.clear();
    while(q--) {
      scanf(" %s", ss);
      go();
      int a = findIdx((string) s1);
      int b = findIdx((string) s2);
      aux.pb(mp(a, b));
    }
    sort(aux.begin(), aux.end());
    back(0);
  }
  int m; scanf("%d", &m);
  for(int i = 0; i < m; ++i) {
    int q; scanf("%d", &q);
    vii lol;
    for(int j = 0; j < q; ++j) {
      scanf(" %s", ss);
      go();
      int a = findIdx((string) s1);
      int b = findIdx((string) s2);
      lol.pb(mp(a, b));
    }
    sort(lol.begin(), lol.end());
    printf("%d\n", cont[lol]);
  }
  return 0;
}