#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  auto check = [&](int mid) -> bool {
    int prv = -1;
    for (int i = 1; i <= n; i++) {
      if (a[i] < mid) {
        if (prv != -1 && a[i] < prv) return false;
        prv = a[i];
      }
    }
    return true;
  };
  int l = 1, r = 1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) ans = mid, l = mid + 1;
    else r = mid - 1;
  }
  std::cout << ans << '\n';
  std::sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] + (a[i] >= ans) << ' ';
  }
  std::cout << '\n';
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
