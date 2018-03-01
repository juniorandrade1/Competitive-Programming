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

const int N = 1000010;

char s[N];
int n;
stack< char > st;

inline char inverse(char c) {
  if(c == '(') return ')';
  if(c == ')') return '(';
  if(c == '[') return ']';
  if(c == ']') return '[';
  if(c == '{') return '}';
  if(c == '}') return '{';
}

string solSt = "";

inline bool check() {
  for(int i = 0; i < n; ++i) {
    if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
      st.push(s[i]);
    }
    else {
      if(st.empty()) {
        solSt.pb(inverse(s[i]));
        continue;
      }
      if(st.top() != inverse(s[i])) return false;
      st.pop();
    }
  }
  return true;
}

                                                                                
int main() { 
  scanf(" %s", s);
  n = strlen(s);
  if(check() == false) puts("NIE");
  else {
    string ed = "";
    while(!st.empty()) {
      ed.pb(inverse(st.top())); st.pop();
    }
    reverse(solSt.begin(), solSt.end());
    printf("%s%s%s\n", solSt.c_str(), s, ed.c_str());
  }
  return 0;                                                                     
}                                                                               
