// date: 2024-08-15 14:46:06
// tag: 进程dp，背包dp

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int T = 3e4;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<int> t1(n + 1), t2(n + 1), t3(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> t1[i] >> t2[i] >> t3[i];
    // if (t1[i] == 0) t1[i] = INT_MAX;
    // if (t2[i] == 0) t2[i] = INT_MAX;
    // if (t3[i] == 0) t3[i] = INT_MAX;
  }
  std::vector<int> f(T + 6, INT_MAX);
  f[0] = 0;
  int up = 0;
  for (int i = 1; i <= n; i++) {
    up += std::max(t1[i], t3[i]);
    for (int j = up; j >= 0; j--) {
      int x = INT_MAX, y = INT_MAX, z = INT_MAX;
      if (t1[i] && j >= t1[i]) x = f[j - t1[i]];
      if (t2[i]) y = f[j] + t2[i];
      if (t3[i] && j >= t3[i]) z = f[j - t3[i]] + t3[i];
      f[j] = std::min({x, y, z});
    }
  }
  int ans = INT_MAX;
  for (int i = 1; i <= up; i++) {
    ans = std::min(ans, std::max(i, f[i]));
  }
  std::cout << ans << '\n';

  return 0;
}