#include <bits/stdc++.h>

using namespace std;

class UnfinishedTournamentEasy {
public:
	double maximal(vector <string>);
};

const int N = 21;

int qw[N], ql[N], qi[N];
double s[N];
int n;

bool notFill(vector< string > &G) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(G[i][j] == '?') return true;
		}
	}
	return false;
}

void process(vector< string > &G) {
	for(int i = 0; i < n; ++i) {
		qw[i] = ql[i] = qi[i] = 0;
		for(int j = 0; j < n; ++j) {
			if(G[i][j] == 'W') qw[i]++;
			else if(G[i][j] == 'L') ql[i]++;
		}
	}
	for(int i = 0; i < n; ++i) {
		qi[i] = n - qw[i] - ql[i] - 1;
	}
}	

bool cmp(int a, int b) {
	int ma = max(qw[a], ql[a]);
	int mb = max(qw[b], ql[b]);
	return ma >= mb;
}

double UnfinishedTournamentEasy::maximal(vector <string> G) {
	n = G.size();
	while(notFill(G)) {
		process(G);
		int arr[N];
		for(int i = 0; i < n; ++i) arr[i] = i;
		sort(arr, arr + n, cmp);	
		int a = arr[0];
		int ma = max(qw[a], ql[a]);
		if(qw[a] == ma) {
			for(int i = 0; i < n; ++i) if(G[a][i] == '?') G[a][i] = 'W';
		}
		else {
			for(int i = 0; i < n; ++i) if(G[a][i] == '?') G[a][i] = 'L';
		}
	}
	
	double calcCost = 0;
	process(G);
	for(int i = 0; i < n; ++i) calcCost += (double)(qw[i] - 0.5) * (double)(qw[i] - 0.5);
	calcCost /= (double)n;
	return calcCost;
}

int main() {
	vector< string > g;
	g.push_back("-??");
 	g.push_back("?-?");
 	g.push_back("??-");
}