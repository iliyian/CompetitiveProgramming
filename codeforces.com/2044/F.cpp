// date: 2024-12-16 22:18:10
// tag: 神奇卡常题

#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e5;

std::vector<int> fac[N + 1];

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<int> a(n + 1), b(m + 1);
  int suma = 0, sumb = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    suma += a[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
    sumb += b[i];
  }
  std::set<int> sa, sb;
  for (int i = 1; i <= n; i++) {
    sa.insert(suma - a[i]);
  }
  for (int i = 1; i <= m; i++) {
    sb.insert(sumb - b[i]);
  }
  auto check = [&](int x, int y) {
    return sa.count(x) && sb.count(y) || sa.count(y) && sb.count(x);
  };
  std::map<int, bool> mp;
  while (q--) {
    int x;
    std::cin >> x;
    if (mp.count(x)) {
      std::cout << (mp[x] ? "YES" : "NO") << '\n';
      continue;
    }
    if (x == 0) {
      if (sa.count(0) || sb.count(0)) {
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
      continue;
    }
    bool f = false;
    for (int &i : fac[std::abs(x)]) {
      if (i * i > std::abs(x)) break;
      if (check(i, x / i) || check(-i, -x / i)) {
        std::cout << "YES\n";
        f = true;
        mp[x] = 1;
        break;
      }
    }
    if (!f) {
      std::cout << "NO\n";
      mp[x] = 0;
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      fac[j].push_back(i);
    }
  }
  // int mx = 0;
  // for (auto &i : fac) {
  //   mx = std::max<int>(mx, i.size());
  // }
  // std::cout << mx << '\n';

  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}