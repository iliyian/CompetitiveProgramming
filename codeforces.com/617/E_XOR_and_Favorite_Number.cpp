// date: 2025-03-28 17:20:36
// tag: 关于莫队的操作也要符合栈的原则这件事，如果加是先更新答案再改，则删则要先改再更新答案，嗯，反正很有对称性。异或前缀和

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<int> a(n + 2);
  for (int i = 2; i <= n + 1; i++) {
    std::cin >> a[i];
    a[i] ^= a[i - 1];
  }
  std::vector<std::array<int, 3>> ask(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> ask[i][0] >> ask[i][1];
    ask[i][1]++;
    ask[i][2] = i;
  }
  int Knum = n / std::min<int>(n, sqrt(m));
  std::vector<int> K(n + 2);
  for (int i = 2; i <= n + 1; i++) {
    K[i] = (i - 1) / Knum + 1;
  }
  sort(ask.begin() + 1, ask.end(), [&](const auto &x, const auto &y) {
    if (K[x[0]] != K[y[0]]) return x[0] < y[0];
    if (K[x[0]] & 1) return x[1] < y[1];
    return x[1] > y[1];
  });
  int l = 1, r = 0, val = 0;
  std::vector<int> ans(m + 1);
  constexpr int N = 3e6;
  std::vector<int> cnt(N + 1);
  auto add = [&](int x) {
    val += cnt[x ^ k];
    cnt[x]++;
  };
  auto del = [&](int x) {
    cnt[x]--;
    val -= cnt[x ^ k];
  };
  for (int i = 1; i <= m; i++) {
    auto [ql, qr, id] = ask[i];
    while (l > ql) add(a[--l]);
    while (r < qr) add(a[++r]);
    while (l < ql) del(a[l++]);
    while (r > qr) del(a[r--]);
    ans[id] = val;
  }
  for (int i = 1; i <= m; i++) {
    std::cout << ans[i] << '\n';
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