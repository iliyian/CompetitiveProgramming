#include <bits/stdc++.h>
#define int long long

signed main() {
  std::string str;
  std::cin >> str;
  int n = str.size(), ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (str[i] == str[j]) {
        ans++;
      }
    }
  }
  std::cout << ans << '\n';
  return 0;
}