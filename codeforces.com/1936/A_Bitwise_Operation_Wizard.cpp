// date: 2025-05-09 16:41:21
// tag: 为什么位运算题总是如此抽象。哪个神仙能想到或最大的前提下的最小值就是异或的最大值啊

#include <bits/stdc++.h>
#define int long long

int ask(int a, int b, int c, int d) {
  std::cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << std::endl;
  char ans;
  std::cin >> ans;
  return ans;
}

void answer(int x, int y) {
  std::cout << "! " << x << ' ' << y << std::endl;
}

void solve() {
  int n;
  std::cin >> n;
  int mx = 0;
  for (int i = 1; i < n; i++) {
    if (ask(mx, mx, i, i) == '<') {
      mx = i;
    }
  }
  std::vector<int> tmp;
  for (int i = 0; i < n; i++) {
    if (i != mx) {
      if (tmp.empty()) {
        tmp.push_back(i);
      } else {
        char ans = ask(mx, i, mx, tmp.back());
        if (ans == '=') {
          tmp.push_back(i);
        } else if (ans == '>') {
          tmp.clear();
          tmp.push_back(i);
        }
      }
    }
  }
  int mn = tmp.front();
  for (int i = 1; i < tmp.size(); i++) {
    if (ask(mn, mn, tmp[i], tmp[i]) == '>') {
      mn = tmp[i];
    }
  }
  answer(mx, mn);
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