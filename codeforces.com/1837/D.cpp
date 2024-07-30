// date: 2024-07-29 16:59:16
// tag: 

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  std::vector<int> s(n);
  for (int i = 0; i < n; i++) {
    s[i] = (i ? s[i - 1] : 0) + (str[i] == '(' ? 1 : -1);
  }
  if (s.back()) {
    std::cout << -1 << '\n';
    return;
  }
  bool f = false, g = false;
  for (int i = 0; i < n; i++) {
    f |= s[i] > 0;
    g |= s[i] < 0;
  }
  if (!f || !g) {
    for (int i = 0; i <= n; i++) {
      std::cout << 1 << " \n"[!i || i == n];
    }
    return;
  }
  std::cout << 2 << '\n';
  for (int i = 0; i < n; i++) {
    if (s[i] < 0 || i > 0 && s[i - 1] < 0) {
      std::cout << 2 << ' ';
    } else {
      std::cout << 1 << ' ';
    }
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}