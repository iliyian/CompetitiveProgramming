#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), mx(n + 1);
  std::vector<int> mad(n + 1);
  int Mx = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    ans += a[i];
  }
  auto move = [&]() {
    std::vector<int> cnt(n + 1), mad(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      cnt[a[i]]++;
      if (cnt[a[i]] > 1) {
        mx = std::max(a[i], mad[i - 1]);
        mad[i] = mx;
      } else {
        mad[i] = mad[i - 1];
      }
    }
    for (int i = 1; i <= n; i++) {
      a[i] = mad[i];
    }
  };
  move();
  for (int i = 1; i <= n; i++) {
    ans += a[i];
  }
  move();
  for (int i = 1; i <= n; i++) {
    ans += a[i];
  }
  move();
  for (int i = 1; i <= n; i++) {
    ans += a[i];
  }
  move();
  std::vector<int> cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    cnt[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (!cnt[a[i]]) continue;
    ans += a[i] * (n - i + 1 - cnt[a[i]]) * cnt[a[i]] + cnt[a[i]] * (cnt[a[i]] + 1) / 2 * a[i];
    cnt[a[i]] = 0;
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}