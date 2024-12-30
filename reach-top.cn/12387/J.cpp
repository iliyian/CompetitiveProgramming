#include <bits/stdc++.h>
#define int long long

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
  int n;
  std::cin >> n;
  std::stack<int> s;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) {
        s.push(i);
        n /= i;
      }
    }
  }
  if (n > 1) s.push(n);
  while (!s.empty()) {
    std::cout << s.top();
    s.pop();
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}