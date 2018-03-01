#include <bits/stdc++.h>

using namespace std;

const int N = 300030;

typedef long long ll;

const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

struct node {
	ll val, idx;
	node(){
		val = -LINF;
		idx = -LINF;
	};
	node(ll _val, ll _idx) {
		val = _val;
		idx = _idx;
	}
	bool operator < (node other) {
		if(val != other.val) return val > other.val;
		else return idx < other.idx;
	}
};

node tr[4 * N];

node join(node a, node b) {
	if(a < b) return a;
	else return b;
}

void update(int no, int l, int r, int i, node v) {
	if(l == r) {
		tr[no] = v;
		return;
	}
	int nxt = (no << 1), mid = (l + r) >> 1;
	if(i <= mid) update(nxt, l, mid, i, v);
	else update(nxt + 1, mid + 1, r, i, v);
	tr[no] = join(tr[nxt], tr[nxt + 1]);
}

node query(int no, int l, int r, int i, int j) {
	if(r < i || l > j) return node();
	if(l >= i && r <= j) return tr[no];
	int nxt = (no << 1), mid = (l + r) >> 1;
	return join(query(nxt, l, mid, i, j), query(nxt + 1, mid + 1, r, i, j));
}

int n;
node all[N];
int used[N];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		node foo = node(x, i);
		update(1, 0, n - 1, i, foo);
		all[i] = foo;
	}
	sort(all, all + n);
	reverse(all, all + n);
	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		if(used[all[i].idx]) continue;
		int id = all[i].idx;
		if(id == n - 1) continue;
		node sol = query(1, 0, n - 1, id + 1, n - 1);
		if(sol.val == -LINF) continue;
		ans += all[i].val - sol.val;
		used[all[i].idx] = used[sol.idx] = 1;
		update(1, 0, n - 1, all[i].idx, node());
		update(1, 0, n - 1, sol.idx, node());
	}
	printf("%lld\n", ans);
	return 0;
}