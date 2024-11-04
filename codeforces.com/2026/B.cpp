#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  auto check = [&](int mid) {
    bool f = true;
    for (int i = 1; i < n; i += 2) {
      if (a[i + 1] - a[i] > mid) {
        f = false;
        break;
      }
    }
    if (f) return true;
    if (n % 2 == 0) return false;
    f = true;
    for (int i = 1; i < n; i += 2) {
      if (a[i + 1] - a[i] > mid) {
        if (!f) return false;
        f = false;
        i--;
      }
    }
    return true;
  };
  int l = 1, r = 1e18 + 5, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}