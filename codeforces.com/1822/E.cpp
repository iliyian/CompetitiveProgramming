// date: 2024-07-17 14:08:47
// tag: 字符串

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::string str;

  std::cin >> n >> str;

  if (n & 1) {
    std::cout << -1 << '\n';
    return;
  }
  
  std::vector<int> vis(26), vis2(26);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    vis[str[i] - 'a']++;
    if (str[i] == str[n - i - 1]) {
      vis2[str[i] - 'a']++;
      sum++;
    }
    if (vis[str[i] - 'a'] > n / 2) {
      std::cout << -1 << '\n';
      return;
    }
  }

  for (int i = 0 ; i < 26; i++) {
    if (vis2[i] * 2 >= sum) {
      std::cout << vis2[i] / 2 << '\n';
      return;
    }
  }
  std::cout << (sum / 2 + 1) / 2 << '\n';
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