#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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

/*
  Author: Junior Andrade
*/ 

void arquivo() {
  freopen("","r",stdin);
  freopen("","w",stdout);
}

const int N = 5200000;
const int SHIFT = N / 2;

#define EPS 1e-7
using namespace std;

#define pi acos(-1.0)

struct dificil {
  double real;
  double im;
  dificil() {
    real=0.0;
    im=0.0;
  }

  dificil(double real, double im):real(real),im(im){}

  dificil operator+(const dificil &o)const {
    return dificil(o.real+real, im+o.im);
  }

  dificil operator/(double v) const {
    return dificil(real/v, im/v);
  }

  dificil operator*(const dificil &o)const {
    return dificil(real*o.real-im*o.im, real*o.im+im*o.real);
  }

  dificil operator-(const dificil &o) const {
    return dificil(real-o.real, im-o.im);
  }
};

dificil tmp[N*2];
int coco,maiorpot2[N];

void fft(vector<dificil> &A, int s)
{
  int n = A.size(), p = 0;

  while(n>1){
    p++;
    n >>= 1;
  }

  n = (1<<p);

  vector<dificil> a=A;

  for(int i = 0; i < n; ++i){
    int rev = 0;
    for(int j = 0; j < p; ++j){
      rev <<= 1;
      rev |= ( (i >> j) & 1 );
    }
    A[i] = a[rev];
  }

  dificil w, wn;

  for(int i = 1; i <= p; ++i){
    int M = 1 << i;
    int K = M >> 1;
    wn = dificil(cos(s*2.0*pi/(double)M), sin(s*2.0*pi/(double)M) );
    for(int j = 0; j < n; j += M){
      w = dificil(1.0, 0.0);
      for(int l = j; l < K + j; ++l){
        dificil t = w;
        t = t*A[l + K];
        dificil u = A[l];
        A[l] =A[l]+ t;
        u = u-t;
        A[l + K] = u;
        w = wn*w;
      }
    }
  }

  if(s==-1){
    for(int i = 0;i<n;++i)
      A[i] = A[i]/(double)n;
  }
}

void mul(vector<dificil> &a, vector<dificil> &b)
{
  for(int i=0;i<a.size();i++)
  {
    a[i]=a[i]*b[i];
  }
}

char s[100010];
int len;
ll csum[100010];

int main() {
  scanf(" %s", s);
  len = strlen(s);
  vector<dificil> a;//(N, 0);
  vector<dificil> b;//(N, 0);
  for(int i = 0; i < N; ++i) {
    a.pb(dificil());
    b.pb(dificil());
  }
  
  a[SHIFT].real = 1;
  b[SHIFT].real = 1;
  for(int i = 0; i < len; ++i) {
    csum[i] = csum[i - 1] + (s[i] - 'a' + 1);
    a[SHIFT + csum[i]].real++;
    b[SHIFT - csum[i]].real++;
  }
  int ans = 0;
  mul(a, b);
  for(int i = SHIFT + 1; i < N; ++i) ans += (int)(a[i].real + 0.5) > 0;
  printf("%d\n", ans);
  
  return 0;
} 