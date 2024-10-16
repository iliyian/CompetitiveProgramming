#include <bits/stdc++.h>
#define int long long

struct Node {
  int l, r, w;
  bool operator < (const Node &b) const {
    return w > b.w;
  }
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }
  std::vector<std::vector<int>> b(n + 1, std::vector<int>(n + 1));
  std::priority_queue<Node> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> b[i][j];
      if (i <= j) {
        q.push({i, j, b[i][j]});
      }
    }
  }
  int cnt = 0, ans = 0;
  std::vector<int> pa(n + 1), siz(n + 1, 1);
  std::iota(pa.begin() + 1, pa.end(), 1);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) -> void {
    x = find(find, x), y = find(find, y);
    if (x == y) return;
    if (siz[x] > siz[y]) std::swap(x, y);
    pa[x] = y;
    siz[y] += siz[x];
  };
  while (!q.empty() && cnt < sum - 1) {
    auto [l, r, w] = q.top(); q.pop();
    if (l == r) {
      cnt += a[l] - 1;
      ans += (a[l] - 1) * w;
      a[l] = 1;
      continue;
    }
    l = find(find, l), r = find(find, r);
    if (l != r) {
      int co = std::min(sum - 1 - cnt, a[l] + a[r] - 1);
      a[l] = a[r] = 1;
      merge(l, r);
      ans += co * w;
      cnt += co;
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("J.in", "r", stdin);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}