#include <bits/stdc++.h>
#include <regex>
#define int long long
using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::pair<int, int>> a(n + 1);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].second;
    mx = std::max(mx, a[i].second);
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first;
  }
  std::sort(a.begin() + 1, a.end());
  int sum = k;

  auto check = [&](int mid, int p) -> int {
    return (k + k - (mid - 1) * p) * mid / 2;
  };

  for (int i = 1; i <= n; i++) {
    auto &[p, h] = a[i];
    if (sum >= h) continue;
    k -= p;
    if (k <= 0) break;

    int l = 1, r = k / p + 1, ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid, p) + sum >= h) r = mid - 1, ans = mid;
      else l = mid + 1;
    }
    int t = check(ans, p);
    sum += t;
    k -= (ans - 1) * p;
  }
  std::cout << (sum >= mx ? "YES" : "NO") << '\n';
}

signed main() {
  freopen("I.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}