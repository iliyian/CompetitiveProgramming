#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    b[i] += b[i - 1];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] + b[i] > a[n] + b[n] - a[i] - b[i]) {
      std::cout << "Mandy\n";
      return;
    } else if (a[n] - a[n - i] + b[n] - b[n - i] > a[n - i] + b[n - i]) {
      std::cout << "brz\n";
      return;
    }
    
  }
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