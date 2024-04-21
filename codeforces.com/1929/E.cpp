// date: 2024/02/22 19:26:32
// tag: 所谓状态压缩，
// 只是为了方便对状态的构成进行二进制遍历罢了
// 状态的转移一律按位或

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y), adj[y].push_back(x);
  }
  vector<int> dep(n + 1), pa(n + 1);
  auto dfs = [&](auto self, int x, int p) -> void {
    dep[x] = dep[p] + 1;
    for (int y : adj[x]) {
      if (y == p) continue;
      pa[y] = x;
      self(self, y, x);
    }
  };
  dfs(dfs, 1, 0);

  int k;
  cin >> k;
  vector<int> sta(n + 1);
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    while (x != y) {
      if (dep[x] < dep[y]) swap(x, y);
      // 注意按位或
      sta[x] |= 1 << i;
      x = pa[x];
    }
  }
  vector<int> vec = sta;
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
  int len = vec.size();
  vector<int> dp(1 << k, 0x3f3f3f3f);
  dp[0] = 0;
  for (int S = 0; S < (1 << k); S++) {
    for (int j = 0; j < len; j++) {
      int T = S | vec[j];
      dp[T] = min(dp[T], dp[S] + 1);
    }
  }
  cout << dp[(1 << k) - 1] << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}