#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, smax;
  std::cin >> n >> m >> smax;
  std::vector<std::queue<char>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    for (int j = 0; j < m; j++) {
      a[i].push(str[j]);
    }
  }
  int x;
  std::stack<char> s;
  while (std::cin >> x, x != -1) {
    if (x == 0) {
      if (!s.empty()) {
        std::cout << s.top(); s.pop();
      }
    } else {
      if (!a[x].empty()) {
        if (s.size() == smax) {
          std::cout << s.top(); s.pop();
        }
        s.push(a[x].front()); a[x].pop();
      }
    }
  }
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