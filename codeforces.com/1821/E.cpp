// date: 2024-07-17 13:45:21
// tag: 括号序列

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int k;
  std::string str;
  std::cin >> k >> str;

  std::vector<int> dis;
  int ans = 0;
  std::stack<std::pair<int, int>> s;
  std::vector<int> sum(str.size());

  for (int i = 0; i < str.size(); i++) {
    sum[i] = (str[i] == '(') + (i ? sum[i - 1] : 0);
    if (str[i] == '(') {
      s.push({i, 0});
    } else {
      ans += s.size() - 1;
      dis.push_back(sum[i] - sum[s.top().first]);
      // dis.push_back(s.top().second);
      s.pop();

      // if (!s.empty()) {
      //   s.top().second++;
      // }
    }
  }
  std::sort(dis.begin(), dis.end());
  for (int i = dis.size() - 1; i >= std::max(0, signed(dis.size() - k)); i--) {
    ans -= dis[i];
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}