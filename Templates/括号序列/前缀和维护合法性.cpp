// date: 2024-07-26 12:33:28
// tag: 基于前缀和维护的括号序列合法性与计数

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  std::string str;
  std::cin >> str;
  int n = str.size();
  str = '#' + str;
  std::vector<int> s(n + 1);
  std::vector<std::vector<int>> pos(n + 1);
  std::vector<std::vector<int>> mx(n + 1, std::vector<int>(21));
  std::vector<std::vector<int>> mn(n + 1, std::vector<int>(21));
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + (str[i] == '(' ? 1 : -1);
    pos[s[i]].push_back(i);
    mx[i][0] = mn[i][0] = s[i];
  }

  for (int j = 1; j <= 20; j++) {
    for (int i = 1; i + (1 << (j - 1)) <= n; i++) {
      mx[i][j] = std::max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
      mn[i][j] = std::min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
    }
  }

  auto querymn = [&](int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::min(mn[l][len], mn[r - (1 << len) + 1][len]);
  };

  auto querymx = [&](int l, int r) {
    int len = std::__lg(r - l + 1);
    return std::max(mx[l][len], mx[r - (1 << len) + 1][len]);
  };

  int ans = 0;
  for (auto &vec : pos) {
    if (vec.empty()) continue;
    int l = vec[0] + 1, cnt = 1;
    for (int i = 1; i < vec.size(); i++) {
      int r = vec[i];
      if (querymn(l, r) >= 0 && querymx(l, r) <= 2 * s[l - 1]) {
        ans += cnt;
        cnt++;
      } else {
        l = r + 1;
        cnt = 1;
      }
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