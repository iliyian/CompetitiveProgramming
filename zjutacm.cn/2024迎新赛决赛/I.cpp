#include <bits/stdc++.h>
#define int long long

constexpr int inf = 0x3f3f3f3f3f3f3f3f;

constexpr int N = 1e6;
std::vector<int> pri, vis(N + 1);

void solve() {
  int n;
  std::cin >> n;
  int len = 1;
  while (len * (len - 1) / 2 < n) len++;
  std::vector<int> ans;
  for (int i = 0; i < len; i++) {
    ans.push_back(pri[i]);
  }
  n = len * (len - 1) / 2 - n;
  int p = 0;
  while (n > 0) {
    int q = 1;
    while (q * (q + 1) / 2 <= n) q++;
    for (int i = p; i <= p + q - 1; i++) {
      ans[i] = ans[p];
    }
    p += q;
    n -= q * (q - 1) / 2;
  }
  std::cout << ans.size() << '\n';
  for (auto i : ans) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

signed main() {
  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (auto p : pri) {
      if (i * p > N) break;
      vis[i * p] = 1;
      if (i % p == 0) break;
    }
  }

  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}