// date: 2024/01/25 10:47:09
// tag: 分治法，单调栈判断溯及范围的坐标，
// 单调栈也只能用来放坐标，栈里是等待着外界传入答案的

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n + 1, vector<char>(m + 1));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> a[i][j];
  vector<int> l(m + 1), r(m + 1), h(m + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      h[j] = a[i][j] == '*' ? 0 : h[j] + 1;
    stack<int> ls, rs;
    for (int j = m; j >= 1; j--) {
      while (!ls.empty() && h[j] <= h[ls.top()])
        // 最远可以溯及的位置
        l[ls.top()] = j, ls.pop();
      ls.push(j);
    }
    while (!ls.empty()) l[ls.top()] = 0, ls.pop();
    
    for (int j = 1; j <= m; j++) {
      // 右边新来的可能立刻成为答案
      while (!rs.empty() && h[j] < h[rs.top()])
        r[rs.top()] = j, rs.pop();
      rs.push(j);
    }
    while (!rs.empty()) r[rs.top()] = m + 1, rs.pop();
    
    for (int j = 1; j <= m; j++)
      ans += (j - l[j]) * (r[j] - j) * h[j];
  }
  cout << ans;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}