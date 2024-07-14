// date: 2024-07-12 19:15:08
// tag: 构造，贪心

#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
// using namespace std;

constexpr int N = 1e12;

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  
  str = '#' + str + '#';
  std::vector<int> suf(n + 2), pre(n + 2);

  for (int i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + (str[i] == '1');
  }
  for (int i = n; i >= 1; i--) {
    suf[i] = suf[i + 1] + (str[i] == '0');
  }

  int ans = inf;
  for (int i = 0; i <= n; i++) {
    ans = std::min(ans, (suf[i + 1] + pre[i]) * (N + 1));
    if (str[i] == '1' && str[i + 1] == '0') {
      ans = std::min(ans, (suf[i + 2] + pre[i - 1]) * (N + 1) + N);
    }
  }
  std::cout << ans << '\n';
}

signed main() {
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