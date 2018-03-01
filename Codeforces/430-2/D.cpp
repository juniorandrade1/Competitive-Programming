#include <bits/stdc++.h>

using namespace std;

template <typename T>
class TrieInteger {
private:
  vector< vector< int > > tr;
  vector< int > fq;
  int MAX_BITS;
  void add(T x, int step, int node) {
    fq[node]++;
    if(step == -1) return;
    int b = ((x >> step) & 1);
    if(tr[node][b] == -1) {
      tr[node][b] = tr.size();
      tr.push_back(vector< int >(2, -1));
      fq.push_back(0);
    }
    add(x, step - 1, tr[node][b]);
  }
  int query(int x, int val, int bit) {
    if(x < 0) return 0;
    if(bit < 0) return 0;
    int b = ((val >> bit) & 1);
    if(tr[x][b] == -1 || fq[tr[x][b]] < (1 << bit)) return query(tr[x][b], val, bit - 1);
    else return query(tr[x][b ^ 1], val, bit - 1) + (1 << bit);
  }
public:
  TrieInteger() {
    tr.push_back(vector< int >(2, -1));
    fq.push_back(0);
    MAX_BITS = 19;
  }
  void add(T x) {
    add(x, MAX_BITS, 0);
  }
  int query(T x) {
    return query(0, x, MAX_BITS);
  }
};

int main() {
  int n, m; scanf("%d %d", &n, &m);
  TrieInteger< int > tr;
  vector< int > v(n);
  for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for(int i = 0; i < (int)v.size(); ++i) tr.add(v[i]);
  int atval = 0;
  while(m--) {
    int x; scanf("%d", &x);
    atval ^= x;
    printf("%d\n", tr.query(atval));
  }
  return 0;
}