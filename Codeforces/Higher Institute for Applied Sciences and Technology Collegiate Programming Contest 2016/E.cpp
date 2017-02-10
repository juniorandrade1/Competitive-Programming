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

char s[N];
int qtd;
int len;
stack<int> st;

inline void getMin() {
  int q = qtd;
  for(int i = 0; i < len; ++i) {
     while(!st.empty() && st.top() < s[i] - '0' && q) st.pop(), q--;
     st.push(s[i] - '0');
  }
  while(q) st.pop(), q--;
  string foo = "";
  while(st.size()) foo.pb((char)st.top() + '0'), st.pop();
  reverse(foo.begin(), foo.end());
  printf("%s\n", foo.c_str());
}

inline void getMax() {
 int q = qtd;
  for(int i = 0; i < len; ++i) {
     while(!st.empty() && st.top() > s[i] - '0' && q) st.pop(), q--;
     st.push(s[i] - '0');
  }
  while(q) st.pop(), q--;
  string foo = "";
  while(st.size()) foo.pb((char)st.top() + '0'), st.pop();
  reverse(foo.begin(), foo.end());
  printf("%s\n", foo.c_str());
}

inline void main2() {
  scanf(" %s %d", s, &qtd);
  len = strlen(s);
  getMax();
  getMin();
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}