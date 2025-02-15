#include <bits/stdc++.h>
#define int long long

constexpr int M = 1e5;

void solve() {
  int g;
  std::cin >> g;
  std::vector<int> t(g + 1), u(g + 1);
  for (int i = 1; i <= g; i++) {
    std::cin >> t[i] >> u[i];
  }
  int n;
  std::cin >> n;
  std::map<int, std::set<std::pair<int, int>>> mp;
  std::vector<std::vector<std::pair<int, int>>> G(M + 1);
  std::vector<int> in(M + 1);
  for (int i = 1; i <= n; i++) {
    int m, k;
    std::cin >> m;
    for (int j = 1; j <= m; j++) {
      int x, y;
      std::cin >> x >> y;
      mp[x].insert({y, i});
      in[i]++;
    }
    std::cin >> k;
    for (int j = 1; j <= k; j++) {
      int x, y;
      std::cin >> x >> y;
      G[i].push_back({y, x});
    }
  }
  std::map<int, int> cnt;
  std::queue<int> q;
  auto check = [&](int x) {
    auto &mpt = mp[x];
    while (!mpt.empty()) {
      auto [y, id] = *mpt.begin();
      if (y <= cnt[x]) {
        if (!--in[id]) {
          q.push(id);
        }
        mpt.erase(mpt.begin());
      } else {
        break;
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    // std::cout << in[i] << " \n"[i == n];
    if (!in[i]) {
      q.push(i);
    }
  }
  std::vector<int> vis(n + 1);
  for (int i = 1; i <= g; i++) {
    cnt[t[i]] += u[i];
    check(t[i]);
  }
  int ans = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    ans++;
    // std::cout << u << '\n';
    for (auto [y, x] : G[u]) {
      cnt[x] += y;
      check(x);
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}