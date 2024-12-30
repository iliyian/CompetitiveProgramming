#include <bits/stdc++.h>
#define int long long

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

int A(int n, int m) {
  int ans = 1;
  for (int i = n; i >= n - m + 1; i--) {
    ans *= i;
  }
  return ans;
}

int cnt = 0;
std::vector<std::vector<int>> f(12, std::vector<int>(1 << 12, -1));

int dfs(int u, int S) {
  if (__builtin_popcountll(S) == cnt) {
    return 1;
  }
  if (f[cnt][S] != -1) return f[cnt][S];
  int ans = 0;
  for (int i = 1; i < (1 << cnt); i++) {
    if ((S & i) == 0) {
      ans += dfs(u + 1, S | i);
    }
  }
  return f[cnt][S] = ans;
}

void solve(int n) {
  // int n;
  // std::cin >> n;
  if (n == 1) {
    std::cout << 1 << '\n';
    return;
  }
  cnt = 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      cnt++;
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) cnt++;
  int ans = dfs(0, 0);
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  int n;
  while (std::cin >> n) {
    solve(n);
  }
  return 0;
}