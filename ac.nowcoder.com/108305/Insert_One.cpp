#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  if (str == "0") {
    std::cout << 10 << '\n';
    return;
  }
  if (str.front() != '-') {
    int pos = -1;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '0') {
        if (pos == -1) {
          pos = i; 
        }
      }
    }
    for (int i = 0; i < str.size(); i++) {
      if (i == pos) {
        std::cout << 1;
      }
      std::cout << str[i];
    }
    if (pos == -1) {
      std::cout << 1;
    }
    std::cout << '\n';
  } else {
    bool f = false;
    for (int i = 0; i < str.size(); i++) {
      if (str[i] > '1' && !f) {
        std::cout << 1;
        f = true;
      }
      std::cout << str[i];
    }
    if (!f) {
      std::cout << 1;
    }
    std::cout << '\n';
  }
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