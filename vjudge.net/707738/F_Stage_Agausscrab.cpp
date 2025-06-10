#include <bits/stdc++.h>
#include <cctype>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::string> names(n + 1);
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> names[i] >> a[i];
  }
  std::string ans;
  for (int i = 1; i <= n; i++) {
    int r = 1;
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        r += a[j] > a[i];
      }
    }
    for (int j = 0; j < (int)names[i].size() - r; j++) {
      ans.push_back(names[i][j]);
    }
  }
  ans.front() = toupper(ans.front());
  std::cout << "Stage: " << ans;
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