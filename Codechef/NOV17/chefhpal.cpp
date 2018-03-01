#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1000010;
 
string str;
int bst;
 
int n, a;
char s[N];
 
int manacher() {
  int ans = 0;
  vector<int> d1 (n);
  int l=0, r=-1;
  for (int i=0; i<n; ++i) {
    int k = (i>r ? 0 : min (d1[l+r-i], r-i)) + 1;
    while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
    d1[i] = k--;
    if (i+k > r)
      l = i-k,  r = i+k;
    ans = max(ans, r - l + 1);
  }
  vector<int> d2 (n);
  l=0, r=-1;
  for (int i=0; i<n; ++i) {
    int k = (i>r ? 0 : min (d2[l+r-i+1], r-i+1)) + 1;
    while (i+k-1 < n && i-k >= 0 && s[i+k-1] == s[i-k])  ++k;
    d2[i] = --k;
    if (i+k-1 > r)
      l = i-k,  r = i+k-1;
    ans = max(ans, r - l + 1);
  }
  return ans;
}
 
 
void genString(int pos) {
  if(pos == n) {
    int v = manacher();
    if(v < bst) {
      str = "";
      for(int i = 0; i < n; ++i) str.push_back(s[i]);
      bst = v;
    }
    return;
  }
  for(int i = 0; i < a; ++i) {
    s[pos] = i + 'a';
    genString(pos + 1);
  } 
}
 
 
inline void main2() {
  scanf("%d %d", &n, &a);
  if(a == 1) {
    bst = 12345678;
    genString(0);
    printf("%d %s\n", bst, str.c_str());
  }
  else if(a > 2) {
    printf("1 ");
    for(int i = 0; i < n; ++i) printf("%c", (i % 3) + 'a');
    printf("\n");
  }
  else {
    if(n <= 10) {
      bst = 12345678;
      genString(0);
      printf("%d %s\n", bst, str.c_str());
    }
    else {
      for(int i = 0; i < min(n, 4); ++i) s[i] = 'a';
      string magic = "babbaa";
      for(int i = 4; i < n; ++i) {
        int id = (i - 4) % 6;
        s[i] = magic[id];
      }
      s[n] = '\0';
      printf("%d %s\n", manacher(), s);
    }
  }
}
 
int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}