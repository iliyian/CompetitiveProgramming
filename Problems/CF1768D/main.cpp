// date: 2024-03-27 17:44:01
// tag: 思维，排列的排序的性质
// wa#01: 某些条件不是必要的，漏了步骤

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), nxt(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    nxt[i] = a[i];
  }
  vector<int> vis(n + 1);
  int id = 0, ans = 0;
  auto dfs = [&](auto self, auto u, int cnt) -> void {
    if (vis[u]) {
      ans += cnt - 1;
      return;
    }
    vis[u] = id;
    self(self, nxt[u], cnt + 1);
  };
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      ++id;
      dfs(dfs, i, 0);
    }
  }
  bool f = false;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == vis[i - 1]) {
      // 该环彻底复原前的上一步必然还有恰好一个逆序对
      f = true;
      break;
    }
  }
  if (f) {
    ans--;
  } else {
    ans++;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}