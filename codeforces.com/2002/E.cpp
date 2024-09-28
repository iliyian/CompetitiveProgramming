#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::stack<std::pair<int, int>> s;
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    int len = 0;
    while (!s.empty()) {
      if (s.top().second < x) {
        
      }
    }
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}