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
  std::vector<int> a(n + 1), c = {{}};
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    for (int j = 1; j <= a[i]; j++) {
      c.push_back(i);
    }
  }
  std::vector<std::vector<int>> b(n + 1, std::vector<int>(n + 1));
  std::priority_queue<Node> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      std::cin >> b[i][j];
    }
  }
  std::vector<int> pa(c.size());
  std::iota(pa.begin() + 1, pa.end(), 1);
  for (int i = 1; i < c.size(); i++) {
    for (int j = i; j < c.size(); j++) {
      q.push({i, j, b[c[i]][c[j]]});
    }
  }
  int cnt = 0, ans = 0;
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  while (!q.empty() && cnt < pa.size() - 2) {
    auto [l, r, w] = q.top(); q.pop();
    l = find(find, l), r = find(find, r);
    if (l != r) {
      ans += w;
      cnt++;
      pa[l] = r;
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