#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define EPS 1e-7
#define PI  3.1415926535897932384626433832795028841971693993
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};  
//////////////////////

const int N = 1011;

ll n;
ll v[N];

int main() {
  //ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 0; i < n; ++i) cin >> v[i];
  sort(v,v+n);
  double maxi = 0.;
  for(int i = 1; i < n; ++i) maxi = max(maxi,(double)(v[i]-v[i-1])/2.);
  printf("%.10lf\n",maxi);
  return 0;
}