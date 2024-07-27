// date: 2024-07-27 09:41:58
// tag: 二分，贪心

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  auto get = [&](int mid) -> std::pair<int, int> {
    int cnt = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] >= mid) {
        int t = (a[i] - mid) / b[i] + 1;
        cnt += t;
        sum += a[i] * t - t * (t - 1) / 2 * b[i];
      }
    }
    return {cnt, sum};
  };
  int l = 0, r = 1e9 + 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (get(mid).first <= k) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  auto [t, sum] = get(ans);
  if (ans > 0) {
    sum += (ans - 1) * (k - t); // for all is below ans,
  }
  std::cerr << '\n';
  std::cout << sum << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}