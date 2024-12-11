#include <bits/stdc++.h>
#define int long long

constexpr int N = 6e5;

void solve() {
  int n, k;
  std::cin >> n >> k;
  if (std::__lg(k - 1) >= n - 1) {
    std::cout << -1 << '\n';
    return;
  }
  std::vector<int> ans(n);
  int l = 0, r = n - 1, cur = 0;
  int len = n - 1;
  while (len >= 0) {
    if (std::log2(k) <= double(len) - 1) ans[l++] = ++cur;
    else ans[r--] = ++cur, k -= (1ll << (len - 1));
    len--;
  }
  // int len = (1ll << (n - 1));
  // while (len) {
  //   if (k <= len / 2) ans[l++] = ++cur;
  //   else ans[r--] = ++cur, k -= len / 2;
  //   len /= 2;
  // }
  for (auto i : ans) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
  // int n;
  // std::cin >> n;
  // std::vector<int> a(n + 1);
  // std::iota(a.begin(), a.end(), 0);
  // int mx = 0;
  // do {
  //   int sum = 0;
  //   for (int l = 1; l <= n; l++) {
  //     for (int r = l; r <= n; r++) {
  //       sum += *std::min_element(a.begin() + l, a.begin() + r + 1);
  //     }
  //   }
  //   if (sum >= mx) {
  //     mx = sum;
  //     for (int i = 1; i <= n; i++) {
  //       std::cout << a[i] << " ";
  //     }
  //     std::cout << sum << '\n';
  //   }
  // } while (std::next_permutation(a.begin() + 1, a.end()));
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
