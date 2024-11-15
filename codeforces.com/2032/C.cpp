#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  int ans = INT_MAX;
  if (a[1] + a[2] > a[n]) {
    std::cout << 0 << '\n';
    return;
  }
  for (int l = 1; l + 1 <= n; l++) {
    int sum = a[l] + a[l + 1];
    int p = std::lower_bound(a.begin() + 1, a.end(), sum) - a.begin() - 1; 
    ans = std::min(ans, l - 1 + n - p);
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}