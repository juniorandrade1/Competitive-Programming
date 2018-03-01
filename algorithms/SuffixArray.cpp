#include <bits/stdc++.h>

using namespace std;

template <typename T> 
class SuffixArray {
private:
  struct Node {
    pair<T, T>nx;
    int p;
    Node(){};
    Node(T nx0, T nx1, int _p) {
      nx = make_pair(nx0, nx1);
      p = _p;
    }
    bool operator < (Node other) const {
      if(nx != other.nx) return nx < other.nx;
      return p < other.p;
    }
  };
  vector< Node > l;
  vector< T > v;
  vector< T > prev[2];
  int n;
public:
  vector< int > sa;
  SuffixArray(){};
  SuffixArray(vector< T > _v) {
    v = _v;
    n = (int)v.size();
    prev[0].resize(n); prev[1].resize(n); l.resize(n); sa.resize(n);
    for(int i = 0; i < n; ++i) prev[0][i] = v[i];
    int lst = 0;
    for(int stp = 1, cnt = 1; cnt < n; stp++, cnt *= 2) {
      for(int i = 0; i < n; ++i) {
        l[i] = Node(prev[~stp & 1][i], i + cnt < n ? prev[~stp & 1][i + cnt] : -1, i);
      }
      sort(l.begin(), l.end());
      for(int i = 0; i < n; ++i) {
        prev[stp][l[i].p] = (i > 0 && l[i].nx == l[i - 1].nx) ? prev[stp][l[i - 1].p] : i;
      }
      lst = stp;
    }
    for(int i = 0; i < n; ++i) sa[i] = l[i].p;
  }
};



int main() {
  vector< char > str; 
  str.push_back('m');
  str.push_back('i');
  str.push_back('s');
  str.push_back('s');
  str.push_back('i');
  str.push_back('s');
  str.push_back('s');
  str.push_back('i');
  str.push_back('p');

  SuffixArray< char > sa(str);
  for(int i = 0; i < sa.sa.size(); ++i) {
    printf("%d\n", sa.sa[i]);
  }
  return 0;
}