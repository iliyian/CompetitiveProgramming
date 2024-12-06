#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int sum = 0, cnt2 = 0, cnt3 = 0;
  for (int i = 0; i < str.size(); i++) {
    sum += str[i] - '0';
    cnt2 += str[i] == '2';
    cnt3 += str[i] == '3';
  }
  for (int i = 0; i <= std::min(cnt2, 9ll); i++) {
    for (int j = 0; j <= std::min(cnt3, 3ll); j++) {
      if ((sum + i * 2 + j * 6) % 9 == 0) {
        std::cout << "YES\n";
        return;
      }
    }
  }
  std::cout << "NO\n";
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