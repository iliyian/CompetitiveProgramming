#include <bits/stdc++.h>
#define int long long

void solve() {
  int a[7] {};
  for (int i = 1; i <= 6; i++) {
    std::string str;
    std::cin >> str;
    if (str == "true") {
      a[i] = 1;
    } else {
      a[i] = 0;
    }
  }
  int cnt = 0;
  if (a[1] ^ a[4]) cnt++;
  if (a[2] ^ a[5]) cnt++;
  if (a[3] ^ a[6]) cnt++;
  if (cnt == 0) {
    std::cout << 8 << '\n';
  } else if (cnt == 1) {
    std::cout << 6 << '\n';
  } else if (cnt == 2) {
    std::cout << 5 << '\n';
  } else {
    std::cout << 4 << '\n';
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}