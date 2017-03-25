#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > brute;
int resposta = 0;

const int N = 1000000;

int n, c;
int v[N];

void func(int pos, int peg) {
  if(pos == n) {
    for(int i = 0; i < brute.size(); ++i) {
      printf("%d %d\n", brute[i].first, brute[i].second);
    }
    printf("-----------------------\n");
    printf("%d\n", resposta);
    printf("========================\n\n\n");
    return;
  }

  func(pos + 1, peg);


  if(peg == false) {
    brute.push_back(make_pair(pos, 1));
    resposta += (-v[pos] - c);
    func(pos + 1, 1);
    resposta -= (-v[pos] - c);
    brute.pop_back();
  }
  else {
    brute.push_back(make_pair(pos, 0));
    resposta += (+v[pos]);
    func(pos + 1, 0);
    resposta -= (+v[pos]);
    brute.pop_back();
  }
}

int main() {
  scanf("%d %d", &n, &c);
  for(int i = 0; i < n; ++i) scanf("%d", v + i);
  func(0, 0);
  return 0;
}