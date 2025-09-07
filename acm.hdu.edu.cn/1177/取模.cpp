#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, c;
  std::cin >> n >> m >> c;
  std::vector<int> a(n + 1), cnt(m + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }
  int tot = 0;
  std::vector<std::pair<int, int>> v;
  for (int i = 0; i <= m; i++) {
    if (cnt[i]) {
      v.push_back({i, cnt[i]});
      tot++;
    }
  }
  if (tot <= c) {
    for (auto &[k, v] : v) {
      if (v != n / c) {
        std::cout << 0 << '\n';
        return;
      }
    }
    std::cout << -1 << '\n';
    return;
  }

  for (int i = 1; i <= m; i++) {
    cnt[i] += cnt[i - 1];
  }
  // for (int i = c; i <= m; i++) {
  //   if ()
  // }

  std::vector<int> ans;
  std::vector<int> b(m + 1);
  // std::cerr << m * tot << '\n';
  for (int k = 1; k <= m * c / tot + 100; k++) { // 神秘上界
    for (auto &[_k, _v] : v) {
      b[_k % k] += _v;
    }
    bool f = true;
    for (auto &[_k, _v] : v) {
      if (b[_k % k] != n / c) {
        f = false;
        break;
      }
    }
    if (f) {
      ans.push_back(k);
    }
    for (auto &[_k, _v] : v) {
      b[_k % k] -= _v;
    }
  }
  std::cout << ans.size() << ' ';
  for (auto i : ans) {
    std::cout << i << ' ';
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