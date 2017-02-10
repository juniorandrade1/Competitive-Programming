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

const int N = 10010;

int n, q;
ll pd[N][555];
ll v[N];
ll csum[N];
ll cost[N][N];

ll getSum(int i, int j) {
  if(i == 0) return csum[j];
  return csum[j] - csum[i - 1];
}


void func(int k, int l, int r, int ll, int rr){
    if(l>r) return;
    int m = (l+r)/2;
    pd[m][k] = LINF;
    int xd;
    for(int i = max(ll, m); i <= rr; i++){
      long long qtd = (i - m + 1) * (getSum(m, i));
        if(pd[m][k]>pd[i+1][k-1] + qtd){
            pd[m][k] = pd[i + 1][k - 1] + qtd;
            xd = i;
        }
    }
    func(k,l,m-1,ll,xd);
    func(k,m+1,r,xd,rr);
}

int main() {
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; ++i) {
    scanf("%lld", v + i);
    csum[i] = v[i];
    if(i) csum[i] += csum[i - 1];
  }
  for(int i = 0; i <= n; ++i) for(int j = 0; j <= q; ++j) pd[i][j] = LINF;
  for(int i = 0; i <= q; i++) pd[n][i] = 0;
  for(int i = 1; i <= q; i++) func(i,0,n-1,0,n-1);
  printf("%lld\n",pd[0][q]);
  return 0;
}