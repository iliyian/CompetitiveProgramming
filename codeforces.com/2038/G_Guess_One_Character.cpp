// date: 2025-01-25 13:30:34
// tag: 01串，构造，交互，贪心，边界的特殊性

#include <bits/stdc++.h>
#define int long long

void answer(int x, int c) {
  std::cout << 0 << ' ' << x << ' ' << c << std::endl;
  int re;
  std::cin >> re;
  if (re != 1) {
    exit(0);
  }
}

int ask(std::string str) {
  std::cout << 1 << ' ' << str << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  int cnt0 = ask("0");
  int cnt01 = ask("01");
  int cnt00 = ask("00");
  answer(n, cnt0 == cnt01 + cnt00);
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