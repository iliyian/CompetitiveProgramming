// date: 2024-07-25 14:40:07
// tag: 字符串哈希
// 关键在于u64自然溢出，太妙了

#include <bits/stdc++.h>
#define int long long
// using namespace std;

using u64 = unsigned long long;

constexpr int base = 1e9 + 7;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string str;
  std::cin >> str;

  str = '#' + str;
  int ans0 = 0, ans1 = 0;
  std::vector<int> h(n + 2), revh(n + 2), p(n + 2);
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] * base;
    ans0 = ans0 * base + ((i - 1) / k % 2 ? 0 : 1);
    ans1 = ans1 * base + ((i - 1) / k % 2 ? 1 : 0);
    h[i] = h[i - 1] * base + (str[i] == '1');
    revh[n - i + 1] = revh[n - i + 2] * base + (str[n - i + 1] == '1');
  }
  if (h[n] == ans0 || h[n] == ans1) {
    std::cout << n << '\n';
    return;
  }
  for (int i = 1; i < n; i++) {
    int h1 = (h[n] - h[i] * p[n - i]);
    int h2 = (revh[1] - revh[i + 1] * p[i]);
    int H = h1 * p[i] + h2;
    if (H == ans0 || H == ans1) {
      std::cout << i << '\n';
      return;
    }
  }
  std::cout << -1 << '\n';
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