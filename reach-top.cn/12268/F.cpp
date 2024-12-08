#include <bits/stdc++.h>
#define int long long

int calc(int x) {
  int ans = 0;
  while (x) ans += x % 10, x /= 10;
  return ans;
}

struct Node {
  std::string id;
  int y, s, sum;
  bool operator < (const Node &b) const {
    return std::tie(b.sum, b.s, b.id) < std::tie(sum, s, id);
  }
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<Node> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].id >> a[i].y >> a[i].s >> a[i].sum;
  }
  std::sort(a.begin(), a.end());
  for (auto x : a) {
    std::cout << x.id << ' '
      << std::setw(3) << std::setfill('0') << x.y << ' '
      << std::setw(3) << std::setfill('0') << x.s << ' '
      << std::setw(3) << std::setfill('0') << x.sum << '\n';
  }
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