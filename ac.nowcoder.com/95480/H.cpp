#include <bits/stdc++.h>
#define int long long

int a[101][10001];
std::vector<std::vector<int>> g[101];
int f[101][10001];

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

int n;

std::set<std::pair<int, int>> s;

int dfs(int u, int t) {
  if (g[t][u].empty() && t == n) return a[t][u];
  if (g[t][u].empty()) {
    return a[t][u] - dfs(1, t + 1);
  }
  if (f[t][u] != -inf) return f[t][u];
  int mx = -inf;
  for (int v : g[t][u]) {
    mx = std::max(mx, dfs(v, t));
  }
  return f[t][u] = a[t][u] - mx;
};

void solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int s;
    std::cin >> s;
    g[i].assign(s + 1, {});
    for (int j = 2; j <= s; j++) {
      int x;
      std::cin >> x;
      g[i][x].push_back(j);
    }
    for (int j = 1; j <= s; j++) {
      f[i][j] = -inf;
      std::cin >> a[i][j];
    }
  }
  int ans = dfs(1, 1);
  std::cout << (ans == 0 ? "Draw" : ans > 0 ? "tryandtryagain win" : "Arcaea win") << '\n';
  // std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}