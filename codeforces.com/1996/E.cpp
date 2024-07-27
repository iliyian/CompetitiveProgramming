// date: 2024-07-27 08:59:13
// tag: 

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int mod = 1e9 + 7;

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  std::vector<int> s(n + 1);
  std::vector<std::vector<int>> pos(n * 2 + 1);
  pos[n].push_back(0);
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + (str[i] == '1' ? 1 : -1);
    pos[s[i] + n].push_back(i);
  }
  int ans = 0;
  for (auto &vec : pos) {
    if (vec.empty()) continue; // 怎么就军训了
    int cur = 0;
    for (int i = 1; i < vec.size(); i++) {
      ans += (vec[i - 1] + 1 + cur) % mod * (n - vec[i] + 1) % mod;
      ans %= mod;

      cur += vec[i - 1] + 1;
      cur %= mod;
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
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