#include <bits/stdc++.h>

using namespace std;
#define PI acos(-1.0)

const int LOGN = 16;
const int N = (1 << LOGN);

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
    for (int i=0; i<n; i+=len) {
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
    for (int j = 0; j < log_n; ++j)
      if (i & (1 << j)) rev[i] |= 1 << (log_n - 1 - j);
  }
}

const int HF = N / 2;

Complex A[N], B[N];
int c1[N], c2[N], c3[N];
double ans[N];


int main() {
  calc_rev(N, LOGN);
  int n; scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    c1[x + HF]++;
    c2[x + x + HF]++;
    c3[x + x + x + HF]++;
  }
  for(int i = 0; i < N; ++i) B[i] = Complex(c1[i], 0);
  fft(B, N, 0);
  for(int i = 0; i < N; ++i) A[i] = B[i] * B[i] * B[i];
  fft(A, N, 1);
  for(int i = 0; i < N; ++i) ans[i] = A[i].a;


  for(int i = 0; i < N; ++i) A[i] = Complex(c2[i], 0);
  fft(A, N, 0);
  for(int i = 0; i < N; ++i) A[i] = A[i] * B[i];
  fft(A, N, 1);
  for(int i = 0; i < N; ++i) ans[i] -= 3.0 * A[i].a;

  for(int i = 0; i < N; ++i) ans[i] += 2.0 * c3[i];

  for(int i = 0; i < N; ++i) {
    long long qtd = (long long)(ans[i] / 6.0 + 0.5);
    if(qtd > 0) printf("%d : %lld\n", i - HF, qtd);
  }
  return 0;
}