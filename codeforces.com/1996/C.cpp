#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::string a, b;
  std::cin >> a >> b;
  a = '#' + a, b = '#' + b;
  std::vector<std::vector<int>> cnta(n + 1, std::vector<int>(26));
  std::vector<std::vector<int>> cntb(n + 1, std::vector<int>(26));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      cnta[i][j] = cnta[i - 1][j] + (a[i] - 'a' == j);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      cntb[i][j] = cntb[i - 1][j] + (b[i] - 'a' == j);
    }
  }
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      int asum = cnta[r][i] - cnta[l - 1][i];
      int bsum = cntb[r][i] - cntb[l - 1][i];
      if (asum != bsum) {
        ans += std::abs(asum - bsum);
      }
    }
    std::cout << ans / 2 << '\n';
  }
}

int32_t main() {
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