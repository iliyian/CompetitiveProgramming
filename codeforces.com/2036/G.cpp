// date: 2024-11-15 15:04:11
// tag: 三个不同的数的异或和为0满足的条件，交互，二分，位运算

#include <bits/stdc++.h>
#define int long long

int ask(int x, int y) {
  std::cout << "xor " << x << ' ' << y << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}

void answer(int a, int b, int c) {
  std::cout << "ans " << a << ' ' << b << ' ' << c << std::endl;
}

void solve() {
  int n;
  std::cin >> n;
  int x = ask(1, n);
  if (x) {
    int l = 1, r = n, a = -1, b = -1, c = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (ask(1, mid)) r = mid - 1, a = mid;
      else l = mid + 1;
    }
    l = a + 1, r = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (ask(1, mid) ^ a) r = mid - 1, b = mid;
      else l = mid + 1;
    }
    c = ask(1, n) ^ a ^ b;
    answer(a, b, c);
  } else {
    int a = -1, b = -1, c = -1;
    for (int i = std::__lg(n) + 1; i >= 0; i--) {
      int t = ask(1, std::min(n, (1ll << i) - 1));
      if (t) {
        a = t;
        break;
      }
    }
    int l = a + 1, r = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (ask(1, mid) ^ a) r = mid - 1, b = mid;
      else l = mid + 1;
    }
    answer(a, b, a ^ b);
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
};
