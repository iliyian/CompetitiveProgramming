#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (cur == 0 && i != 1) {
      std::cout << "No\n";
      return;
    }
    cur -= i != 1;
    cur += a[i] - (i != 1);
  }
  if (cur) {
    std::cout << "No\n";
    return;
  }
  std::cout << "Yes\n";
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