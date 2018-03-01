#include <bits/stdc++.h>

using namespace std;

const int DAY = 24 * 60 * 60;

const int GOOD_MORNING = 60 * 60 * 6;
const int GOOD_AFTERNOON = 60 * 60 * 12;
const int GOOD_NIGHT = 60 * 60 * 18;

int main() {
  double n;
  while(scanf("%lf", &n) != EOF) {
    n = fmod(n, 360);
    double seg = n * 240 + 60 * 60 * 6;
    while(seg >= DAY) seg -= DAY;
    if(seg < GOOD_MORNING) puts("Boa Madrugada!!");
    else if(seg < GOOD_AFTERNOON) puts("Bom Dia!!");
    else if(seg < GOOD_NIGHT) puts("Boa Tarde!!");
    else puts("Boa Noite!!");
    int hour = (seg / (60 * 60));
    seg -= (hour * 60 * 60);
    int minute = (seg / 60);
    int second = seg - minute * 60;
    printf("%02d:%02d:%02d\n", hour, minute, second);
  }
  return 0;
}