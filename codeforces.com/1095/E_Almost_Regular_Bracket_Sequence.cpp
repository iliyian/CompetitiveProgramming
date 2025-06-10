#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  std::vector<int> a(n + 1), b(n + 2);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1];
    if (str[i] == '(') a[i]++;
    else a[i]--;
  }
  for (int i = n; i >= 1; i--) {
    b[i] = b[i + 1];
    if (str[i] == '(') b[i]++;
    else b[i]--;
  }
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] == 2)
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