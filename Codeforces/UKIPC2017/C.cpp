#include <bits/stdc++.h>

using namespace std;

map< string, int > vals;

int main() {
  vals["red"] = 1;
  vals["yellow"] = 2;
  vals["green"] = 3;
  vals["brown"] = 4;
  vals["blue"] = 5;
  vals["pink"] = 6;
  vals["black"] = 7;
  char str[123];
  int n; scanf("%d", &n);
  int rd = 0;
  int mx = 0;
  int sum = 0;
  for(int i = 0; i < n; ++i) {
    scanf(" %s", str);
    if(vals[(string)str] == 1) rd++;
    mx = max(mx, vals[(string)str]);
    sum += vals[(string)str];
  }
  if(rd == n) puts("1");
  else printf("%d\n", sum + (mx * rd));
  return 0;
}