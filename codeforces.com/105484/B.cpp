#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  std::string str;
  std::cin >> str;
  std::array<int, 2> cnt0 = {0, 0}, cnt1 = {0, 0};
  int cnt2 = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '0') {
      cnt0[i % 2]++;
    } else if (str[i] == '1') {
      cnt1[i % 2]++;
    } else {
      cnt2++;
    }
  }
  int t = std::abs(std::abs(cnt0[0] - cnt0[1]) + std::abs(cnt1[0] - cnt1[1]));
  // std::cout << t << ' ' << cnt2 << '\n';
  if (cnt2 < t) {
    std::cout << t - cnt2 << '\n';
  } else {
    std::cout << (cnt2 - t) % 2 << '\n';
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}