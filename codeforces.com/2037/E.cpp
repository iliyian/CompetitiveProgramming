// date: 2024-11-21 21:47:30
// tag: goushi题

#include <bits/stdc++.h>
#define int long long

int ask(int l, int r) {
  std::cout << "? " << l << ' ' << r << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}

void answer(const std::string &x) {
  std::cout << "! " << x << std::endl;
}

void solve() {
  int n;
  std::cin >> n;
  std::string ans(n, '1');
  bool f = false;
  int prv = 0;
  for (int i = 2; i <= n; i++) {
    int x = ask(1, i);
    if (x && !f) {
      f = true;
      for (int j = i - 1; j >= i - x; j--) {
        ans[j - 1] = '0';
      }
      ans[i - 1] = '1';
    } else {
      ans[i - 1] = (prv && x == prv ? '0' : '1');
    }
    prv = x;
  }
  answer(f ? ans : "IMPOSSIBLE");
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