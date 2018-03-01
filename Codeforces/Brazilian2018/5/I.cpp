  #include <bits/stdc++.h>

  using namespace std;

  typedef long long ll;

  typedef unsigned long long ull;
  typedef pair<ll,ll> ii;
  typedef vector<ll> vi;
  typedef vector< ii > vii;

  #define INF 0x3F3F3F3F
  #define LINF 0x3F3F3F3F3F3F3F3FLL
  #define pb push_back
  #define mp make_pair
  #define pq priority_queue
  #define LSONE(s) ((s)&(-s)) //LASTBIT
  #define DEG_to_RAD(X)   (X * PI / 180)
  #define F first
  #define S second

   
  #ifdef ONLINE_JUDGE
  #define debug(args...)
  #else
  #define debug(args...) fprintf(stderr,args)
  #endif

  //////////////////////
  int dx[] = {1,-1,0,0};
  int dy[] = {0,0,-1,1};  
  //////////////////////

  const int N = 100100;
  const int M = 26;

  struct state {
    int len, link;
    vector< int > next;
    state(){};
    state( int a, int b, vector< int > s ) {
      len = a;
      link = b;
      next = s;
    }
  };

  state st[4 * N];
  int sz, last;

  void init_sa() {
    sz = 1; last = 0;
    st[0] = state(0,-1,vector<int>(M, -1));
  }


  void add_char( char c ) {
    int cur = sz++;
    st[cur].len = st[last].len+1;
    st[cur].next = vector< int > (M, -1);
    int p = last;
    for( p = last; p != -1 && st[p].next[c] == -1; p = st[p].link ) st[p].next[c] = cur;
    if( p == -1 ) st[cur].link = 0;
    else {
      int q = st[p].next[c];
      if( st[p].len+1 == st[q].len ) st[cur].link = q;
      else {
        int clone = sz++;
        st[clone].len = st[p].len+1;
        st[clone].next = st[q].next;
        st[clone].link = st[q].link;
        for(;p!=-1 && st[p].next[c]==q;p = st[p].link) st[p].next[c] = clone;
        st[q].link = st[cur].link = clone;
      }
    }
    last = cur;
  }

  char s[N];
  char op;

  int main() {
    init_sa();
    while(scanf(" %c %s", &op, s) != EOF) {
      int n = strlen(s);
      for(int i = 0; i < n; ++i) s[i] = tolower(s[i]);
      if(op == 'A') for(int i = 0; i < n; ++i) add_char(s[i] - 'a');
      else {
        int x = 0;
        bool ok = true;
        for(int i = 0; i < n && ok; ++i) {
          x = st[x].next[s[i] - 'a'];
          if(x < 0) ok = false;
        }
        puts(ok ? "YES" : "NO");
      }
    }

    return 0;
  } 