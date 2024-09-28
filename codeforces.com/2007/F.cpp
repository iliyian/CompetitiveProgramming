#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  std::vector<std::vector<int>> st(21, std::vector<int>(n + 1));
  auto query = [&](int l, int r) -> int {
    int len = std::__lg(r - l + 1);
    return std::gcd(st[len][l], st[len][r - (1 << len) + 1]);
  };
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    st[0][i] = std::abs(a[i + 1] - a[i]);
  }
  n--;
  for (int i = 1; i <= 20; i++) {
    for (int j = n - (1 << (i - 1)); j >= 1; j--) {
      st[i][j] = std::gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }
  std::vector<int> lsteq(n + 1);
  lsteq[n] = n;
  for (int i = n - 1; i >= 1; i--) {
    lsteq[i] = (a[i] == a[i + 1] ? lsteq[i + 1] : i);
  }
  int cnt = 0, d = 0, ans = 1;
  for (int i = 1, j = 1; i <= n; i++) {
    j = std::max(j, lsteq[i]);
    while (j <= n && __builtin_popcountll(query(lsteq[i], j)) > 1) j++;
    ans += n - j + 1 + lsteq[i] - i + 1;
  }
  std::cout << ans << '\n';
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