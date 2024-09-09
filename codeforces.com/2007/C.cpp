#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, A, B;
  std::cin >> n >> A >> B;
  std::vector<int> a(n + 1);
  int g = std::gcd(A, B);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] %= g;
  }
  std::sort(a.begin() + 1, a.end());
  int ans = a.back() - a[1];
  for (int i = 1; i < n; i++) {
    ans = std::min(ans, g - (a[i + 1] - a[i]));
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}