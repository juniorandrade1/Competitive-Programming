#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair< ll, ll > ii;
typedef vector< ll > vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s))
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef complex<long double> Complex;
const long double PI = acos(-1.0L);
// Computes the DFT of vector v if type = 1, or the IDFT if type = -1
vector<Complex> FFT(vector<Complex> v, int type) {
int n = v.size();
while(n&(n-1)) { v.push_back(0); n++; }
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
Complex w = 1;
for(int j=0; 2*j<m; j++) {
Complex t = w * v2[k + j + (m>>1)], u = v2[k + j];
v2[k + j] = u + t; v2[k + j + (m>>1)] = u - t;
w *= wm;
}
}
}
if(type == -1) for(Complex &c: v2) c /= n;
return v2;
}

const int N = 400001;

int main() {
  vector< Complex > vet(N);
  int n; scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    int x; scanf("%d", &x);
    vet[x] = Complex(real(vet[x]) + 1, imag(vet[x]));
  }
  vector< Complex > res = FFT(vet, 1);
  for(int i = 0; i < res.size(); ++i) res[i] = res[i] * res[i];
  vector< Complex > ans = FFT(res, -1);
  int m; scanf("%d", &m);
  ll sol = 0;
  for(int i = 0; i < m; ++i) {
    int x; scanf("%d", &x);
    int sum = 0;
    if(ans.size() > x) sum |= (round(real(ans[x])) >= 1);
    if(vet.size() > x) sum |= (round(real(vet[x])) >= 1);
    sol += sum;
  }
  printf("%lld\n", sol);
  return 0;
}