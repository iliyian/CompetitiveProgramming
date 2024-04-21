// date: 2024/02/12 16:00:23
// tag: wa#01: 忽略了结尾的情况，遍历完所有点后仍可以视为使用了一次k到达根节点
// wa#02: 上述情况只有真正的根节点有存在可能

#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    adj[x - 1].push_back(i);
  }
  vector<int> a;
  int ans = 2 * n - 2;
  auto dfs = [&](auto self, int x, int d) -> int {
    int l = 0;
    for (auto y : adj[x]) {
      int v = self(self, y, d + 1) + 1;
      if (v > l) {
        swap(v, l);
      }
      if (v > d) {
        // 对于最大的v之外的所有值
        a.push_back(v - d);
        // 节省从上向下走的，但加上从下向上走的
      }
    }
    return l;
  };
  a.push_back(dfs(dfs, 0, 0));
  sort(a.begin(), a.end(), greater());
  for (int i = 0; i < a.size() && i < k + 1; i++) { // 最后一趟有去无回
    ans -= a[i];
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }
  return 0;
}