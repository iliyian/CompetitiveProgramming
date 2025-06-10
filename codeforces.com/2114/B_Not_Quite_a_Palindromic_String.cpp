#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string str;
  std::cin >> str;
  int c[2] {};
  for (int i = 0; i < str.size(); i++) {
    c[str[i] - '0']++;
  }
  int d = std::abs(c[0] - c[1]);
  if (k < d / 2) {
    std::cout << "NO\n";
    return;
  }
  k -= d / 2;
  if (k % 2 == 1 || std::min(c[0], c[1]) * 2 < k) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
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