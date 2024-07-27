// date: 2024-07-27 10:19:50
// tag: 异或哈希

#include <bits/stdc++.h>
#define int long long
// using namespace std;

using u64 = unsigned long long;

std::mt19937_64 rd(std::random_device{}());

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<u64> f(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    u64 r = rd();
    f[x] ^= r;
    f[y] ^= r;
  }
  for (int i = 1; i <= n; i++) {
    f[i] ^= f[i - 1];
  }
  std::map<u64, int> cnt;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = std::max(ans, ++cnt[f[i]]);
  }
  std::cout << n - ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}