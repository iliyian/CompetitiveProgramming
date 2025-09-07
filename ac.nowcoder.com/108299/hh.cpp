#include <bits/stdc++.h>
#include <random>
#define int long long

std::mt19937_64 rd(std::random_device{}());

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1), h(n + 1);
  std::vector<std::array<int, 4>> e;
  std::vector<int> dis1(n + 1, LLONG_MAX / 3), dis2(n + 1, LLONG_MAX / 3);
  for (int i = 1; i <= m; i++) {
    int x, y, t, w;
    std::cin >> x >> y >> t >> w;
    if (x == y) continue;
    g[x].push_back({y, t});
    h[y].push_back({x, t});
    e.push_back({t, w, x, y});
  }
  auto dijkstra = [](std::vector<std::vector<std::pair<int, int>>> &g,
                     std::vector<int> &dis, int s) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        q;
    q.push({dis[s] = 0, s});
    while (!q.empty()) {
      auto [d, u] = q.top();
      q.pop();
      if (dis[u] != d)
        continue;
      for (auto [v, w] : g[u]) {
        if (dis[v] > dis[u] + w) {
          q.push({dis[v] = dis[u] + w, v});
        }
      }
    }
  };
  dijkstra(g, dis1, 1);
  dijkstra(h, dis2, n);
  std::vector<std::pair<int, int>> v, vv;
  for (auto &[t, w, x, y] : e) {
    if (dis1[x] == LLONG_MAX / 3 || dis2[y] == LLONG_MAX / 3) continue;
    t += dis1[x] + dis2[y];
    v.push_back({-w, t});
  }
  // for (int i = 0; i < 1000; i++) {
  //   v.push_back({- (rd() % 100), rd() % 100});
  // }
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < v.size(); i++) {
    if (vv.empty() ||
        v[i].first > vv.back().first && v[i].second < vv.back().second) {
      vv.push_back(v[i]);
    }
  }
  v = vv;
  // for (auto [w, t] : v) {
  //   std::cerr << w << ' ' << t << '\n';
  // }
  int q;
  std::cin >> q;
  std::vector<std::array<int, 2>> ask(q);
  for (int i = 0; i < q; i++) {
    std::cin >> ask[i][0];
    ask[i][1] = i;
  }
  auto check = [&](int mid, int k) -> int {
    return v[mid].second + v[mid].first * k;
  };
  std::sort(ask.begin(), ask.end());
  std::vector<int> ans(q);
  int i = v.size() - 1;
  for (auto [k, id] : ask) {
    while (i > 0 && check(i, k) > check(i - 1, k)) {
      i--;
    }
    ans[id] = check(i, k);
  }
  for (int i = 0; i < q; i++) {
    std::cout << ans[i] << '\n';
  }
  std::cout << '\n';
  // while (q--) {
  //   int k;
  //   std::cin >> k;
  //   // int ans = LLONG_MAX / 3;
  //   // for (auto [w, t] : v) {
  //   //   ans = std::min(ans, t + w * k);
  //   // }
  //   // std::cout << ans << '\n';
  //   int l = 0, r = v.size() - 1;
  //   while (l < r) {
  //     int mid = (l + r) / 2;
  //     if (check(mid) < check(mid + 1))
  //       r = mid;
  //     else
  //       l = mid + 1;
  //   }
  //   std::cout << check(l) << '\n';
  // }
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