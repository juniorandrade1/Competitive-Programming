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

const int N = 10000010;

int n;
ll X[N], Ax, Bx, Cx;
ll H[N], Ah, Bh, Ch;
double ans;

set< pair<double, double> > allRect;
set< pair<double, double> > :: iterator it;
set< pair<double, double> > :: iterator it2;
vector< pair<double, double> > needErase;

inline void clearSet() {
  for(int i = 0; i < needErase.size(); ++i) {
    allRect.erase(allRect.find(needErase[i]));
  }
  needErase.clear();
}

inline void go(int idx) {

  it = allRect.lower_bound(mp(X[idx], -1));
  it2 = allRect.lower_bound(mp(X[idx], -1));

  while(it != allRect.end()) {
    double newH = H[idx] - fabs(X[idx] - it->F);
    if(newH >= it->S) {
      needErase.pb(*it);
      it++;
    }
    else break;
  }
  
  

  int ok = 0;
  while(it2 != allRect.begin()) {
    it2--;
   double newH = H[idx] - fabs(X[idx] - it->F);
    if(newH >= it2->S) {
      needErase.pb(*it2);
      continue;
    }
    else{
      ok = 1;
      break;
    }
  }


  if(ok) {
    double newH = it->S - fabs(X[idx] - it->F);
    if(newH >= H[idx]) {
      //Covered
      clearSet();
      return;
    }
  }

  
  if(it != allRect.end()) {
    double newH = it->S - fabs(X[idx] - it->F);
    if(newH >= H[idx]) {
      //Covered
      clearSet();
      return;
    }
  }
  


  if(ok) {
    double gap = fabs(H[idx] - it2->S) * 0.5;
    double mid = (X[idx] + it2->F) * 0.5;
    double findX, findH;
    if(H[idx] < it2->S) findX = mid + gap;
    else findX = mid - gap;
    findH = H[idx] - fabs(X[idx] - findX);
    ans -= (findH * findH);
    //allRect.insert(mp(findX, findH));
  }

  
  /*
  if(it != allRect.end()) {
    double gap = fabs(H[idx] - it->S) * 0.5;
    double mid = (X[idx] + it->F) * 0.5;
    double findX, findH;
    if(H[idx] < it->S) findX = mid + gap;
    else findX = mid - gap;
    findH = H[idx] - fabs(X[idx] - findX);
    ans -= (findH * findH);
    //allRect.insert(mp(findX, findH));
  }
  */
  
   
    

  clearSet();
  allRect.insert(mp(X[idx], H[idx]));
  ans += (H[idx] * H[idx]);
}

double globAns = 0;

inline void main2() {
  allRect.clear();
  globAns = 0;
  scanf("%d", &n);
  scanf("%lld %lld %lld %lld", X + 1, &Ax, &Bx, &Cx);
  scanf("%lld %lld %lld %lld", H + 1, &Ah, &Bh, &Ch);
  ans = H[1] * H[1];
  globAns += ans;
  allRect.insert(ii(X[1], H[1]));
  for(int i = 2; i <= n; ++i) {
    X[i] = ((Ax * X[i - 1] + Bx) % Cx) + 1;
    H[i] = ((Ah * H[i - 1] + Bh) % Ch) + 1;
    go(i);
    globAns += ans;
  }

  printf(" %.7lf\n", globAns);
}

int main() {
  int test; scanf("%d", &test);
  for(int i = 1; i <= test; ++i) {
    printf("Case #%d:", i);
    main2();
  }
  return 0;
}
