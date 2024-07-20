#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::string s, t;
  std::cin >> n >> s >> t;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      std::cout << "YES\n";
      return;
    } else if (s[i] != t[i]) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n" << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}