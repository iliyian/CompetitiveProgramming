#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e5;

void solve() {
  int n, y;
  std::cin >> n >> y;
  std::vector<int> a(n + 1), cnt(N + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }
  for (int i = 1; i <= N; i++) {
    cnt[i] += cnt[i - 1];
  }
  int ans = LLONG_MIN / 3;
  for (int x = 2; x <= N; x++) {
    int sum = - n * y;
    for (int i = 1; (i - 1) * x + 1 <= N; i++) {
      int l = (i - 1) * x + 1, r = std::min(N, i * x);
      sum += (cnt[r] - cnt[l - 1]) * i;
      sum += std::min(cnt[i] - cnt[i - 1], cnt[r] - cnt[l - 1]) * y;
      // if (x != 2) {
      //   std::cerr << l << ' ' << r << '\n';
      // }
    }
    ans = std::max(ans, sum);
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