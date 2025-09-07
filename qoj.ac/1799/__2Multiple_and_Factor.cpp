#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> fac(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i) {
      fac[j].push_back(i);
    }
  }
  int B = 3;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> val(B + 1);
  while (m--) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int x, k;
      std::cin >> x >> k;
      if (x > B) {
        for (int i = 1; i * x <= n; i++) {
          a[x * i] += k;
        }
      } else {
        val[x] += k;
      }
    } else if (op == 2) {
      int x, k;
      std::cin >> x >> k;
      for (int y : fac[x]) {
        a[y] += k;
      }
    } else if (op == 3) {
      int x;
      std::cin >> x;

      std::cout << ans << '\n';
    } else {
      int x;
      std::cin >> x;
      int ans = 0;
      for (int y : fac[x]) {
        if (y <= B) {
          ans += fac[x / y].size() * val[y];
        }
        ans += a[y];
      }
      std::cout << ans << '\n';
    }
    for (int i = 1; i <= n; i++) {
      std::cerr << a[i] << ' ';
    }
    std::cerr << '\n';
    for (int i = 1; i <= B; i++) {
      std::cerr << val[i] << ' ';
    }
    std::cerr << '\n';
  }
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