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

ll pd[20][200][2][2][2];
string sn, sk;
int sumN, sumK;

string intToString(ll x) {
  string foo = "";
  while(x) {
    foo.pb((x % 10) + '0');
    x /= 10;
  }
  while(foo.size() < 20) foo.pb('0');
  reverse(foo.begin(), foo.end());
  return foo;
}

int sumDigits(ll x) {
  int sum = 0;
  while(x) {
    sum += (x % 10);
    x /= 10;
  }
  return sum;
}

bool cmp(ll x, ll y) {
  if(sumDigits(x) != sumDigits(y)) return sumDigits(x) < sumDigits(y);
  return x < y;
}

ll func(int pos, int sum, int lessK, int greaterK, int lessN) {
  if(sum > sumK) return pd[pos][sum][lessK][greaterK][lessN] = 0;
  if(pos == sn.size()) return pd[pos][sum][lessK][greaterK][lessN] = (sum < sumK) || (sum == sumK && lessK);
  if(pd[pos][sum][lessK][greaterK][lessN] != -1) return pd[pos][sum][lessK][greaterK][lessN];
  ll ret = 0;
  int dn = sn[pos] - '0';
  int dk = sk[pos] - '0';
  for(int i = 0; i < 10; ++i) {
    if(lessN == false && i > dn) break;
    int nlessK = lessK, ngreaterK = greaterK;
    if(!nlessK && !ngreaterK) {
      nlessK |= (i < dk);
      ngreaterK |= (i > dk);
    }
    ret += func(pos + 1, sum + i, nlessK, ngreaterK, lessN | (i < dn));
  }
  return pd[pos][sum][lessK][greaterK][lessN] = ret;
}

ll pdCount[20][200][200][2], allSum[200];
string ax;

ll funcCount(int pos, int sumNeed, int sumTot, int less) {
  if(pos == ax.size()) return sumNeed == sumTot;
  if(pdCount[pos][sumNeed][sumTot][less] != -1) return pdCount[pos][sumNeed][sumTot][less];
  ll ret = 0;
  int top = (less) ? 9 : (ax[pos] - '0');
  for(int i = 0; i <= top; ++i) ret += funcCount(pos + 1, sumNeed, sumTot + i, less | (i < top));
  return pdCount[pos][sumNeed][sumTot][less] = ret;
}

int main() {
  ll n, k;
  scanf("%lld %lld", &n, &k);
  sn = intToString(n);
  sk = intToString(k);
  sumN = sumDigits(n);
  sumK = sumDigits(k);
  memset(pd, -1, sizeof pd);
  printf("%lld ", func(0, 0, 0, 0, 0));


  memset(pdCount, -1, sizeof pdCount);
  ax = intToString(k);
  for(int i = 1; i < 200; ++i) allSum[i] = allSum[i - 1] + funcCount(0, sumK, 0, 0);
  for(int i = 0; i < 200; ++i) {
    if(allSum[i] >= k) {
      sumK = i;
      break;
    }
  }
  ll lo = 1, hi = n;
  while(lo < hi) {
    ll md = (lo + hi) >> 1LL;
    memset(pd, -1, sizeof pd);
    ax = intToString(md);
    ll x = allSum[sumK - 1] + funcCount(0, sumK, 0, 0);
    if(x < k) lo = md + 1;
    else hi = md;
  }
  printf("%lld\n", lo);
  return 0;
}