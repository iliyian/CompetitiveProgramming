// 树状数组与树上差分模板题
// wa#01: 不开long long见祖宗
// wa#02: 查询由大至小，修改由小至大
// tle#03: memset超时??不确定，改成fill_n
// wa#04: l[i]==i不一定成立???
// wa#05: 树状数组单点差分修改首尾倒置???

#include <bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;

int c[N], l[N], r[N];
int sz, id;

int lowbit(int x) {return x & -x;}
int query(int x) {
	int res = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		res += c[i];
	return res;
}
void add(int x, int k) {
	for (int i = x; i <= sz; i += lowbit(i))
		c[i] += k;
}

struct Op {
	int op, u, w;
};
vector<Op> ops;
vector<int> g[N];

void build(int u) {
	l[u] = ++id;
	for (auto v : g[u])
		build(v);
	r[u] = id;
}

void solve() {
	int q;
	cin >> q;

	fill_n(c, sz + 1, 0);
	fill_n(l, sz + 1, 0);
	fill_n(r, sz + 1, 0);
	sz = 1, id = 0;

	while (q--) {
		int op, u, w;
		cin >> op >> u;
		if (op == 1) {
			sz++;
			g[u].push_back(sz);
			ops.push_back({op, sz, 0});
		} else {
			cin >> w;
			ops.push_back({op, u, w});
		}
	}
	build(1);
	for (auto &[op, u, w] : ops) {
		if (op == 1) {
			int res = query(l[u]);
			// 我还是搞不懂这一步
			add(l[u], -res), add(r[u] + 1, res);
		} else {
			add(l[u], w), add(r[u] + 1, -w);
		}
	}

	for (int i = 1; i <= sz; i++) {
		cout << query(i[l]) << ' ';
		g[i].clear();
	}
	ops.clear();
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("data.in", "r", stdin);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}