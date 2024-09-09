#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  int t = sqrt(n);
  if (t * t != n) {
    std::cout << "No\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (i <= t || i >= n - t + 1) {
      if (str[i] != '1') {
        std::cout << "No\n";
        return;
      }
    } else {
      if (i % t == 1 || i % t == 0) {
        if (str[i] != '1') {
          std::cout << "No\n";
          return;
        }
      } else {
        if (str[i] != '0') {
          std::cout << "No\n";
          return;
        }
      }
    }
  }
  std::cout << "Yes\n";
}

int32_t main() {
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