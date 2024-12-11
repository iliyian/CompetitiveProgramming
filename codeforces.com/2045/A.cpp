// date: 2024-12-10 11:08:49
// tag: 字符串贪心，分类讨论

#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int cnt0 = 0, cnt1 = 0, cnty = 0, cntn = 0, cntg = 0;
  for (char ch : str) {
    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
      cnt0++;
    } else if (ch == 'Y') {
      cnty++;
    } else if (ch == 'N') {
      cntn++;
    } else if (ch == 'G') {
      cntg++;
    } else {
      cnt1++;
    }
  }
  int ans = 0;
  for (int i = 0; i <= std::min(cntn, cntg); i++) {
    for (int j = 0; j <= cnty; j++) {
      int c0 = cnt0, c1 = cnt1 + cntn + cntg - i; // 其中有i份辅音长2
      // std::cout << c0 << ' ' << c1 << '\n';
      c0 += j, c1 += cnty - j;
      // std::cout << c0 << ' ' << c1 << '\n';
      int cnt = std::min(c0, c1 / 2);
      ans = std::max(ans, cnt * 3 + std::min(cnt * 2, i)); // 一个词最多放两份长为2的辅音
    }
  }
  std::cout << ans << '\n';
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