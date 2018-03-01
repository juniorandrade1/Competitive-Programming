#include <bits/stdc++.h>

using namespace std;

inline int getDigitSum(int x) {
  int digitSum = 0;
  while(x) {
    digitSum += (x % 10); 
    x /= 10;
  }
  return digitSum;
}

int main() {
  int n; scanf("%d", &n);
  vector< int > solution;
  for(int x = 0; x <= 500; ++x) {
    int need = n - x;
    if(getDigitSum(need) == x) solution.push_back(need);
  }
  printf("%d\n", (int)solution.size());
  for(int i = 0; i < (int)solution.size(); ++i) printf("%d\n", solution[i]);  
  return 0;
}