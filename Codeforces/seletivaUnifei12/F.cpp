#include <iostream>
using namespace std;

int multNum(int x) {
  if(x == 0) return 0;
  int ans = 1;
  while(x) {
    ans *= (x % 10);
    x /= 10;
  }
  return ans;
}
 
int main() {
  int n;
  while(cin >> n) {
    if(n == 0) break;
    cout << n;
    while(n > 0) {
      if(n < 10) break;
      n = multNum(n);
      cout << " " << n;
    }
    cout << endl;
  }
  // while(n[0]!='0'){
  //   for(int i=0; i<n.size(); i++){
  //     produto *= n[i];
  //   }
  //   cout << produto;
  //   n = produto.str();
  // }
  // printf("\n");
  // your code goes here
  return 0;
}