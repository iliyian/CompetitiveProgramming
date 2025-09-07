#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  int vis[128] {};
  for (int i = 1; i < n - 1; i++) {
    vis[str[i]]++;
    if (str[i] == str.front() || str[i] == str.back()) {
      std::cout << "Yes\n";
      return;
    }
  }
  for (int i = 'a'; i <= 'z'; i++) {
    if (vis[i] > 1) {
      std::cout << "Yes\n";
      return;
    }
  }
  std::cout << "No\n";
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