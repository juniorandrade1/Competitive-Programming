#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int N = 1000010;

char s[N];
int x, y, len;

inline int getScore(string str) {
  int score = 0;
  for(int i = 0; i < (int)str.size(); ++i) {
    score += (str[i] == '*');
  }
  return score;
}

string generate(int qa, int qb, int op) {
  int st = op;
  priority_queue< int > q[2];
  string sol = "";
  while(qa || qb) {
    int need = 0;
    if(!op) {
      need = min(qa, x);
      qa -= need;
    }
    else {
      need = min(qb, y);
      qb -= need;
    }
    if(need == 0) {
      if(!q[op].empty() && q[op].top() > 1) {
        int x = q[op].top(); q[op].pop();
        q[op].push(x - 1);
        q[op].push(1);
      }
      else {
        break;
      }
    }
    q[op].push(need);
    op ^= 1;
  }
  while(!q[st].empty()) {
    int x = q[st].top(); q[st].pop();
    for(int i = 0; i < x; ++i) sol.pb('a' + st);
    st ^= 1;
  }
  while(qa || qb) {
    int need = 0;
    if(!op) {
      need = min(qa, x);
      qa -= need;
    }
    else {
      need = min(qb, y);
      qb -= need;
    }
    if(need == 0) sol.pb('*');
    else for(int i = 0; i < need; ++i) sol.pb('a' + op);
    op ^= 1;
  }
  return sol;
}

inline void main2() {
  scanf(" %s", s);
  len = strlen(s);
  scanf("%d %d", &x, &y);
  int qa = 0, qb = 0;
  for(int i = 0; i < len; ++i) {
    qa += (s[i] == 'a');
    qb += (s[i] == 'b');
  }
  string solA = generate(qa, qb, 0);
  string solB = generate(qa, qb, 1);
  if(getScore(solA) <= getScore(solB)) printf("%s\n", solA.c_str());
  else printf("%s\n", solB.c_str());
}

int main() {
  int t; scanf("%d", &t);
  while(t--) main2();
  return 0;
}