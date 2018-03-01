#include <bits/stdc++.h>

using namespace std;

const int M = 200000001;
const int N = 2000001;

typedef long long ll;

int a[N];
int torneiras[31];
map<int, int> cycle;
int divisible[M];
int fstIndexes[N];

ll divTeto(ll x, ll y) {
  return (x + y - 1) / y;
}

int main() {
  int n, t, x, y;
  scanf("%d %d %d %d %d", &n, &t, &a[0], &x, &y);
  for(int i = 0; i < t; ++i) scanf("%d", torneiras + i);
  memset(fstIndexes, -1, sizeof fstIndexes);
  int stCycle = 0x3f3f3f3f;
  int edCycle = 0x3f3f3f3f;
  cycle[a[0]] = 0;
  divisible[0] = (a[0] % x);
  for(int i = 1; i < M; ++i) {
    int foo = 0;
    for(int j = 0; j < t; ++j) foo ^= ((a[i - 1] >> torneiras[j]) & 1);
    a[i] = (a[i - 1] >> 1);
    a[i] |= (foo << (n - 1));
    divisible[i] = ((divisible[i - 1] + a[i]) % x);
    if(cycle.find(a[i]) == cycle.end()) cycle[a[i]] = i;
    else {
      stCycle = cycle[a[i]];
      edCycle = i;
      break;
    }
  }
  if(stCycle == 0x3f3f3f3f || edCycle == 0x3f3f3f3f) {
    puts("impossivel");
    exit(0);
  }

  ll stAns = 0x3f3f3f3f3f3f3f3fLL, edAns = 0x3f3f3f3f3f3f3f3fLL;
  ll sumModCycle = 0;
  ll szCycle = edCycle - stCycle - 1;
  for(int i = stCycle; i < edCycle; ++i) sumModCycle = (sumModCycle + a[i]) % x;
  
  for(int i = 0; i <= edCycle; ++i) {
    if(divisible[i] == 0) {
      stAns = 0;
      edAns = i;
      break;
    }
  }
  for(int i = 0; i <= edCycle; ++i) {
    if(fstIndexes[divisible[i]] == -1) {
      fstIndexes[divisible[i]] = i;
    }
    else {  
      if(i - fstIndexes[divisible[i]] >= y) {
        if(i < edAns) {
          stAns = fstIndexes[divisible[i]] + 1;
          edAns = i;
        }
        else if(i == edAns && fstIndexes[divisible[i]] < stAns) {
          stAns = fstIndexes[divisible[i]] + 1;
          edAns = i;  
        }
      }
    }
  }
  
  for(int i = 0; i < stCycle; ++i) {
    ll valBefore = (divisible[stCycle - 1] - divisible[i] + 2 * x) % x;
    ll lenBefore = stCycle - i;
    ll need = x - valBefore;
    ll len = ((need * sumModCycle) / __gcd(need, sumModCycle)) * szCycle;
    if(lenBefore < y) {
      int tam = y - lenBefore;
      int qtd = divTeto(tam, len);
      len = qtd * len;
    }
    ll st = i;
    ll ed = i + len + lenBefore;
    if(ed < edAns) {
      stAns = st;
      edAns = ed;
    }
    else if(ed == edAns && st < stAns) {
      stAns = st;
      edAns = ed;
    }
  }


  for(int i = stCycle; i < edCycle; ++i) {
    ll valBefore = (divisible[stCycle] - divisible[i] + 2 * x) % x;
    ll lenBefore = edCycle - i - 1;
    ll need = x - valBefore;
    ll len = (((need * sumModCycle) / __gcd(need, sumModCycle)) / sumModCycle) * szCycle;
    if(lenBefore < y) {
      ll tam = y - lenBefore;
      ll qtd = divTeto(tam, len);
      len = qtd * len;
    }

    ll st = i;
    ll ed = i + len + lenBefore;
    printf("%lld %lld\n", st, ed);
    if(ed < edAns) {
      stAns = st;
      edAns = ed;
    }
    else if(ed == edAns && st < stAns) 
{      stAns = st;
      edAns = ed;
    }
  }
  
  printf("%lld %lld\n", stAns, edAns);
  return 0;
}