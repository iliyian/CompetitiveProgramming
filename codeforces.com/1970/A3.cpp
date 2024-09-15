// date: 2024-09-14 15:19:05
// tag: 构造，括号序列

#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("A3.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  int cur = 0, prv = 0;
  std::vector<std::vector<char>> s(n + 1);
  for (int i = 1, j = 1; i <= n; i = j) {
    int cnt = prv;
    while (str[j] == '(') {
      s[cur].push_back(str[j++]);
      cnt++;
    }
    cur++;
    prv = 0;
    while (j <= n && cnt) {
      s[cur].push_back(str[j]);
      cnt -= str[j] == ')';
      prv += str[j] == '(';
      j++;
    }
  }
  cur = 0;
  for (int i = 1; i <= n; i++) {
    char u = s[cur].back(); s[cur].pop_back();
    cur += u == '(' ? 1 : -1;
    std::cout << u;
  }
  return 0;
}