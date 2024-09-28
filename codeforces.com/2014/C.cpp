#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }
  std::sort(a.begin() + 1, a.end());
  auto check = [&](int mid) -> bool {
    double avg = double(sum + mid) / n / 2.0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt += (a[i] + (i == n ? mid : 0) < avg);
    }
    return cnt > n / 2;
  };
  int l = 0, r = 0x3f3f3f3f3f3f3f3f;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else l = mid + 1;
  }
  if (check(l)) {
    std::cout << l << '\n';
  } else {
    std::cout << -1 << '\n';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("C.in", "r", stdin);

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}