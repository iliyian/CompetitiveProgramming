// date: 2024-08-22 11:41:59
// tag: 倍增，value*length最大化

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> st(21, std::vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    st[0][i] = a[i];
  }

  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j + (1 << (i - 1)) <= n; j++) {
      st[i][j] = std::gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }

  auto query = [&](int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::gcd(st[len][l], st[len][r - (1 << len) + 1]);
  };

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int j = i;
    while (j <= n) {
      int cur = query(i, j);
      for (int k = 20; k >= 0; k--) {
        if (j + (1 << k) <= n && query(i, j + (1 << k)) == cur) {
          j += 1 << k;
        }
      }
      ans = std::max(ans, (j - i + 1) * cur);
      j++;
    }
  }
  std::cout << ans << '\n';

  return 0;
}