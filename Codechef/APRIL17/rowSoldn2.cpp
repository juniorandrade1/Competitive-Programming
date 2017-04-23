#include <bits/stdc++.h>

#define pq priority_queue

using namespace std;

char s[1234567];
int n;

inline void main2() {
  scanf(" %s", s);
  n = strlen(s);
  long long ans = 0;
  pq<int> q;
  set<int>ss;
  int lst = n;
  for(int i = n - 1; i >= 0; --i) if(s[i] == '1') {
    ss.insert(i);
    if(i + 1 != lst) {
      q.push(-i);
    }
    lst = i;
  }

  while(!q.empty()) {
    int i = -q.top(); q.pop();
    set<int>::iterator itIni = ss.find(i);
    set<int>::iterator itFim = ss.find(i); itFim++;
    ans++;
    if(itFim == ss.end()) {
      ans += (n - *itIni - 1);
      set<int>::iterator it = ss.find(i);
      if(it != ss.begin()) {
        it--;
        q.push(-(*it));
      }
      ss.erase(itIni);
      n--;
    }
    else {
      int vI = *itIni;
      int vF = *itFim;
      set<int>::iterator it = ss.find(i);
      if(it != ss.begin()) {
        it--;
        q.push(-(*it));
      }
      ans += (vF - vI - 1);
      ss.erase(itIni);
      ss.insert(vF - 1);
    }
  }





  printf("%lld\n", ans);
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}

//110000
//101000 + 2
//011000 + 2
//010100 + 2
//001100 
//001010
//000110
//000101
//000011