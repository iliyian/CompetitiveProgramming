// date: 2025-05-25 20:46:10
// tag: 小模拟

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), l(n + 1), r(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    l[i] = i - 1, r[i] = i + 1;
  }
  l[1] = n, r[n] = 1;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  int cur = 1, f = 1;
  for (int i = 1; i <= m; i++) {
    // std::cerr << cur << '\n';
    a[cur]--;
    if (!a[cur]) {
      r[l[cur]] = r[cur];
      l[r[cur]] = l[cur];
    }
    if (str[i] == 'S') {
      if (f) {
        cur = r[r[cur]];
      } else {
        cur = l[l[cur]];
      }
    } else if (str[i] == 'R') {
      f ^= 1;
      if (f) {
        cur = r[cur];
      } else {
        cur = l[cur];
      }
    } else if (str[i] == 'C') {
      if (f) {
        cur = r[cur];
      } else {
        cur = l[cur];
      }
    } else {
      if (f) {
        a[r[cur]] += 2;
      } else {
        a[l[cur]] += 2;
      }

      if (f) {
        cur = r[r[cur]];
      } else {
        cur = l[l[cur]];
      }
    }
    // for (int i = 1; i <= n; i++) {
    //   std::cout << a[i] << " \n"[i == n];
    // }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << '\n';
  }
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