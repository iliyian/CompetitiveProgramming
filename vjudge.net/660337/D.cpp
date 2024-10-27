#include <bits/stdc++.h>

constexpr int N = 5e5;

std::vector<int> d(N + 1), prv(N + 1);

void add(int x, int c) {
  for (int i = x; i <= N; i++) d[i] += c;
}

int query(int x) {
  int ans = 0;
  for (int i = x; i > 0; i-= i & -i) ans += d[i];
  return ans;
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  std::vector<std::array<int, 3>> b;
  std::vector<std::vector<std::pair<int, int>>> p(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (prv[a[i]] && prv[a[i]] < i - 1) {
      b.push_back({prv[a[i]] + 1, i - 1, a[i]});
    }
    prv[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (prv[a[i]] && prv[a[i]] < n) {
      b.push_back({prv[a[i]] + 1, n, a[i]});
      prv[a[i]] = 0;
    }
  }
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("D.in", "r", stdin);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}