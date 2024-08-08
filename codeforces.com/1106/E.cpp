// date: 2024-08-05 14:19:50
// tag: 

// 记忆缠绕我

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

struct Node {
  int s, t, d, w;
  bool operator < (const Node &b) const {
    return w != b.w ? w < b.w : d < b.d;
  }
};

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n, m, k;
  std::cin >> n >> m >> k;
  std::priority_queue<Node> q;
  std::vector<Node> a(k + 1);
  for (int i = 1; i <= k; i++) {
    std::cin >> a[i].s >> a[i].t >> a[i].d >> a[i].w;
  }
  std::sort(a.begin() + 1, a.end(), [&](const Node &x, const Node &y) {
    return x.s < y.s;
  });
  int cur = 1;
  std::vector<int> g(n + 1), h(n + 1);
  for (int i = 1; i <= n; i++) {
    while (cur <= k && a[cur].s <= i) {
      q.push(a[cur++]);
    }
    if (q.empty()) {
      g[i] = i + 1;
    } else {
      auto [s, t, d, w] = q.top();
      if (t < i) {
        --i;
        q.pop();
        continue;
      }
      g[i] = d + 1;
      h[i] = w;
    }
  }
  std::vector<std::vector<int>> f(n + 2, std::vector<int>(m + 2, inf));
  f[1][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      f[i + 1][j + 1] = std::min(f[i + 1][j + 1], f[i][j]);
      f[g[i]][j] = std::min(f[g[i]][j], f[i][j] + h[i]);
    }
  }
  int ans = inf;
  for (int i = 0; i <= m; i++) {
    ans = std::min(ans, f[n + 1][i]);
  }
  std::cout << ans << '\n';

  return 0;
}