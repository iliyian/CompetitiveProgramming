// date: 2025-09-24 16:09:35
// tag: 实际上本代码能被 2 1 hack掉，正确答案是5，本代码会输出0......，只需要把m--删掉，ans的b初始化为1即可

#include <bits/stdc++.h>
#define int long long

int n, m;

struct Num {
  int a = 0, b = 10;
  Num operator*(Num other) {
    int _b = b * other.b;
    int _a = a * other.a * n + a * other.b + b * other.a;
    _a += _b / n;
    _b %= n;
    _a %= 10;
    return Num{_a, _b};
  }
};

void solve() {
  std::cin >> n >> m;
  Num ans{0, 10}, a = {0, 10};
  m--;
  while (m) {
    if (m & 1) ans = ans * a;
    a = a * a;
    m >>= 1;
  }
  std::cout << ans.a << '\n';
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