#include <bits/stdc++.h>
#define int long long

constexpr int mod = 1e9;

void solve() {
  int n, k;
  std::cin >> n >> k;
  int sum = 0;
  n++;
  if (n <= k) {
    std::cout << 1 << '\n';
    return;
  }
  std::queue<int> q;
  for (int i = 1; i <= k; i++) {
    q.push(1);
    sum++;
  }
  for (int i = k + 1; i <= n; i++) {
    int x = sum;
    sum = (sum + mod - q.front()) % mod; q.pop();
    q.push(x);
    sum += x;
    sum %= mod;
    // std::cerr << sum << '\n';
  }
  std::cout << q.back() << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}