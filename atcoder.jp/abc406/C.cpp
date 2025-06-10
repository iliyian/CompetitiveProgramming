#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int len = 0;
  std::vector<int> b;
  for (int i = 2; i <= n; i++) {
    if (a[i] <= a[i - 1]) {
      if (len) {
        b.push_back(len);
      }
      len = 0;
    } else {
      len++;
    }
  }
  if (len) {
    b.push_back(len);
  }
  // for (auto i : b) {
  //   std::cerr << i << ' ';
  // }
  // std::cerr << '\n';
  int ans = 0;
  for (int i = 1; i < b.size(); i++) {
    ans += b[i] * b[i - 1];
  }
  std::cout << ans << '\n';
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