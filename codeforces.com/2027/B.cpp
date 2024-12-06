#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<int> vec = {INT_MIN};
  auto id = [&](int x) -> int {
    return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin();
  };
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    vec.push_back(a[i]);
  }
  std::sort(vec.begin(), vec.end());
  int len = vec.size() - 1;
  std::vector<int> d(len + 1);
  auto add = [&](int x) {for (int i = x; i <= len; i += i & -i) d[i]++;};
  auto query = [&](int x) {int ans = 0; for (int i = x; i > 0; i -= i & -i) ans += d[i]; return ans;};
  int ans = INT_MAX;
  for (int i = n; i >= 1; i--) {
    ans = std::min(ans, i - 1 + n - i - query(id(a[i])));
    add(id(a[i]));
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}