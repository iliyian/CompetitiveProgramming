#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 998244353;

std::string s, t;
int n, m;
std::vector<int> mem(2e6 + 1);
std::vector<int> vis(2e6 + 1);
std::vector<std::vector<int>> h(101, std::vector<int>(26));
// 1 3 7 

// 2^t-1

int id(int dep, int l, int r) {
  return (dep * 101 + l) * 101 + r;
}

int cnt = 0, cnt0 = 0;
int dfs(int dep, int l, int r) {
  cnt++;
  if (dep == 0 || r < l || (dep <= 30 && (1ll << dep) - 1 < r - l + 1)) return 0;
  if (l == r) {
    return h[dep][t[l] - 'a'];
  }
  if (vis[id(dep, l, r)]) return mem[id(dep, l, r)];
  cnt0++;
  int ans = 2 * dfs(dep - 1, l, r) % mod;
  for (int k = l; k <= r; k++) {
    ans += dfs(dep - 1, l, k) * dfs(dep - 1, k + 1, r) % mod;
    ans %= mod;
    if (s[dep] == t[k]) {
      if (k == l) ans += dfs(dep - 1, l + 1, r);
      else if (k == r) ans += dfs(dep - 1, l, r - 1);
      else ans += dfs(dep - 1, l, k - 1) * dfs(dep - 1, k + 1, r) % mod;
      ans %= mod;
    }
  }
  vis[id(dep, l, r)] = 1;
  return mem[id(dep, l, r)] = ans;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("4.in", "r", stdin);
  std::cin >> s >> t;
  n = s.size(), m = t.size();
  s = '#' + s, t = '#' + t;
  for (int i = 1; i <= n; i++) {
    for (char j = 'a'; j <= 'z'; j++) {
      h[i][j - 'a'] = h[i - 1][j - 'a'] * 2 % mod + (s[i] == j);
      h[i][j - 'a'] %= mod;
    }
  }
  std::cout << dfs(n, 1, m) << '\n';
  // std::cout << cnt << '\n' << cnt0 << '\n';
  return 0;
}