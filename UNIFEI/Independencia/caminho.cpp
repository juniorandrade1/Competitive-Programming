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

const int N = 123456;

ll v[N];
int n;

inline void main2(int test) {
  scanf("%d", &n);
  n--;
  bool hasPositive = false;

  ll curSum = 0;
  ll bstSum = 0;
  int lb, rb;

  int atl = 1;
  for(int i = 1; i <= n; ++i) {
    scanf("%lld", v + i);
    if(v[i] > 0) hasPositive = true;
    curSum += v[i];
    if(curSum > bstSum) {
      bstSum = curSum;
      lb = atl;
      rb = i;
    }
    else if(curSum == bstSum &&  i - atl > rb - lb) {
      bstSum = curSum;
      lb = atl;
      rb = i;
    }
    if(curSum < 0) {
      curSum = 0;
      atl = i + 1;
    }
  }
  if(hasPositive == false) {
    printf("Trecho %d não tem partes agradaveis, pois", test);
    ll sum = 0;
    for(int i = 1; i <= n; ++i) {
      sum += v[i];
      if(i != 1) printf(" +");
      printf(" %lld", v[i]);
    }
    printf(" = %lld\n", sum);
  }
  else {
    printf("A parte mais agradavel do trecho %d está entre %d e %d, isto eh,", test, lb, rb + 1);
    ll sum = 0;
    for(int i = lb; i <= rb; ++i) {
      sum += v[i];
      if(i != lb) printf(" +");
      printf(" %lld", v[i]);
    }
    printf(" = %lld\n", sum);
  }
}

int main() {
  int t; scanf("%d", &t);
  int test = 1;
  while(t--) main2(test++);
  return 0;
}