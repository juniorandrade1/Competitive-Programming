#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100010;
 
int n, c, v[N];
int pd[N][2];
int memorizado[N][2];
 
int func(int posicao, int peguei) {
  if(posicao == n) { //cheguei no fim do vetor, não tenho mais o que fazer
    return 0;
  }
  if(memorizado[posicao][peguei]) return pd[posicao][peguei]; //Já calculei
  //preciso calcular
  memorizado[posicao][peguei] = 1; //não pode esquecer de falar que calculou
  
  int resp = func(posicao + 1, peguei); //Ignora o cara da posição
 
  if(peguei == false) { //posso pegar essa posição
    resp = max(resp, func(posicao + 1, 1) - v[posicao] - c);
  }
  else { //to com um cara comprado, não posso comprar, mas posso vender
     resp = max(resp, func(posicao + 1, 0) + v[posicao]);
  }
  return pd[posicao][peguei] = resp;
}
 
int main() {
    scanf("%d %d", &n, &c);
    for(int i = 0; i < n; ++i) scanf("%d", v + i);
    printf("%d\n", func(0, 0));
}