#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  std::vector<std::vector<std::string>> sp(4);
  sp[1] = {"I", "V", "X", "L", "C", "D", "M"};
  sp[2] = {"II", "XX", "CC", "MM"};
  sp[3] = {"III", "XIX", "XXX", "CXC", "CCC", "MCM", "MMM"};
  std::vector<int> f(n + 1, INT_MAX);
  std::vector<int> pre(n + 1);
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= std::min(i, 3ll); j++) {
      if (std::find(sp[j].begin(), sp[j].end(), str.substr(i + 1 - j, j)) != sp[j].end()) {
        if (f[i] > f[i - j] + 1) {
          f[i] = f[i - j] + 1;
          pre[i] = i - j;
        }
      }
    }
  }
  std::vector<std::string> ans;
  for (int i = n; i >= 1; i = pre[i]) {
    ans.push_back(str.substr(pre[i] + 1, i - pre[i]));
    // if (i == ) break;
  }
  std::cout << ans.size() << '\n';
  for (int i = ans.size() - 1; i >= 0; i--) {
    std::cout << ans[i] << '\n';
  }
}

signed main() {
  freopen("H.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}