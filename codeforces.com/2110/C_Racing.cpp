#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> d(n + 1);
  std::vector<int> l(n + 1), r(n + 1);
  // int L = 0, R = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> d[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> l[i] >> r[i];
  }
  int L = 0, R = 0;
  std::stack<int> q;
  for (int i = 1; i <= n; i++) {
    if (d[i] == -1) {
      R++;
      if (L > r[i] || R < l[i]) {
        std::cout << -1 << '\n';
        return;
      }
      q.push(i);
    } else {
      L += d[i], R += d[i];
      if (L > r[i] || R < l[i]) {
        std::cout << -1 << '\n';
        return;
      }
    }
    for (int j = 0; i < R - r[i]; j++) {
      d[q.top()] = 0; q.pop();
    }
    R = std::min(R, r[i]);
    for (int j = 0; j < l[i] - L; j++) {
      d[q.top()] = 1; q.pop();
    }
    L = std::max(L, l[i]);
  }
  for (int i = 1; i <= n; i++) {
    // if (d[i] == -1) {
    //   std::cout << _L[i] - _L[i - 1] << ' ';
    // } else {
      std::cout << (d[i] == -1 ? 0 : d[i]) << ' ';
    // }
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