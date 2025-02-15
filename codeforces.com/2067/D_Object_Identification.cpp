// date: 2025-02-12 12:21:17
// tag: 抽象交互题，注意审题

#include <bits/stdc++.h>
#define int long long

int ask(int a, int b) {
  std::cout << "? " << a << ' ' << b << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}

void answer(char x) {
  std::cout << "! " << x << std::endl;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int an = -1, a1 = -1;
  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    s.insert(a[i]);
    if (a[i] == n) {
      an = i;
    }
    if (a[i] == 1) {
      a1 = i;
    }
  }
  if (s.size() < n) {
    for (int i = 1; i <= n; i++) {
      if (!s.count(i)) {
        int ans = ask(i, i % n + 1);
        if (ans) {
          answer('B');
        } else {
          answer('A');
        }
        return;
      }
    }
  }
  int x = ask(a1, an), y = ask(an, a1);
  if (x == 0 || y == 0) {
    answer('A');
    return;
  }
  if (x == n - 1) {
    if (y == n - 1) {
      answer('B');
    } else {
      answer('A');
    }
  } else if (x < n - 1) {
    answer('A');
  } else {
    answer('B');
  }
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