// date: 2025-04-24 00:58:12
// tag: 只能说tmd三四而后交啊，务必搞清楚啊，务必不要慌啊，主要是太慌了，太着急了，才WA了。很多时候都是犯了没有扩大化或者缩小化的问题。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int c[2] {};
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  int ans = str.size();
  str = '0' + str;
  for (int i = 1; i < str.size(); i++) {
    if (str[i] != str[i - 1]) {
      c[str[i] - '0']++;
      ans++;
    }
  }
  if (c[1] >= 2 || c[0] >= 2) {
    std::cout << ans - 2 << '\n';
    return;
  }
  if (c[1] && c[0]) {
    std::cout << ans - 1 << '\n';
    return;
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