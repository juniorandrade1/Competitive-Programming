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

const int N = 2000010;

struct SuffixAutomaton {
  vector< map<char,int> > edges; // edges[i]  : the labeled edges from node i
  vector<int> link;            // link[i]   : the parent of i
  vector<int> length;          // length[i] : the length of the longest string in the ith class
  int last;                    // the index of the equivalence class of the whole string

  SuffixAutomaton(string s) {
    // add the initial node
    edges.push_back(map<char,int>());
    link.push_back(-1);
    length.push_back(0);
    last = 0;

    for(int i=0;i<s.size();i++) {
      // construct r
      edges.push_back(map<char,int>());
      length.push_back(i+1);
      link.push_back(0);
      int r = edges.size() - 1;

      // add edges to r and find p with link to q
      int p = last;
      while(p >= 0 && edges[p].find(s[i]) == edges[p].end()) {
        edges[p][s[i]] = r;
        p = link[p];
      }
      if(p != -1) {
        int q = edges[p][s[i]];
        if(length[p] + 1 == length[q]) {
          // we do not have to split q, just set the correct suffix link
          link[r] = q;
        } else {
          // we have to split, add q'
          edges.push_back(edges[q]); // copy edges of q
          length.push_back(length[p] + 1);
          link.push_back(link[q]); // copy parent of q
          int qq = edges.size()-1;
          // add qq as the new parent of q and r
          link[q] = qq;
          link[r] = qq;
          // move short classes pointing to q to point to q'
          while(p >= 0 && edges[p][s[i]] == q) {
            edges[p][s[i]] = qq;
            p = link[p];
          }
        }
      }
      last = r;
    }
  }
};

char str[N];
vector< pair< ii, char > > edge;

int main() {
  scanf(" %s", str);
  SuffixAutomaton sa((string)str);
  printf("%d ", (int)sa.edges.size());
  for(int x = 0; x < sa.edges.size(); ++x) {
    for(map< char, int > :: iterator it = sa.edges[x].begin(); it != sa.edges[x].end(); it++) edge.pb(mp(mp(x, it->S), it->F));
  }
  printf("%d\n", (int)edge.size());
  for(int i = 0; i < edge.size(); ++i) {
    printf("%d %d %c\n", (int)edge[i].F.F + 1, (int)edge[i].F.S + 1, (char)edge[i].S);
  }
  vector<int> terminals;
  int p = sa.last;
  while(p > 0) {
    terminals.push_back(p);
    p = sa.link[p];
  }
  terminals.pb(0);
  printf("%d\n", (int)terminals.size());
  for(int i = 0; i < terminals.size(); ++i) {
    if(i) printf(" ");
    printf("%d", (int)terminals[i] + 1);
  }

  return 0;
}