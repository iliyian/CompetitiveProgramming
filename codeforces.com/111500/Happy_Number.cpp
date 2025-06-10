#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int p[22] {}, l[22] {};
  p[0] = 1;
  l[1] = 1;
  for (int i = 1; i <= 21; i++) {
    p[i] = p[i - 1] * 3;
    l[i] = l[i - 1] * 3 + 1;
  }
  int i = 21;
  while (l[i] > n) i--;
  std::vector<int> ans(i + 1);
  int mp[] = {2, 3, 6};
  for (int j = i; j >= 1; j--) {
    ans[j] = (n - l[j]) / p[j - 1];
    n -= (ans[j] + 1) * p[j - 1];
    std::cout << mp[ans[j]];
  }
  std::cout << '\n';
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