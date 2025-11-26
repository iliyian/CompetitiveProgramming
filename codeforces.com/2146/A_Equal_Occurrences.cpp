#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::map<int, int> cnt;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }
  std::vector<int> b;
  for (auto [k, v] : cnt) {
    b.push_back(v);
  }
  std::ranges::sort(b);
  int ans = 0;
  for (int i = 0; i < b.size(); i++) {
    ans = std::max<int>(ans, (b.size() - i) * b[i]);
  }
  std::cout << ans << '\n';
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