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

const int N = 1000010;

char s[N];
int n;
int c[256];

int main() {
	scanf(" %s", s);
	n = strlen(s);
	for(int i = 0; i < n; ++i) {
		c[s[i]]++;
	}
	puts(c['K'] == c['P'] && c['P'] == c['N'] ? "1" : "0");
  return 0;
} 
