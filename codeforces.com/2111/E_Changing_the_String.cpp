// date: 2025-06-05 22:56:31
// tag: 什么暴力裸题啊？

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string str;
  std::cin >> str;
  std::multiset<int> ba, bc, ca, cb;
  for (int i = 1; i <= m; i++) {
    char x, y;
    std::cin >> x >> y;
    if (x == 'a') {
    } else if (x == 'b') {
      if (y == 'a') ba.insert(i);
      else if (y == 'c') bc.insert(i);
    } else if (x == 'c') {
      if (y == 'a') ca.insert(i);
      else if (y == 'b') cb.insert(i);
    }
  }
  for (int i = 0; i < str.size(); i++) {
    char ch = str[i];
    if (ch == 'a') {
    } else if (ch == 'b') {
      auto p = ba.begin();
      if (p != ba.end()) {
        ba.erase(p);
        ch = 'a';
      } else {
        p = bc.begin();
        if (p != bc.end()) {
          auto q = ca.upper_bound(*p);
          if (q != ca.end()) {
            bc.erase(p), ca.erase(q);
            ch = 'a';
          }
        }
      }
    } else if (ch == 'c') {
      auto p = ca.begin();
      if (p != ca.end()) {
        ca.erase(p);
        ch = 'a';
      } else {
        p = cb.begin();
        auto q = ba.upper_bound(*p);
        if (p != cb.end()) {
          if (q != ba.end()) {
            ch = 'a';
            ba.erase(q), cb.erase(p);
          } else {
            ch = 'b';
            cb.erase(p);
          }
        }
      }
    }
    std::cout << ch;
  }
  std::cout << '\n';
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