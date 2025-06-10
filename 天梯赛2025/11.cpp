#include <bits/stdc++.h>
#define int long long

int calc(std::string str) {
  int h = std::stoll(str.substr(0, 2));
  int m = std::stoll(str.substr(3, 2));
  int s = std::stoll(str.substr(6, 2));
  return h * 60 * 60 + m * 60 + s;
}

void solve() {
  int n;
  std::cin >> n;
  int N = 1e5;
  std::vector<int> a(N + 1);
  for (int i = 1; i <= n; i++) {
    std::string s, t;
    std::cin >> s >> t;
    a[calc(s)]++;
    a[calc(t) + 1]--;
  }
  int mx = 0;
  for (int i = 1; i <= N; i++) {
    a[i] += a[i - 1];
    mx = std::max(mx, a[i]);
  }
  std::cout << mx << '\n';
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