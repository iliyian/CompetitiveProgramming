#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;
int d1[N + 1] {}, d2[N + 1] {}, d3[N + 1] {};

int query(int x, int *d) {
  x += (int)2e5 + 10;
  int ans = 0;
  for (int i = x; i > 0; i -= i & -i) ans += d[i];
  return ans;
}

void add(int x, int c, int *d) {
  x += (int)2e5 + 10;
  if (x == 0) return;
  for (int i = x; i <= N; i += i & -i) d[i] += c;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].second;
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first;
  }
  std::sort(a.begin() + 1, a.end(), std::greater<>());
  std::vector<std::pair<int, int>> b;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    auto [r, x] = a[i];
    b.push_back({x - r, x + r});
    // ans += i - 1 - query(x - r - 1, d2) - (i - 1 - query(x + r, d1));
    // add(x - r, 1, d1);
    // add(x + r, 1, d2);
  }
  std::sort(b.begin(), b.end());
  for (int i = 0; i < b.size(); i++) {
    auto [l, r] = b[i];
    ans += query(r, d3) - query(l - 1, d3);
    add(r, 1, d3);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}