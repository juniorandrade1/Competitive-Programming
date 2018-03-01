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

const int LOGN = (23);
const int N = (1 << LOGN);
const int SHIFT = N / 2;

#define EPS 1e-7
using namespace std;

#define PI acos(-1.0)

typedef long double CTYPE;

struct Complex {
  CTYPE a, b; // a + bi
  Complex(){
    a = 0.0;
    b = 0.0;
  };
  Complex(CTYPE _a, CTYPE _b) {
    a = _a;
    b = _b;
  }
  Complex operator+(const Complex &o)const {
    return Complex(o.a + a, b + o.b);
  }

  Complex operator/(double v) const {
    return Complex(a / v, b / v);
  }
  Complex operator*(const Complex &o)const {
    return Complex(a * o.a - b * o.b, a * o.b + b * o.a);
  }

  Complex operator-(const Complex &o) const {
    return Complex(a - o.a, b - o.b);
  }
};

int rev[N];
Complex wlen_pw[N];
 
void fft (Complex a[], int n, bool invert) {
  for (int i = 0; i < n; ++i) if (i < rev[i]) swap (a[i], a[rev[i]]);
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : +1);
    int len2 = len >> 1;
    Complex wlen (cos(ang), sin(ang));
    wlen_pw[0] = Complex(1, 0);
    for (int i = 1; i < len2; ++i) wlen_pw[i] = wlen_pw[i - 1] * wlen;
    for (int i = 0; i < n; i += len) {
      Complex t, *pu = a+i, *pv = a+i+len2,  *pu_end = a+i+len2, *pw = wlen_pw;
      for (; pu!=pu_end; ++pu, ++pv, ++pw) {
        t = *pv * *pw;
        *pv = *pu - t;
        *pu = *pu + t;
      }
    }
  }
  if (invert) for (int i=0; i<n; ++i) a[i] = a[i] / n;
}
 
void calc_rev (int n, int log_n) {
  for (int i = 0; i < n; ++i) {
    rev[i] = 0;
    for (int j = 0; j < log_n; ++j) if (i & (1 << j)) rev[i] |= 1 << (log_n - 1 - j);
  }
}

char s[100010];
int len;
Complex a[N], b[N];

int main() {
  calc_rev(N, LOGN);
  scanf(" %s", s);
  len = strlen(s);
  a[SHIFT].a = 1;
  b[SHIFT].a = 1;
  int sum = 0;
  for(int i = 0; i < len; ++i) {
    sum += (s[i] - 'a' + 1);
    a[SHIFT + sum].a++;
    b[SHIFT - sum].a++;
  }
  int ans = 0;
  fft(a, N, 0);
  fft(b, N, 0);
  for(int i = 0; i < N; ++i) a[i] = a[i] * b[i];
  fft(a, N, 1);
  for(int i = SHIFT + 1; i < N; ++i) ans += (int)(a[i].a + 0.5) > 0;
  printf("%d\n", ans);
  return 0;
} 