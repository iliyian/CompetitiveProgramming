#include <algorithm>
#include <bits/stdc++.h>
#define int long long

int calc(int x) {
  int ans = 0;
  while (x) ans += x % 10, x /= 10;
  return ans;
}

std::string rev(std::string str) {
  std::reverse(str.begin(), str.end());
  return str;
}

bool isprime(int x) {
  if (x < 2) return false;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cout << std::setw(3) << a[i][j] / a[i][m];
    }
    std::cout << '\n';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}