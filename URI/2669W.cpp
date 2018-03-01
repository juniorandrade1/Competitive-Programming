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

void arquivo() {
  freopen("","r",stdin);
  freopen("","w",stdout);
}

const int N = (1 << 23);
const int SHIFT = N / 2;


#define PI acos(-1.0)

struct Complex {
  double a, b; // a + bi
  Complex(){
    a = 0.0;
    b = 0.0;
  };
  Complex(double _a, double _b) {
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


vector<Complex> FFT(vector<Complex> v, int type) {
  int n = v.size();
  int logn = __builtin_ctz(n);
  vector<Complex> v2(n);
  for(int i=0; i<n; i++) {
    int mask = 0;
    for(int j=0; j<logn; j++) if(i&(1<<j)) mask |= (1<<(logn - 1 - j));
    v2[mask] = v[i];
  }
  for(int s=0, m=2; s<logn; s++, m<<=1) {
    Complex wm(cos(2.L * type * PI / m), sin(2.L * type * PI / m));
    for(int k=0; k<n; k+=m) {
      Complex w = Complex(1, 0);
      for(int j=0; 2*j<m; j++) {
        Complex t = w * v2[k + j + (m>>1)], u = v2[k + j];
        v2[k + j] = u + t; v2[k + j + (m>>1)] = u - t;
        w = w * wm;
      }
    }
  }
  if(type == -1) for(int i = 0; i < v2.size(); ++i) v2[i] = v2[i] / n;
  return v2;
}



char s[100010];
int len;

int main() {
  scanf(" %s", s);
  len = strlen(s);
  vector< Complex > a(N, Complex());
  vector< Complex > b(N, Complex());
  a[SHIFT].a = 1;
  b[SHIFT].a = 1;
  int sum = 0;
  for(int i = 0; i < len; ++i) {
    sum += (s[i] - 'a' + 1);
    a[SHIFT + sum].a++;
    b[SHIFT - sum].a++;
  }
  int ans = 0;
  a = FFT(a, 1);
  b = FFT(b, 1);
  for(int i = 0; i < N; ++i) a[i] = a[i] * b[i];
  a = FFT(a, -1);
  for(int i = SHIFT + 1; i < N; ++i) ans += (int)(a[i].a + 0.5) > 0;
  printf("%d\n", ans);
  return 0;
} 