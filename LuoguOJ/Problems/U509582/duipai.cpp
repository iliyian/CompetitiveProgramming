#include <bits/stdc++.h>
#define int long long

std::vector<int> vec;
std::vector<std::vector<std::pair<int, int>>> g;

int n;

std::vector<int> cur;

void dfs(int u, int p) {
  if (!cur.empty()) {
    auto tmp = cur;
    std::sort(tmp.begin(), tmp.end());
    vec.push_back(tmp[(tmp.size() - 1) / 2]);
  }
  for (auto [v, w] : g[u]) {
    if (v != p) {
      cur.push_back(w);
      dfs(v, u);
      cur.pop_back();
    }
  }
}

signed main(signed argc, char **argv) {
  if (argc > 1) freopen(argv[1], "r", stdin);
  if (argc > 2) freopen(argv[2], "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> n;
  g.assign(n + 1, {});
  for (int i = 2; i <= n; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  for (int i = 1; i <= n; i++) {
    dfs(1, 0);
  }
  std::sort(vec.begin(), vec.end());
  std::cout << vec[(vec.size() - 1) / 2] << '\n';
  return 0;
}