#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), pos(n + 1), cnt(n + 1);
  int ans = 0, ansl = 0, ansr = 0;
  std::set<int> s;
  auto check = [&](int l, int r) {
    if (l > r) return;
    if (r - l + 1 >= ans) {
      ansl = l, ansr = r, ans = r - l + 1;
    }
  };
  bool f = false;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    s.insert(a[i]);
    cnt[a[i]]++;
  }
  int prv = 0;
  for (int i = 1; i <= n + 1; i++) {
    if (i == n + 1 || cnt[a[i]] >= 2) {
      check(prv + 1, i - 1);
      prv = i;
    }
  }
  if (s.size() == n) {
    check(1, n);
  }
  if (ansl) {
    std::cout << ansl << ' ' << ansr << '\n';
  } else {
    std::cout << 0 << '\n';
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