#include <bits/stdc++.h>
#define int long long

int qpow(int a, int b, int mod) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<double> ans(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum += a[i];
    ans[i] = a[i];
  }
  // for (int t = 1; t <= 1; t++) {
  //   int p = (t - 1) % n + 1;
  //   ans[p % n + 1] += ans[p] / 2;
  //   ans[p] /= 2;
  // }
  // for (int i = 1; i <= n; i++) {
  //   std::cout << ans[i] << ' ';
  // }
  // return;
  double t = (double)sum / (n + 1);
  int pos = qpow(2022, 1204, n);
  pos += 1;
  for (int i = 1; i <= n; i++) {
    std::cout << std::fixed << std::setprecision(20) << t * (i == pos ? 2 : 1) << ' ';
  }
  std::cout << '\n';
}

signed main() {
  freopen("D.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}