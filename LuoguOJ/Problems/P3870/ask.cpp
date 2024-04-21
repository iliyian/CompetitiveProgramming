#include<bits/stdc++.h>
using namespace std;
typedef int itn;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int INF = 0x3f3f3f3f;
const int mod = 100003;
const int MAX = 200005;

int sg[MAX * 4];//线段树数组
int lazy[MAX * 4];//懒标记
void newsum(int k) {
	sg[k] = sg[k << 1] + sg[k << 1 | 1];
}
int getmid(int l, int r) {
	return l + ((r - l) >> 1);
}
void newlazy(int k,int l,int r) {
	if (lazy[k]) {
		int mid = getmid(l, r);
		lazy[k << 1] = 1;
		lazy[k << 1 | 1] = 1;
		sg[k << 1 | 1] = r - mid - sg[k << 1 | 1];
		sg[k << 1] = mid - l + 1 - sg[k << 1];
		lazy[k] = 0;
	}
}
void update(int k, int L, int R, int l, int r) {
	if (L <= l && R >= r) {
		sg[k] = (r - l + 1) - sg[k];
		lazy[k] = 1;
	}
	else {
		newlazy(k,l,r);
		int mid = getmid(l , r);
		if (L <= mid)update(k << 1, L, R, l, mid);
		if (R > mid)update(k << 1 | 1, L, R, mid + 1, r);
		newsum(k);
	}
}
int query(int k, int L, int R, int l, int r) {
	if (L <= l && R >= r)return sg[k];
	else {
		newlazy(k, l, r);
		int mid = getmid(l, r);  
		int sum = 0;
		if (L <= mid)sum+=query(k << 1, L, R, l, mid);
		if (R > mid)sum+=query(k << 1|1, L, R, mid+1, r);
		return sum;
	}
}
void solve() {
	int n, m; cin >> n >> m;
	for (itn i = 1; i <= m; i++) {
		int op, x, y; cin >> op>>x>>y;
		if (op == 0)
			update(1, x, y, 1, n);
		else
			cout << query(1, x, y, 1, n) << endl;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  freopen("data.in", "r", stdin);
	//int t; cin >> t;
	//while (t--)   
	solve();

	return 0;
}