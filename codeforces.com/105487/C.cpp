#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int ccnt = 0, pcnt = 0;
  ccnt = std::count(str.begin(), str.end(), 'C');
  pcnt = std::count(str.begin(), str.end(), 'P');
  std::cout << std::min((ccnt - 1) / 2, pcnt) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
}