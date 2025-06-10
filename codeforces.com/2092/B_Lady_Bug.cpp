#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string a, b;
  std::cin >> a >> b;
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2) {
      cnt0 += a[i] - '0';
      cnt1 += b[i] - '0';
    } else {
      cnt0 += b[i] - '0';
      cnt1 += a[i] - '0';
    }
  }
  std::cout << (cnt1 <= n / 2 && cnt0 <= (n + 1) / 2 ? "YES" : "NO") << '\n';
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