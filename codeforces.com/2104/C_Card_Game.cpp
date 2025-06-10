#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  str = '#' + str;
  std::vector<int> a, b;
  for (int i = 1; i <= n; i++) {
    if (str[i] == 'A') {
      a.push_back(i);
    } else {
      b.push_back(i);
    }
  }
  for (auto i : a) {
    bool f = true;
    for (auto j : b) {
      if (j == 1 && i == n || j == n && i != 1 || j != 1 && j != n && j > i) { // j 可以干掉 i
        f = false;
        break;
      }
    }
    if (f) {
      std::cout << "Alice\n";
      return;
    }
  }
  std::cout << "Bob\n";
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