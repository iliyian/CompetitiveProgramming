#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  while (n--) {
    std::string str;
    std::cin >> str;
    int v = 1;
    for (int i = 0; i < str.size(); i++) {
      v *= str[i] - '0';
      if (v > k) {
        std::cout << "dame\n";
        goto end;
      }
    }
    std::cout << "kawaii\n";
    end:;
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