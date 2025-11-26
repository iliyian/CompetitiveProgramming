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
  int l = pos[n], r = pos[n];
  for (int i = n - 1; i >= 1; i--) {
    if (pos[i] != r + 1 && pos[i] != l - 1) {
      std::cout << "NO\n";
      return;
    }
    l = std::min(l, pos[i]);
    r = std::max(r, pos[i]);
  }
  std::cout << "YES\n";
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