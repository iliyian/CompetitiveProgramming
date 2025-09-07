#include <bits/stdc++.h>
#define int long long

int a[10][7] = {
  {1, 1, 1, 0, 1, 1, 1},
  {0, 0, 0, 0, 0, 1, 1},
  {0, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 1},
  {1, 0, 0, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 0, 1},
  {1, 1, 1, 1, 1, 0, 1},
  {0, 0, 1, 0, 0, 1, 1},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 0, 1, 1, 1, 1, 1}
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  int val[10] {};
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 7; j++) {
      if (a[i][j]) {
        val[i] |= 1 << j;
      }
    }
  }
  std::vector<std::string> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  auto dfs = [&](auto self, int u, std::vector<int> &prv) -> void {

  }
  int ans = 7;
  for (int s = 0; s < (1 << 7); s++) {
    std::set<int> st;
    for (int i = 1; i <= n; i++) {
      int t = 0;
      for (int k = 0; k < m; k++) {
        int x = a[i][k] - '0';
        x = val[x] & s;
        t |= x;
        t <<= 7;
      }
      st.insert(t);
    }
    if (st.size() == n) {
      ans = std::min<int>(ans, __builtin_popcountll(s));
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}