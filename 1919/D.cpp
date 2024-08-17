// date: 2024-08-11 16:31:55
// tag: 构造，单调栈，树

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  if (std::count(a.begin() + 1, a.end(), 0) != 1) {
    std::cout << "NO\n";
    return;
  }
  std::stack<int> s;
  std::vector<int> l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] > a[i]) {
      r[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  while (!s.empty()) {
    s.pop();
  }
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] > a[i]) {
      l[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cout << l[i] << ' ';
  // }
  // std::cout << '\n';
  // for (int i = 1; i <= n; i++) {
  //   std::cout << r[i] << ' ';
  // }
  // std::cout << '\n';
  for (int i = 1; i <= n; i++) {
    if (!a[i]) continue;
    bool f = false;
    if (l[i] && a[l[i]] == a[i] - 1) {
      f = true;
    }
    if (r[i] && a[r[i]] == a[i] - 1) {
      f = true;
    }
    if (!f) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}