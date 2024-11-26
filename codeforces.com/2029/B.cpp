#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string a, b;
  std::cin >> n >> a >> b;
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < n; i++) {
    cnt0 += a[i] == '0';
    cnt1 += a[i] == '1';
  }
  for (int i = 0; i < n - 1; i++) {
    if (!cnt0 || !cnt1) {
      std::cout << "NO\n";
      return;
    }
    (b[i] == '0' ? cnt1 : cnt0)--;
  }
  std::cout << "YES\n";
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