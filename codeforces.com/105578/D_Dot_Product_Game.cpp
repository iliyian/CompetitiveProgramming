#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  auto calc = [&n](std::vector<int> &v) {
    std::vector<int> d(n + 1);
    auto add = [&](int x, int c) {for (int i = x; i <= n; i += i & -i) d[i] += c;};
    auto query = [&](int x) {int ans = 0; for (int i = x; i > 0; i -= i & -i) ans += d[i]; return ans;};
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += query(v[i] - 1);
      add(v[i], 1);
    }
    return ans % 2;
  };
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  int ans1 = calc(a), ans2 = calc(b);
  int ans = ans1 ^ ans2;
  std::cout << (ans ? "A" : "B");
  for (int i = 1; i <= n - 1; i++) {
    char ch;
    int l, r, d;
    std::cin >> ch >> l >> r >> d;
    if ((r - l + 1) % 2 == 0) {
      if (d % 2 == 1) {
        ans ^= 1;
      }
    }
    std::cout << (ans ? "A" : "B");
  }
  std::cout << '\n';
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