#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  std::vector<std::vector<int>> mx(21, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mx[0][i] = a[i];
  }
  auto querymx = [&](int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::max(mx[len][l], mx[len][r - (1 << len) + 1]);
  };
  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j + (1 << (i - 1)) <= n; j++) {
      mx[i][j] = std::max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = 1, r = i - 1, _ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (querymx(mid, i - 1) >= std::max(a[i], b[i])) l = mid + 1, _ans = mid;
      else r = mid - 1;
    }
    // std::cerr << i << ' ' << _ans << '\n';
    if (a[i] == b[i]) {
      ans += i * (n - i + 1);
    } else if (_ans != -1) {
      ans += _ans * (n - i + 1);
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