#include <bits/stdc++.h>

using namespace std;

int n, k;
bool memo[401][401];
long double pd[401][401]; //k, up, down

long double func(int qtd, int cnt) {
	if(cnt == 0) return qtd;
	if(memo[qtd][cnt]) return pd[qtd][cnt];
	long double ret = 0;
	memo[qtd][cnt] = 1;
	if(qtd == 0) {
		ret = (func(qtd + 1, cnt - 1) + func(qtd, cnt - 1)) * 0.5;
	}
	else if(qtd == n) {
		ret = (func(qtd - 1, cnt - 1) + func(qtd, cnt - 1)) * 0.5;
	}
	else {
		ret = max((func(qtd - 1, cnt - 1) + func(qtd, cnt - 1)) * 0.5, (func(qtd + 1, cnt - 1) + func(qtd, cnt - 1)) * 0.5);
	}
	return pd[qtd][cnt] = ret;
}

int main() {
	scanf("%d %d", &n, &k);
	printf("%.10lf\n", (double)func(0, k));
	return 0;
}