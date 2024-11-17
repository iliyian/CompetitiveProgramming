// date: 2024-11-12 18:40:32
// tag: 字符串

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> acnt(26), bcnt(26);
  std::string a, b;
  std::cin >> a >> b;
  for (int i = 1; i <= n; i++) {
    acnt[a[i - 1] - 'a']++;
    bcnt[b[i - 1] - 'a']++;
  }
  int cnt = 0;
  for (int i = 0; i < 26; i++) {
    cnt += acnt[i];
    if (cnt < bcnt[i] || (cnt - bcnt[i]) % k) {
      std::cout << "No\n";
      return;
    }
    cnt -= bcnt[i];
  }
  std::cout << "Yes\n";
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}