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


const int MATHUTILSMAXN = 1000000;

vector< bool > isPrime;
vector< int > primeDivisor;
vector< int > primeSet;
bool sieveIsCalculated;
int sizeSieve;

class MathUtils {
  public:
    MathUtils(){
      sieveIsCalculated = false;
      sizeSieve = 0;
    };

    static void sieve(int _sizeSieve) {
      sizeSieve = _sizeSieve;
      isPrime.resize(sizeSieve + 1, 1);
      primeDivisor.resize(sizeSieve + 1, 0);
      for(int i = 2; i <= sizeSieve; ++i) {
        if(isPrime[i]) {
          primeSet.pb(i);
          for(int j = 1; j * i <= sizeSieve; ++j) {
            if(j > 1) isPrime[j * i] = false;
            primeDivisor[j * i] = i;
          }
        }
      }
      sieveIsCalculated = true;
    }

    static vii factorize(ll x) {
      if(sieveIsCalculated == false) sieve(MATHUTILSMAXN);
      if(x <= sizeSieve) { //LOG(n) factorization
        vi tot;
        while(x > 1) {
          tot.pb(primeDivisor[x]);
          x /= primeDivisor[x];
        }
        sort(tot.begin(), tot.end());
        vii sol;
        for(int i = 0; i < tot.size(); ++i) {
          int j = i;
          while(j < tot.size() && tot[i] == tot[j]) j++;
          sol.pb(mp(tot[i], j - i));
          i = j - 1;
        }
        return sol;
      }
      else { //Prime factorization
        return vii();
      } 
    }

    static ll gcd(ll a, ll b) { return a?gcd(b%a, a):abs(b); }
    static ll lcm(ll x, ll y) { return (x&&y) ? abs(x) / gcd(x,y) * abs(y): 0; }
    static ll addMod(ll a, ll b, ll m) {
      ll s = ((a % m) + (b % m)) % m;
      if(s < 0) s += m;
      return s;
    }
    static ll subMod(ll a, ll b, ll m) {
      ll s = ((a % m) - (b % m)) % m;
      if(s < 0) s += m;
      return s;
    }
    static ll mulMod(ll a, ll b, ll mod) {
      if (b < 0) return mulMod(a, (b%mod + mod)%mod, mod);
      if (b == 0) return 0LL;
      ll ans = (2LL * mulMod(a, b/2, mod)) % mod;
      if (b%2 == 0) return ans;
      return (ans + a) % mod;
    }
    static ll gcd_extended(ll a, ll b, ll &x, ll &y) {
      if (a == 0) { x = 0, y = 1; return b; }
      ll xx, yy, d = gcd_extended(b%a, a, xx, yy);
      x = yy-(b/a)*xx, y=xx;
      if (d < 0) {d = -d; x = -x; y = -y; }
      return d;
    }

    static ll powMod(ll x, ll p, ll m) {
      ll ans = 1;
      while(p) {
        if(p & 1) ans = (ans * x) % m;
        x = (x * x) % m;
        x >>= 1;
      }
      return ans;
    }


    //para td i, (0 <= i < k), x = a[i] ( mod m[i])
    static bool chines_resto(ll &X, int k, vi &a, vi &m) {
      //Assume que k >= 1
      ll d, z, w, l = m[0];
      X = (a[0] % m[0] + m[0]) % m[0];
      for (int i = 1; i < k; i++) {
        a[i] %= m[i];
        d = gcd_extended(l, m[i], z, w);
        if ( (a[i]-X) % d != 0) return false;
        X += l*z*((a[i]-X)/d); //Pode usar mulmod(), pra nao estourar ll
        l = lcm(l, m[i]);
        X = ((X%l) + l) % l;
      }
      return true;
    }

    static ll nCrModpDP(int n, int r, int p) {
      vi C(r + 1);
      for(int j = 0; j <= r; ++j) C[j] = 0;
      C[0] = 1;
      for (int i = 1; i <= n; i++) for (int j = min(i, r); j > 0; j--) C[j] = addMod(C[j], C[j-1], p);
      return C[r];
    }

    static ll nCrModLucas(ll n, ll r, ll m) { //Only for primes
      if(r == 0) return 1;
      ll ni = n % m, ri = r % m;
      return (nCrModLucas(n / m, r / m, m) * nCrModpDP(ni, ri, m)) % m;
    }



    static ll largestDivisorOfNFatorialCoprimeWithPrimePPowerA(ll n, ll p, ll a, vi &fat) {
      ll pPowerA = powMod(p, a, LINF);
      if(fat.size() == 0) {
        fat.resize(p);
        fat[0] = 1LL;
        for(int i = 1; i < p; ++i) fat[i] = mulMod(fat[i - 1], i, pPowerA);
      }
      ll nModP = 1;
      for(int i = 1; i <= n; ++i) nModP = mulMod(nModP, i, p);
      ll fst = powMod(fat[p - 1], n / p, pPowerA);
      ll snd = nModP;
      ll trh = largestDivisorOfNFatorialCoprimeWithPrimePPowerA(n / p, p, a, fat);
      return mulMod(fst, mulMod(snd, trh, pPowerA), pPowerA);
    }

    static ll nCrModPrimePower(ll n, ll r, ll p, ll a) {
      ll power = 1;
      for(int i = 0; i < a; ++i) power *= p;
      return nCrModpDP(n, r, power);
    }

    static ll nCrModPWithChineseRemainderTheorem(ll n, ll r, ll p) {
      vii factorized = factorize(p);
      vi a, m;
      for(int i = 0; i < factorized.size(); ++i) {
        if(factorized[i].S == 1) {
          a.pb(nCrModLucas(n, r, factorized[i].F));
          m.pb(factorized[i].F);
        }
        else {
          ll at = 1;
          for(int i = 0; i < factorized[i].S; ++i) at *= factorized[i].F;
          a.pb(nCrModpDP(n, r, at));
          m.pb(at);
        }
      }
      ll solution;
      chines_resto(solution, a.size(), a, m);
      return solution;
    }
};

int main() {
  
  return 0;
}