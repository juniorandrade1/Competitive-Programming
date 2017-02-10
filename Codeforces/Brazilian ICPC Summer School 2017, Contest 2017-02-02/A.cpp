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
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

const int N = 1e5 + 10;

void arquivo() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}

struct name {
  vector< string > names;
  name(){};
  bool operator < (name other) {
    return true;
  }
};

struct est {
  int type;  
  vector< name > authors;
  string title, pub, year; //all
  string volume; //all optional
  string number, pages; //article
  est(){};
};

char s[N];

int main() {
  while(scanf(" [^\n]", s) != EOF) {
    int len = strlen(s);
    int type = 
  }
  return 0;
}