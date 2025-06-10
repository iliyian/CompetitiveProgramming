// date: 2025-05-23 16:54:48
// tag: 暴力，仅维护当前需要更新的即可

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 2), d(n + 2);
  std::vector<int> l(n + 2), r(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    l[i] = i - 1, r[i] = i + 1;
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> d[i];
  }
  std::set<int> q;
  for (int i = 1; i <= n; i++) {
    q.insert(i);
  }
  for (int i = 1; i <= n; i++) {
    int ans = 0;
    std::set<int> nq;
    std::vector<int> del;
    for (auto j : q) {
      if (j > n || j < 1) continue;
      // std::cerr << j << ' ';
      int s = a[l[j]] + a[r[j]];
      if (s > d[j]) {
        nq.insert(l[j]);
        nq.insert(r[j]);
        del.push_back(j);
        // r[l[j]] = r[j];
        // l[r[j]] = l[j];
        ans++;
      }
    }
    for (int j : del) {
      r[l[j]] = r[j];
      l[r[j]] = l[j];
      nq.erase(j);
    }
    // std::cerr << '\n';
    q = nq;
    std::cout << ans << ' ';
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