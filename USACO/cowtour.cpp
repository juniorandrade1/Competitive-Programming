/*
ID: juninho4
PROG: cowtour
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int n;
int field[155];
double diam[155];
double fielddiam[155];
double dist[155][155];
vector< pair<int,int> > pastures;

double distance_between(int a, int b) {
  return sqrt((pastures[a].first - pastures[b].first)*(pastures[a].first - pastures[b].first) + (pastures[a].second - pastures[b].second)*(pastures[a].second - pastures[b].second));
}

void belongs_to(int a, int fieldnum) {
  field[a] = fieldnum;

  for (int i = 0; i < n; i++) {
    if (dist[a][i] != 1e50 && field[i] == -1) {
      belongs_to(i, fieldnum);
    }
  }
}

int main() {
  int x, y;
  char c;

  ofstream fout("cowtour.out");
  ifstream fin("cowtour.in");

  fin >> n;

  for (int i = 0; i < n; i++) {
    fin >> x >> y;
    pastures.push_back(make_pair(x, y));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> c;
      if (i == j) {
        dist[i][j] = 0;
      } else if (c == '1') {
        dist[i][j] = distance_between(i, j);
      } else {
        dist[i][j] = 1e50;
      }
    }
  }

  // Floyd-Warshall
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  fill (field, field + 155, -1);

  int fieldnum = 0;
  for (int i = 0; i < n; i++) {
    if (field[i] == -1) {
      belongs_to(i, fieldnum);
      fieldnum++;
    }
  }

  fill (diam, diam + 155, 0);
  fill (fielddiam, fielddiam + 155, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (diam[i] < dist[i][j] && dist[i][j] != 1e50) {
        diam[i] = dist[i][j];
      }
    }
    if (diam[i] > fielddiam[field[i]])
      fielddiam[field[i]] = diam[i];
  }

  double result = 1e50;
  double tmp;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (field[i] == field[j])
        continue;

      tmp = diam[i] + diam[j] + distance_between(i, j);
      if (tmp < fielddiam[field[i]])
        tmp = fielddiam[field[i]];
      if (tmp < fielddiam[field[j]])
        tmp = fielddiam[field[j]];
      if (tmp < result)
        result = tmp;
    }
  }

  fout << setprecision(6) << setiosflags(ios::fixed|ios::showpoint) << result << endl;

  return 0;
}