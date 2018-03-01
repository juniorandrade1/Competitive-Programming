#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
using namespace std;
typedef long double ld;

struct vec2{
  ld x,y;

  bool operator<(vec2 const &a)const{return x!=a.x? x<a.x: y<a.y;}
  vec2 operator-(vec2 const &a)const{return {x-a.x,y-a.y};}
  ld cross(vec2 const &a)const{return y*a.x-x*a.y;}

  ld dist(vec2 const &a,vec2 const &b)const{
    ld const u=fabsl(x*(b.y-a.y)-y*(b.x-a.x)+a.cross(b));
    ld const l=hypotl(a.x-b.x,a.y-b.y);
    return u/l;
  }
};

int main(){
  int n; cin>>n;
  vector<vec2> v(n); for (auto &i: v) cin>>i.x>>i.y;
  sort(v.begin(),v.end());

  vector<vec2> h1,h2;
  for (int i=0; i<v.size(); i++){
    while (h1.size()>=2 and (v[i]-h1[h1.size()-1]).cross(v[i]-h1[h1.size()-2])<=0) h1.pop_back();
    h1.push_back(v[i]);
  }
  for (int i=v.size(); i--;){
    while (h2.size()>=2 and (v[i]-h2[h2.size()-1]).cross(v[i]-h2[h2.size()-2])<=0) h2.pop_back();
    h2.push_back(v[i]);
  }
  copy(h2.begin()+1,h2.end()-1,back_inserter(h1));
  printf("%d\n", (int)h1.size());
  ld res=1e30L;
  for (int i=0,j=h1.size()-1; i<h1.size(); j=i++){
    ld dist=0L;
    for (auto const &k: h1) dist=max(dist,k.dist(h1[i],h1[j]));
    res=min(res,dist);
  }
  cout.precision(10);
  cout<<res<<endl;
}