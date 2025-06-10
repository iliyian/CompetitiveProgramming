#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string str;
  std::cin >> str;
  str = '#' + str + '#';
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<int> pre(n + 2), suf(n + 2);
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    if (str[i] == '0') {
      pre[i] = 0;
    } else {
      pre[i] = std::max(pre[i - 1] + a[i], a[i]);
    }
    mx = std::max(mx, pre[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (mx == k) {
      std::cout << "Yes\n";
      for (int i = 1; i <= n; i++) {
        std::cout << (str[i] == '1' ? a[i] : (int)-1e18) << " \n"[i == n];
      }
      return;
    }
  }
  if (k < mx) {
    std::cout << "No\n";
    return;
  }
  for (int i = n; i >= 1; i--) {
    if (str[i] == '0') {
      suf[i] = 0;
    } else {
      suf[i] = std::max(suf[i + 1] + a[i], a[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (str[i] == '0') {
      int cur = 0;
      if (str[i + 1] == '1') cur += std::max(0ll, suf[i + 1]);
      if (str[i - 1] == '1') cur += std::max(0ll, pre[i - 1]);
      if (cur <= k || true) {
        a[i] = k - cur;
        str[i] = '1';
        std::cout << "Yes\n";
        for (int i = 1; i <= n; i++) {
          std::cout << (str[i] == '1' ? a[i] : (int)-1e18) << " \n"[i == n];
        }
        return;
      }
    }
  }
  std::cout << "No\n";
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