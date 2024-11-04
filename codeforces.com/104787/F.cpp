#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e7;

std::vector<int> pri, vis(N + 1);

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::array<int, 4>> f(n + 1, {INT_MAX, INT_MAX, INT_MAX, INT_MAX});
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    
  }
}

signed main() {
  freopen("F.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      if (i % p == 0) {
        break;
      }
    }
  }
  std::set<int> s;
  int prv = 0;
  for (int p : pri) {
    s.insert(p - prv);
    prv = p;
  }

  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}