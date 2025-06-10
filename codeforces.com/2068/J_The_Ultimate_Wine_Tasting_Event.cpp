#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == 'W') {
      cnt++;
    }
  }
  if (cnt % 2) {
    std::cout << "NO\n";
    return;
  }
  for (int i = 0; i < cnt / 2; i++) {
    if (str[i] == 'R') {
      std::cout << "NO\n";
      return;
    }
  }
  for (int i = n * 2 - 1; i >= n * 2 - cnt / 2; i--) {
    if (str[i] == 'W') {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
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