// date: 2025-04-13 00:26:48
// tag: 明明错的相当离谱却打了200000组数据才找到一组。理论上应该很简单的dp，我又搞混状态了，每个数不会因为前面的数改变符号啊。

#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  str.push_back(0);
  std::vector<int> f(n + 1);
  int ch[128] {}, cnt[128] {};
  ch['A'] = 1;
  ch['B'] = 10;
  ch['C'] = 100;
  ch['D'] = 1000;
  ch['E'] = 10000;
  std::vector<std::array<int, 128>> hasbigger(n + 2);
  int vis[128] {};
  std::vector<int> s(n + 2);
  for (auto &i : hasbigger) {
    for (auto &j : i) j = 0;
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 'A'; j <= 'E'; j++) {
      hasbigger[i][j] |= hasbigger[i + 1][j];
    }
    for (int j = 'A'; j < str[i + 1]; j++) {
      hasbigger[i][j] = 1;
    }
    s[i] = s[i + 1] + ch[str[i]] * (hasbigger[i][str[i]] ? -1 : 1);
  }
  int ans = LLONG_MIN, sum = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 'A'; j <= 'E'; j++) {
      int tmp = sum;
      tmp += s[i + 1] + ch[j] * (hasbigger[i][j] ? -1 : 1);
      for (int k = 'A'; k <= 'E'; k++) {
        tmp += cnt[k] * ch[k] * ((k < j || hasbigger[i][k]) ? -1 : 1);
        // if (i == 19 && j == 'D') {
        //   std::cout << char(j) << ' ' << char(k) << ' ' << cnt[k] << ' ' << sum << '\n';
        // }
      }
      ans = std::max(ans, tmp);
    }
    cnt[str[i]]++;
    for (int j = 'A'; j < str[i]; j++) {
      sum -= cnt[j] * ch[j];
      cnt[j] = 0;
    }
  }
  ans = std::max(ans, s[1]);
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