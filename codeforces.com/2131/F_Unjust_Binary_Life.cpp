#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string a, b;
  std::cin >> n >> a >> b;
  a = '#' + a, b = '#' + b;
  std::vector<int> va(n + 1), vb(n + 1);
  if (a[1] != b[1]) {
    va[1] = vb[1] = 1;
  }

  for (int i = 2; i <= n; i++) {
    va[i] = va[i - 1] + (a[i] != a[i - 1]);
  }

  for (int i = 1; i <= n; i++) {
    std::cerr << va[i] << ' ';
  }
  std::cerr << '\n';
  for (int i = 1; i <= n; i++) {
    std::cerr << vb[i] << ' ';
  }
  std::cerr << '\n';
  int ans = 0, s = 0;
  for (int i = 1; i <= n; i++) {
    s += va[i];
    vb[i] = vb[i - 1] + vb[i] * n;
  }
  ans = s;
  for (int i = 1; i <= n; i++) {
    s += vb[i];
    ans += s;
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