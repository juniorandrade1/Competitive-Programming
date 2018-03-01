#include <bits/stdc++.h>

using namespace std;

const int N = 251;

vector< int > g[N];
int n, m;
int vis[N], match[N];

int dfs(int x) {
	if(vis[x]) return 0;
	vis[x] = 1;
	for(int i = 0; i < g[x].size(); ++i) {
		int y = g[x][i];
		if(match[y] == -1 || dfs(match[y])) {
			match[y] = x;
			return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i) {
		int x;
		while(scanf("%d", &x) && x != 0) g[i].push_back(x - 1);
	}
	memset(match, -1, sizeof match);
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		memset(vis, 0, sizeof vis);
		ans += dfs(i);
	}
	printf("%d\n", ans);
	vector< pair< int, int > > sol;
	for(int i = 0; i < m; ++i) {
		if(match[i] == -1) continue;
		sol.push_back(make_pair(match[i], i));
	}
	sort(sol.begin(), sol.end());
	for(int i = 0; i < ans; ++i) {
		printf("%d %d\n", sol[i].first + 1, sol[i].second + 1);
	}
	return 0;
}