#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }

  auto check = [&](int mid) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += std::min(a[i], mid);
    }
    return sum <= m;
  };

  int l = 0, r = 2e15, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  if (ans == 2e15) {
    std::cout << "infinite" << '\n';
  } else {
    std::cout << ans << '\n';
  }

  return 0;
}