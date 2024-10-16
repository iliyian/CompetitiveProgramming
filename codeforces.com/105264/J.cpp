#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;

std::vector<int> pri, vis(N + 1), low(N + 1);

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt += vis[low[a[i]]] || vis[a[i] / low[a[i]]];
  }
  std::cout << n - cnt + (cnt + 1) / 2 << '\n';
}

signed main() {
  freopen("J.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
      low[i] = 1;
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      low[i * p] = p;
      if (i % p == 0) {
        break;
      }
    }
  }

  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}