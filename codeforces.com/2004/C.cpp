#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end(), std::greater());
  for (int i = 2; i <= n; i += 2) {
    if (k >= a[i - 1] - a[i]) {
      k -= a[i - 1] - a[i];
      a[i] = a[i - 1];
    } else {
      a[i] += k;
      break;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (i & 1 ? 1 : -1) * a[i];
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