// date: 2024-07-30 10:47:38
// tag: 模拟

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
// using namespace std;

struct Node {
  int x, y, id;
};

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<Node> a(k + 1);
  for (int i = 1; i <= k; i++) {
    std::cin >> a[i].x >> a[i].y;
    a[i].id = i;
  }
  auto cmpx = [&](const Node &x, const Node &y) {
    return std::tie(x.x, x.y) < std::tie(y.x, y.y);
  };
  std::sort(a.begin() + 1, a.end(), cmpx);
  std::vector<int> mny(k + 2);
  mny[k + 1] = inf;
  for (int i = k; i >= 1; i--) {
    mny[i] = std::min(mny[i + 1], a[i].y);
  }
  std::vector<int> ans(k + 1);
  int px = 0, py = 1;
  int sum = 0;
  bool f = false;
  for (int i = 1; i <= k; i++) {
    if (a[i].x > a[i - 1].x && mny[i + 1] > a[i].y) {
      ans[a[i].id] = true;
      sum += (a[i].y - py) * (n - px);
      px = a[i].x, py = a[i].y;
      if (a[i].y == 1) {
        f = true;
      }
    }
  }
  sum += (m - py + 1) * (n - px);
  // sum += !f;
  std::cout << sum << '\n';
  for (int i = 1; i <= k; i++) {
    std::cout << ans[i] << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F1.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}