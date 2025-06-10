// date: 2025-03-02 10:49:19
// tag: 什么神奇字符串贪心，划分为相同字符尽可能远的字符串的方法，先确定界限，然后一个一个填

#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  std::vector<int> cnt(26), p(26);
  for (int i = 1; i <= n; i++) {
    cnt[str[i] - 'a']++;
  }
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(), [&](const int &x, const int &y) {
    return cnt[x] > cnt[y];
  });
  int k = (n - 1) / (cnt[p[0]] - 1);
  std::cout << k << '\n';
  std::string ans(n + 1, '0');
  int x = 0;
  for (int i = 1; i <= k; i++) {
    for (int j = i; j <= n; j += k) {
      if (!cnt[p[x]]) x++;
      cnt[p[x]]--;
      ans[j] = p[x] + 'a';
    }
  }
  std::cout << ans.substr(1, n) << '\n';
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