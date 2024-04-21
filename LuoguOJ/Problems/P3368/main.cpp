// date: 2023/11/15
// tag: 线段树模板
// 一遍AC
// tip: 单点查询，不需要在开始建树

#include <bits/stdc++.h>
#define N 500005
using namespace std;

int a[N], t[N], d[N], n, m;

int lowbit(int x) {return x & -x;}

void add(int x, int c) {
  for (int i = x; i <= n; i += lowbit(i))
    t[i] += c;
}

int query(int x) {
  int res = 0;
  for (int i = x; i > 0; i -= lowbit(i))
    res += t[i];
  return res;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    // cin >> a[i], add(i, a[i]), add(i + 1, -a[i]);
    cin >> a[i];

  for (int i = 0; i < m; i++) {
    int op, x, y, k;
    cin >> op >> x;
    if (op == 1) {
      cin >> y >> k;
      add(x, k);
      add(y + 1, -k);
    // } else cout << query(x) << '\n';
    } else cout << query(x) + a[x] << '\n';
  }
}