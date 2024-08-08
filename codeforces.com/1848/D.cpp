// date: 2024-08-08 16:57:37
// tag: 数学，二次函数

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int calc(int s, int k, int x) {
  if (x < 0) return 0;
  if (k < 4 * x) return 0;
  return - 80 * x * x + (20 * k - 4 * s) * x + s * k;
}

void solve() {
  int s, k;
  std::cin >> s >> k;
  int ans = s * k;
  if (s % 10 == 0) {
    std::cout << ans << '\n';
    return;
  }
  if (s % 10 == 5) {
    std::cout << std::max(ans, (s + 5) * (k - 1)) << '\n';
    return;
  }
  if (s % 2) {
    k--, s += s % 10;
  }
  ans = std::max(ans, s * k);
  for (int i = 0; i < 4; i++, k--) {
    if (k < 0) break;
    ans = std::max(ans, calc(s, k, (5 * k - s + 39) / 40));
    ans = std::max(ans, calc(s, k, (5 * k - s) / 40));
    ans = std::max(ans, calc(s, k, 0));
    ans = std::max(ans, calc(s, k, 1));
    s += s % 10;
  }
  std::cout << ans << '\n';
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