#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdio>
#include <cstring>
#include <iostream>

#define WATCH(x) cout << #x << " = " << (x) << endl

using namespace std;

#define MAXN 10001

double proba[4][4][4][4];
int dice[6];
int aux[6];
const double inf = 1e10;

void update_proba(int a, int d, double p)
{
  for(int i = 0; i < a + d; ++i) aux[i] = dice[i];
  sort(&dice[0], &dice[a], std::greater<int>());
  sort(&dice[a], &dice[a+d], std::greater<int>());
  int la = 0; 
  int ld = 0;
  for (int i = 0; i < min(a, d); ++i) {
    if (dice[i] > dice[a+i]) 
      ld++;
    else
      la++;
  }
  for(int i = 0; i < a + d; ++i) dice[i] = aux[i];
  proba[a][d][la][ld] += p;
}

void roll(int a, int d, double p, int i=0)
{
  if (i == a + d) {
    update_proba(a, d, p);
  } else {
    for (int j = 1; j <= 6; ++j) {
      dice[i] = j;
      roll(a, d, p, i+1);
    }
  }
}

void preprocess()
{
  memset(proba, 0, sizeof proba);
  for (int a = 1; a <= 3; ++a) {
    for (int d = 1; d <= 3; ++d) {
      const double p = 1.0;
      roll(a, d, p);
    }
  }
  for (int a = 1; a <= 3; ++a) 
    for (int d = 1; d <= 3; ++d) 
      for (int i = 0; i <= 3; ++i) 
        for (int j = 0; j <= 3; ++j) 
          proba[a][d][i][j] /= pow(6.0, a + d);
}

double dp[4][MAXN];

double go(int ta, int td)
{
  for (int a = 0; a <= ta; ++a) {
    for (int d = 0; d <= td; ++d) {
      if (a == 0) {
        dp[a & 3][d] = 0.0;
      } else if (d == 0) {
        dp[a & 3][d] = 1.0;
      } else {
        const int da = min(a, 3);
        const int dd = min(d, 3);
        const int mk = min(da, dd);
        dp[a & 3][d] = 0.0;
        for (int k = 0; k <= mk; ++k)
          dp[a & 3][d] += proba[da][dd][k][mk-k] * dp[(a - k) & 3][d - (mk - k)];
      }
    }
  }
  return dp[ta & 3][td];
}

void solve()
{
  int ta = 0, td = 0;
  scanf("%d%d", &ta, &td);
  memset(dp, 0, sizeof dp);
  double sol = go(ta - 1, td);
  printf("%.4lf\n", sol);
}     

////////////////////////////////////////////////////////////////////////
//                    BEGIN INOUT GENERATION CODE
////////////////////////////////////////////////////////////////////////
void output_test(int a, int d, int & file_index)
{
  char name[1000];
  sprintf(name, "%d.in", file_index);
  FILE * file = fopen(name, "w");
  fprintf(file, "%d %d\n", a, d);
  printf("%d %d\n", a, d);
  fclose(file); 
}

void output_sol(double sol, int & file_index)
{
  char name[1000];
  sprintf(name, "%d.out", file_index);
  FILE * file = fopen(name, "w");
  fprintf(file, "%.4lf\n", sol);
  file_index++;
  fclose(file); 
}
 

void gen(int amin, int amax, int da, 
         int dmin, int dmax, int dd, 
         int & file_index,
         double eps = 1e-5)
{
  for (int a = amin; a <= amax; a += da) {
    for (int d = dmin; d <= dmax; d += dd) {
      double sol = go(a - 1, d);
      if (eps <= sol && sol <= (1 - eps)) {
        output_test(a, d, file_index);      
        output_sol(sol, file_index);      
      }
    }
  }
}

void gen_all()
{
  int file_index = 0;
  gen( 1,   5, 1,   1,   5, 1, file_index, 0.0);
  gen(10,  20, 4,  10,  20, 4, file_index);
  gen(80, 100, 4,  80, 100, 4, file_index);
  gen(1000, 10000, 1500, 1000, 10000, 1500, file_index);

  output_test(10000, 10000, file_index);
  output_sol(go(10000, 10000), file_index);
  printf("%d\n", file_index);
}
////////////////////////////////////////////////////////////////////////
//                    END INOUT GENERATION CODE
//////////////////////////////////////////////////////////////////////// 

int main()
{
  //preprocess();
  gen_all();
  solve();
}

