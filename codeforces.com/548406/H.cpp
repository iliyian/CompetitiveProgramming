#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] + a[i - 1] < k) {
      int d = k - (a[i] + a[i - 1]);
      ans += d;
      a[i] += d;
    }
  }
  std::cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';
}

signed main() {
  freopen("H.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}