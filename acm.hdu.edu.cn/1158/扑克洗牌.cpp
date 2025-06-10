#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    pos[a[i]] = i;
  }
  int ans = n - 1, len = 1;
  for (int i = 2; i <= n + 1; i++) {
    if (i != n + 1 && pos[i] > pos[i - 1]) {
      len++;
    } else {
      ans = std::min(ans, n - len);
      len = 1;
    }
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