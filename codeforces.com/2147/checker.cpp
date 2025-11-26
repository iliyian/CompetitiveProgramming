#include <bits/stdc++.h>
#define int long long

void solve() {
  int n = (int)1e5, m = 15000;
  std::set<int> s;
  std::vector<int> a(n + 1);
  int lim = 1000000000000000000ll;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] > lim || a[i] < -lim) {
      std::cout << "OUT OF RANGE\n";
      return;
    }
    s.insert(a[i]);
  }
  if (s.size() > m) {
    std::cout << "TOO MANY\n";
    std::cout << s.size() << '\n';
    return;
  }
  for (int i = 2; i <= n - 1; i++) {
    if (std::abs(a[i] - a[i - 1]) >= std::abs(a[i] - a[i + 1])) {
      std::cout << "BAD" << '\n';
      std::cout << i - 1 << ' ' << i << ' ' << i + 1 << '\n';
      std::cout << a[i - 1] << ' ' << a[i] << ' ' << a[i + 1] << '\n';
      return;
    }
  }
  std::cout << "ACCETPED\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}