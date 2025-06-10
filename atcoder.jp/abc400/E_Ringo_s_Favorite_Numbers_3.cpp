#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e6;
std::vector<int> pri, vis(N + 1);

void solve() {
  int n;
  std::cin >> n;
  int s = sqrtl(n);
  auto check = [&](int x) {
    int cnt = 0;
    for (int p : pri) {
      if (p * p > x) break;
      if (x % p == 0) {
        while (x % p == 0) x /= p;
        cnt++;
        if (cnt > 2) return false;
      }
    }
    if (!vis[x] && x > 1) {
      cnt++;
    }
    if (cnt != 2) return false;
    return true;
  };
  // std::cerr << s << '\n';
  for (int i = s; i >= 1; i--) {
    if (check(i)) {
      std::cout << i * i << '\n';
      return;
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = 1;
      if (i % p == 0) break;
    }
  }

  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}