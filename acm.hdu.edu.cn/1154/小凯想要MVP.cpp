#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] == a[i + 1]) {
      std::cout << "YES\n";
      return;
    }
  }
  if (n > 2000) {
    std::cout << "YES\n";
    return;
  }
  std::map<int, int> s;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      s[a[i] + a[j]]++;
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