#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string a;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    a.push_back(x + 'a' - 1);
  }
  for (int i = 1; i <= m; i++) {
    int op;
    std::cin >> op;
    if (op == 1) {
      int l1;
      std::cin >> l1;
      std::string s, t;
      for (int j = 1; j <= l1; j++) {
        int x;
        std::cin >> x;
        s.push_back(x + 'a' - 1);
      }
      int l2;
      std::cin >> l2;
      for (int j = 1; j <= l2; j++) {
        int x;
        std::cin >> x;
        t.push_back(x + 'a' - 1);
      }
      auto p = a.find(s);
      if (p != a.npos) {
        auto q = a.erase(a.begin() + p, a.begin() + p + l1);
        a.insert(p, t);
      }
    } else if (op == 2) {
      std::string t;
      t.push_back(a.front());
      for (int i = 1; i < a.size(); i++) {
        if ((a[i] + a[i - 1] - 'a' + 1 - 'a' + 1) % 2 == 0) {
          t.push_back((a[i] + a[i - 1]) / 2);
        }
        t.push_back(a[i]);
      }
      a = t;
    } else {
      int l, r;
      std::cin >> l >> r;
      l--, r--;
      std::reverse(a.begin() + l, a.begin() + r + 1);
    }
  }
  for (int i = 0; i < a.size(); i++) {
    std::cout << a[i] - 'a' + 1 << " \n"[i == a.size() - 1];
  }
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