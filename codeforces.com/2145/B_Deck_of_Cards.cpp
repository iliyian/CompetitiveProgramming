#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  int cnt = 0;
  std::string ans(n, '+');
  int l = 0, r = n - 1;
  for (int i = 1; i <= k; i++) {
    char ch;
    std::cin >> ch;
    if (ch == '0') {
      ans[l++] = '-';
    } else if (ch == '1') {
      ans[r--] = '-';
    } else {
      cnt++;
    }
  }
  if (cnt >= r - l + 1) {
    for (int i = 0; i < n; i++) {
      std::cout << "-";
    }
    std::cout << '\n';
    return;
  }
  for (int i = l; i <= l + cnt - 1; i++) {
    ans[i] = '?';
  }
  for (int i = r; i >= r - cnt + 1; i--) {
    ans[i] = '?';
  }
  std::cout << ans << '\n';
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