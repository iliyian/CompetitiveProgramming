// date: 2024-07-17 12:45:25
// tag: 数学

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> l(n + 1), r(n + 1), cnt(n + 1), s(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> l[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> r[i];
    int len = r[i] - l[i] + 1;
    cnt[i] = cnt[i - 1] + (len == 1);
    if (len != 1) {
      s[i] = s[i - 1] + len;
    } else {
      s[i] = s[i - 1];
    }
  }
  int ans = LLONG_MAX;
  for (int i = 1; i <= n; i++) {
    if (s[i] + cnt[i] < k) continue;
    if (s[i] >= k) {
      ans = std::min(ans, r[i] + i * 2 - (s[i] - k) - cnt[i] * 2);
      break;
    }
    if (s[i] + cnt[i] >= k) {
      ans = std::min(ans, r[i] + i * 2 - (s[i] + cnt[i] - k) * 2);
    }
  }
  std::cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
}

signed main() {
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