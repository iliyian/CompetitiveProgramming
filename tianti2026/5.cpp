#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b;
  std::cin >> a >> b;
  int h = 0, m = 0, s = -1;
  int x;
  auto print = [&](int x) {
    if (x < 10) std::cout << 0;
    std::cout << x;
  };
  auto p = [&]() {
    print(h);
    std::cout << ":";
    print(m);
    std::cout << ":";
    print(s);
  };
  while (std::cin >> x) {
    if (s == 59) {
      s = 1;
      if (m == 59) {
        m = 0;
        h++;
      } else {
        m++;
      }
    } else {
      s += 2;
    }
    if (x == a + b) {
      std::cout << x << " Accepted ";
      p();
      std::cout << '\n';
      return;
    }
    if (h == 2 && m == 59 && s == 59) {
      break;
    }
  }
  std::cout << x << " Wrong Answer ";
  p();
  std::cout << '\n';
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