// date: 2024-08-01 16:36:22
// tag: 构造

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 2e6 + 10;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
  std::string str;
  std::cin >> str;

  std::vector<std::pair<int, int>> ans(N, {-1, -1});
  std::vector<int> s(n + 1);
  for (int i = 0; i < n; i++) {
    s[i] = (i ? s[i - 1] : 0) + (str[i] == 'T' ? 2 : 1);
  }

  auto solve = [&](int l, int r) {
    int sum = s[r] - (l ? s[l - 1] : 0);
    ans[sum] = {l, r};
    while (l < r) {
      if (str[l] == str[r]) {
        if (str[l] == 'T') {
          ans[sum - 2] = {l + 1, r};
          ans[sum - 4] = {l + 1, r - 1};
          sum -= 2;
        } else {
          ans[sum - 2] = {l + 1, r - 1};
        }
        l++, r--;
      } else if (str[l] == 'T') {
        ans[sum - 2] = {++l, r};
      } else {
        ans[sum - 2] = {l, --r};
      }
      sum -= 2;
    }
    ans[sum] = {l, l};
  };
  solve(0, n - 1);

  for (int i = 0; i < n - 1; i++) {
    if (str[i] != 'T') {
      solve(i + 1, n - 1);
      break;
    }
  }
  
  for (int i = n - 1; i >= 1; i--) {
    if (str[i] != 'T') {
      solve(0, i - 1);
      break;
    }
  }

  std::vector<std::pair<int, int>> q;
  for (int i = 1; i <= m; i++) {
    int x;
    std::cin >> x;
    auto [l, r] = ans[x];
    if (l == -1 || r == -1) {
      std::cout << "NIE\n";
    } else {
      std::cout << l + 1 << ' ' << r + 1 << '\n';
    }
  }

  return 0;
}