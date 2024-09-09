#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  std::string a, b;
  std::cin >> a >> b;
  std::string ans;
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      std::string x = a.substr(0, i + 1) + b.substr(0, j + 1);
      if (ans.empty() || x < ans) {
        ans = x;
      }
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  freopen("L.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}