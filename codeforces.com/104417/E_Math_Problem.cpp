#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k, m, a, b, tm;
  std::cin >> n >> k >> m >> a >> b;
  tm = m;
  if (n % m == 0) {
    std::cout << 0 << '\n';
    return;
  }
  if (k == 1) {
    std::cout << -1 << '\n';
    return;
  }
  std::vector<int> vn, vm;
  while (n) {
    vn.push_back(n % k);
    n /= k;
  }
  while (tm) {
    vm.push_back(tm % k);
    tm /= k;
  }
  int ans = INT_MAX;
  for (int L = vn.size() - 1; L >= 0; L--) { // 除法次数
    __int128 l = 0, r = 0;
    for (int i = vn.size() - 1; i >= L; i--) {
      l = l * k + vn[i];
      r = r * k + vn[i];
    }
    // std::cerr << "L: " << L << ' ';
    // std::cerr << l << ' ' << r << '\n';
    int t = 0;
    while (l < m) {
      l *= k;
      r = r * k + k - 1;
      t++;
    }
    // std::cerr << "L: " << L << ' ';
    // std::cerr << l << ' ' << r << ' ' << t << '\n';
    if (l / m != r / m) { // 存在倍数
      ans = std::min(ans, t * a + L * b);
    }
    if (l * k / m != (r * k + k - 1) / m) { // 存在倍数
      ans = std::min(ans, (t + 1) * a + L * b);
    }
    if (l * k * k / m != ((r * k + k - 1) * k + k - 1) / m) { // 存在倍数
      ans = std::min(ans, (t + 2) * a + L * b);
    }
  }
  ans = std::min<int>(ans, vn.size() * b);
  // std::cerr << '\n';
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}