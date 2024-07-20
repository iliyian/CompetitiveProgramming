// date: 2024-07-18 16:25:26
// tag: 多指针，构造

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    ans += (n - i) * (n - i + 1) / 2;
  }
  for (int i = 1; i <= n; i++) {
    int l = i, r = i;
    while (l >= 1 && a[l] >= a[i]) l--;
    while (r <= n && a[r] >= a[i]) r++;
    int k = l;
    while (k >= 1 && a[k] <= a[i]) k--;
    ans -= (l - k) * (r - i);
    std::cout << l << ' ' << k << ' ' << r << ' ' << i << '\n';
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B1.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}