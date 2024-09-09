// date: 2024-08-31 21:22:25
// tag: 字符串，树，博弈

#include <algorithm>
#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::string str;
  std::vector<int> in(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    in[x]++, in[y]++;
  }
  std::cin >> str;
  str = '#' + str;
  int cnt0 = 0, cnt1 = 0, cntq = 0;
  for (int i = 2; i <= n; i++) {
    cnt0 += in[i] == 1 && str[i] == '0';
    cnt1 += in[i] == 1 && str[i] == '1';
    cntq += in[i] == 1 && str[i] == '?';
  }
  int ans = 0;
  if (str[1] != '?') {
    ans = (str[1] == '1' ? cnt0 : cnt1) + (cntq + 1) / 2;
  } else {
    ans = std::max(cnt0, cnt1) + cntq / 2;
    if (cnt0 == cnt1 && (std::count(str.begin(), str.end(), '?') - cntq) % 2 == 0) {
      ans = std::max(ans, cnt0 + (cntq + 1) / 2);
    }
  }
  std::cout << ans << '\n';
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