#include <bits/stdc++.h>
#include <cwchar>

signed main() {
  int n;
  std::cin >> n;
  std::multiset<int> s;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    if (x >= 15) continue;
    s.insert(x);
  }
  int ans = 0;
  while (!s.empty()) {
    int x = *s.begin();
    bool f = true;
    for (int i = 0; i < 5; i++) {
      if (!s.count(x + i)) {
        f = false;
      } 
    }
    if (f) {
      for (int i = 0; i < 5; i++) {
        s.erase(s.find(x + i));
      }
      ans++;
    } else {
      s.erase(s.find(x));
    }
  }
  end:
  std::cout << ans << '\n';
  return 0;
}