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

void solve() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0 && (n % (i + 1) == 0)) {
      std::cout << "(" << i << "," << i + 1 << ")\n";
    }
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