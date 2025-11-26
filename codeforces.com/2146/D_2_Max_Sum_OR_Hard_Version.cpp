#include <bits/stdc++.h>
#define int long long

void solve() {
  int l, r;
  std::cin >> l >> r;
  std::map<int, int> ans;
  int sum = 0;
  auto solve = [&](this auto &&self, int r, int l) {
    if (r < l) return;
    if (l == r) {
      ans[l] = l;
      return;
    }
    int msb = 63, s = 0;
    while ((r >> msb & 1) == (l >> msb & 1)) {
      if (r >> msb & 1) {
        s |= 1ll << msb;
      }
      msb--;
    }
    s |= 1ll << msb;
    int rlen = r - s + 1, llen = s - l;
    if (rlen > llen) {
      int rr = s - l + s;
      for (int i = l; i < rr; i++) {
        ans[i] = s - i + s - 1;
      }
      self(r, rr);
    } else {
      int ll = s - (r - s + 1) - 1;
      for (int i = ll + 1; i <= r; i++) {
        ans[i] = s - i + s - 1;
      }
      self(ll, l);
    }
  };
  solve(r, l);
  for (auto [k, v] : ans) {
    sum += k | v;
  }
  std::cout << sum << '\n';
  for (auto [k, v] : ans) {
    std::cout << v << ' ';
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