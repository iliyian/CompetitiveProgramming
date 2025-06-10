#include <bits/stdc++.h>
#define int long long

void solve() {
  int u = 0;
  int mxS = 1 << 18;
  std::vector<int> vis(mxS);
  for (int i = 0; i < 18; i++) {
    char ch;
    std::cin >> ch;
    u ^= (ch == '1') << i;
  }
  int c[3] {};
  for (int i = 0; i < 3; i++) {
    for (int j = 1; j <= 6; j++) {
      c[i] ^= 1 << ((i + 1) * j - 1);
    }
  }
  int t = 0;
  for (int i = 9; i < 18; i++) {
    t ^= 1 << i;
  }
  std::vector<std::pair<char, char>> ans;
  auto dfs = [&](auto self, int u) -> void {
    if (u == t) {
      std::cout << ans.size() << '\n';
      for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i].first << ans[i].second;
        if (i != ans.size() - 1) {
          std::cout << '\n';
        }
      }
      return;
    }
    if (vis[u]) return;
    vis[u] = 1;
    for (int i = 0; i < 3; i++) {
      ans.push_back({'C', i + '1'});
      self(self, u ^ c[i]);
      ans.pop_back();
    }
    int v = u;
    
  };
  dfs(dfs, u);
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}