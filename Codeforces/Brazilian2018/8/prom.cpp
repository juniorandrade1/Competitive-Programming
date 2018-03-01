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

const int N = 250001;

int n, m, k;
int a[N], b[N];                                                                 
                                                                                
int main() { 
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < n; ++i) scanf("%d", a + i);
  for(int i = 0; i < m; ++i) scanf("%d", b + i);
  sort(a, a + n);
  sort(b, b + m);
  ll ans = 0;
  for(int i = 0; i < n; ++i) {
    ans += (ll)(upper_bound(b, b + m, a[i] + k) - lower_bound(b, b + m, a[i] - k));
  }
  printf("%lld\n", ans);
  return 0;                                                                     
}                                                                               
