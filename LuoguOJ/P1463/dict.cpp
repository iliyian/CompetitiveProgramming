#include <bits/stdc++.h>
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.out", "w", stdout);

  const int N = 1e7;
  std::vector<int> d(N + 1), num(N + 1), vis(N + 1), pri, low(N + 1, -1);
  d[1] = 1;
  int tot = -1;
  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
      d[i] = 2;
      num[i] = 1;
      low[i] = ++tot;
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      low[i * p] = tot;
      if (i % p == 0) {
        num[i * p] = num[i] + 1;
        d[i * p] = d[i] / num[i * p] * (num[i * p] + 1);
        break;
      }
      num[i * p] = 1;
      d[i * p] = d[i] * 2;
    }
  }
  std::vector<std::pair<int, int>> pre;
  for (int i = 1; i <= N; i++) {
    if (d[i] > d[i - 1]) {
      pre.push_back({i, d[i]});
      // std::cout << i << ' ' << d[i] << '\n';
    }
    d[i] = std::max(d[i - 1], d[i]);
  }
  num.clear();
  vis.clear();

  auto get = [&](int x) {
    int cnt = 0;
    for (int i = 1; i * i <= x; i++) {
      if (x % i == 0) {
        cnt += (i * i == x ? 1 : 2);
      }
    }
    return cnt;
  };

  // int inc = 12252240;
  int inc = 720720;
  for (int i = pre.back().first; i <= 2.1e9; i += inc) {
    auto x = get(i);
    if (x > pre.back().second) {
      pre.push_back({i, x});
    }
  }
  for (auto [x, y] : pre) {
    std::cout << x << ", ";
  }

  return 0;
}