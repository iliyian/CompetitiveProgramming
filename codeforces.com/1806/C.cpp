// date: 2024-07-09 19:45:08
// tag: 构造，数学

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n * 2 + 1);
  for (int i = 1; i <= n * 2; i++) {
    std::cin >> a[i];
  }
  if (n == 1) {
    std::cout << abs(a[1] - a[2]) << '\n';
    return;
  }
  int ans = inf;
  if (n == 2) {
    int cur = 0;
    for (int i = 1; i <= n * 2; i++) {
      cur += abs(2 - a[i]);
    }
    ans = std::min(ans, cur);
    cur = 0;
  }
  int cur = 0;
  for (int i = 1; i <= n * 2; i++) {
    cur += abs(a[i]);
  }
  ans = std::min(ans, cur);
  if (n & 1 ^ 1) {
    cur = 0;
    for (int i = 1; i <= n * 2; i++) {
      cur += abs(a[i] + 1);
    }
    for (int i = 1; i <= n * 2; i++) {
      ans = std::min(ans, cur - abs(a[i] + 1) + abs(a[i] - n));
    }
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