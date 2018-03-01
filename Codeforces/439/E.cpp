#include <bits/stdc++.h>

using namespace std;

const int N = 2520;

typedef long long ll;
typedef pair<int, int> ii;

#define mp make_pair


ll bt[N][N];

void update(int x, int y, ll v) {
  x++; y++;
  for(int i = x; i < N; i += ((i & (-i)))) for(int j = y; j < N; j += ((j & (-j)))) bt[i][j] += v;
}

ll query(int x, int y) {
  x++; y++;
  ll ans = 0;
  for(int i = x; i; i -= ((i & (-i)))) for(int j = y; j; j -= ((j & (-j)))) ans += bt[i][j];
  return ans;
}

int n, m, q;
map< pair<ii, ii>, ll > o;

int main() {
  srand(time(NULL));
  scanf("%d %d %d", &n, &m, &q);
  for(int i = 0; i < q; ++i) {
    int t, r1, c1, r2, c2;
    scanf("%d %d %d %d %d", &t, &r1, &c1, &r2, &c2);
    if(t == 1) {
      ll foo = o[mp(mp(r1, c1), mp(r2, c2))] = ((ll)rand() << 15 | rand());
      update(r1, c1, foo);
      update(r1, c2 + 1, -foo);
      update(r2 + 1, c1, -foo);
      update(r2 + 1, c2 + 1, foo);
    }
    else if(t == 2){
      ll foo = -o[mp(mp(r1, c1), mp(r2, c2))];
      update(r1, c1, foo);
      update(r1, c2 + 1, -foo);
      update(r2 + 1, c1, -foo);
      update(r2 + 1, c2 + 1, foo);
    }
    else {
      ll ha = query(r1, c1);
      ll hb = query(r2, c2);
      puts(ha == hb ? "Yes" : "No");
    }
  }
  return 0;
}