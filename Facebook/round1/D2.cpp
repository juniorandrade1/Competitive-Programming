#include <bits/stdc++.h>
 
#define mod 1000000007
 
using namespace std;
 
typedef long long ll;
 
ll fat[4005];
ll den[4005];
 
ll myModPow(ll k, ll exp)
{
  if(exp == 0)
    return 1LL;
 
  ll ans = myModPow(k, exp/2) % mod; 
  ans = (ans * ans) % mod;
 
  if(exp % 2) ans = (ans * k) % mod;
 
  return ans;
}
 
void pre()
{
  fat[0] = fat[1] = den[1] = 1;
  for(int i=2;i<4005;i++)
  {
    fat[i] = (fat[i-1] * i) % mod;
    den[i] = myModPow(fat[i], mod-2);
  }
}
 
ll comb(ll n, ll k)
{
  if(k < 0)
    return 0;
  if(k == 0)
    return 1;
  ll num = 1;
  for(ll i=n;i>k;i--)
    num = (num * i) % mod;
  printf("%lld\n", den[n - k]);
  // printf("comb %lld %lld -> %lld %lld -> %lld\n", n, k, num, den[n-k], (num * den[n-k]) % mod);
  return (num * den[n-k]) % mod;
}
 
ll f(int bord, int sum, int n, int m)
{
  int k = m - 1 - (sum - bord);
 
  return comb(n+k, k) % mod;
}
 
main()
{
  int t;
  scanf("%d", &t);
 
  pre();                          // complexidade 4*10^3
 
  for(int c=1;c<=t;c++)           // mult td por 100
  {
    int n, m;
    scanf("%d %d", &n, &m);
 
    int v[2005];
    int sum = 0;
    for(int i=0;i<n;i++)          // complexidade 2*10^3
    {
      scanf("%d", &v[i]);
      sum += v[i]*2;
    }
 
    queue<int> d;
    int cont[4005];
    memset(cont, 0, sizeof cont); // complexidade 4*10^3
 
    for(int i=0;i<n;i++)          // complexidade 4*10^6
    {
      for(int j=i+1;j<n;j++)
      {
        // bordas = i, j
        if(cont[v[i]+v[j]] == 0)
          d.push(v[i]+v[j]);
 
        cont[v[i]+v[j]] += 2;
      }
    }
 
    ll ans = 0;
    while(!d.empty()) // complexidade max = 4000 * 4000 = 1.6 * 10^7
    {
      int atu = d.front(); d.pop();
 
      ans = (ans + cont[atu] * f(atu, sum, n, m)) % mod;  
 
      // printf("%d -> %d x %lld\n", atu, cont[atu], f(atu, sum, n, m));
    } 
    printf("Case #%d: %lld\n", c, n == 1 ? m : (ans * fat[n-2]) % mod);
  }
}