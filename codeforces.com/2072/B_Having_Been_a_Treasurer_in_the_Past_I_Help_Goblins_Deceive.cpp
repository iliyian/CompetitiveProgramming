#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  int c0 = 0, c1 = 0;
  for (char c : str) {
    if (c == '-') c1++;
    else c0++;
  }
  int l = c1 / 2;
  int r = c1 - l;
  std::cout << l * r * c0 << '\n';
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