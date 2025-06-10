#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b, n;
  std::cin >> a >> b >> n;
  std::vector<int> cur = {0, a, b};
  int p = 1;
  for (int i = 3; i <= n; i++) {
    int x = cur[p] * cur[p + 1];
    if (x != 0) {
      std::stack<int> s;
      while (x) {
        s.push(x % 10);
        x /= 10;
      }
      while (!s.empty()) {
        cur.push_back(s.top()); s.pop();
        if (cur.size() - 1 >= n) {
          break;
        }
      }
    } else {
      cur.push_back(0);
    }
    if (cur.size() - 1 >= n) {
      break;
    }
    p++;
  }
  for (int i = 1; i <= n; i++) {
    std::cout << cur[i];
    if (i != n) {
      std::cout << ' ';
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