#include <bits/stdc++.h>
#define int long long

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  
  int n, x;
  std::cin >> n >> x;
  n--;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  auto check = [&](int mid) {
    int sum = 0, r = 1;
    while (r <= mid) sum += a[r++];
    int l = 1;
    while (r <= n) {
      if (sum < x * 2) return false;
      sum += a[r++];
      sum -= a[l++];
    }
    if (sum < x * 2) return false;
    return true;
  };

  int l = 1, r = n, ans = n + 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  std::cout << ans << '\n';

  return 0;
}