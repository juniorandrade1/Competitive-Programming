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

int n, m;
map< string, int > v;
char s[1234567];

int main() {
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; ++i) {
    scanf(" %s", s);
    v[(string)s] |= 1;
  }
  for(int i = 0; i < m; ++i) {
    scanf(" %s", s);
    v[(string)s] |= 2;
  }
  int qa, qb, qc;
  qa = qb = qc = 0;
  for(map<string,int>::iterator it = v.begin(); it != v.end(); it++) {
    if(it->S == 1) {
      qa++;
    }
    else if(it->S == 2) {
      qb++;
    }
    else {
      qc++;
    }
  }

  int player = 0;
  while(1) {
    if(qc) {
      qc--;
    }
    else if(player == 0) {
      if(qa) qa--;
      else {
        puts("NO");
        return 0;
      }
    }
    else {
      if(qb) qb--;
      else {
        puts("YES");
        return 0;
      }
    }
    player ^= 1;
  }


  return 0;
}