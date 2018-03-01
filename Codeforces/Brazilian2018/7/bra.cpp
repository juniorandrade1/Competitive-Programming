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
                                                                                
const int N = 201;
const int M = 20001;                                                            

struct Node {
  int a, b, id;
  Node(){};
  Node(int _a, int _b, int _id) {
    a = _a;
    b = _b;
    id = _id;
  }
};
                                                                                
int n;                                                                          
vector< Node > v;                                                            
int a[N], b[N];                                                                              
int sol[N];  
int pd[M];
vector< int > res[M];                                                                   
                                                             
int main() {                                                                    
  scanf("%d", &n);                                                              
  for(int i = 0; i < n; ++i) scanf("%d", a + i);                                
  for(int i = 0; i < n; ++i) {
    scanf("%d", b + i);                                
    int pw = 1;
    while(pw <= b[i]) {
      v.pb(Node(a[i], pw, i));
      b[i] -= pw;
      pw <<= 1;
    }
    if(b[i]) v.pb(Node(a[i], b[i], i));
  }
  memset(pd, INF, sizeof pd);
  int k; scanf("%d", &k);                                                       
  pd[0] = 0;
  for(int i = 0; i < v.size(); ++i) {
    for(int j = k; j >= v[i].a * v[i].b; --j) {
      if(pd[j] > 1 + pd[j - v[i].a * v[i].b]) {
        res[j] = res[j - v[i].a * v[i].b];
        res[j].pb(i);
      }
      pd[j] = min(pd[j], 1 + pd[j - v[i].a * v[i].b]);
    }
  }
  printf("%d\n", pd[k]);
  for(int i = 0; i < res[k].size(); ++i) {
    int x = res[k][i];
    sol[v[x].id] += v[x].b;
  }
  for(int i = 0; i < n; ++i) {                                                  
    if(i) printf(" ");                                                          
    printf("%d", sol[i]);                                                       
  }                                                                             
  printf("\n");                                                                 
  return 0;                                                                     
}                                                                               
