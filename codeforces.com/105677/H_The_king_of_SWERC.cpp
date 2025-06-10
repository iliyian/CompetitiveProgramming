#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::map<std::string, int> cnt;
  std::string mx = "0";
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    cnt[str]++;
    if (cnt[str] > cnt[mx]) {
      mx = str;
    }
  }
  std::cout << mx << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}