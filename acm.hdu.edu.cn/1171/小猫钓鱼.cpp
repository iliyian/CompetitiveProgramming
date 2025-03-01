// date: 2025-03-01 10:55:12
// tag: 小模拟，血亏，多个栈的思想

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string a, b;
  std::cin >> a >> b;
  a = '#' + a, b = '#' + b;
  std::vector<std::stack<int>> s(100);
  std::stack<int> sq;
  int aans = 0, bans = 0;
  int tp = 0;
  auto clear = [&](int low) {
    for (int i = '1'; i <= '9'; i++) {
      while (!s[i].empty() && s[i].top() >= low) {
        s[i].pop();
      }
    }
    while (!sq.empty() && sq.top() >= low)
      sq.pop();
  };
  auto op = [&](char ch) {
    int ans = 0;
    if (std::isdigit(ch)) {
      if (s[ch].empty()) {
        s[ch].push(++tp);
      } else if (sq.empty() || sq.top() < s[ch].top()) {
        ans += tp + 2 - s[ch].top();
        tp = s[ch].top() - 1;
        s[ch].pop();
      } else {
        s[ch].push(++tp);
        sq.pop();
      }
    } else if (ch == 'J') {
      if (sq.empty()) {
        ans += tp + 1;
        tp = 0;
      } else {
        ans += tp + 2 - sq.top();
        tp = sq.top() - 1;
        sq.pop();
      }
    } else if (ch == 'Q') {
      sq.push(++tp);
    } else {
      ++tp;
      if (!sq.empty())
        sq.pop();
    }
    clear(tp + 1);
    return ans;
  };
  for (int i = 1; i <= n; i++) {
    aans += op(a[i]);
    bans += op(b[i]);
  }
  std::cout << aans << ' ' << bans << '\n';
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