#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string str;
  std::cin >> str;
  std::vector<int> a(n + 1);
  str = '#' + str;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  auto b = a;
  std::sort(b.begin() + 1, b.end());
  auto check = [&](int mid) -> bool {
    std::vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++) {
      if (a[i] > mid && str[i] == 'B' && !vis[i]) {
        vis[i] = 1;
        for (int j = i - 1; j >= 1; j--) {
          if ((str[j] == 'B' || a[j] <= mid) && !vis[j]) {
            vis[j] = 1;
          } else {
            break;
          }
        }
        for (int j = i + 1; j <= n; j++) {
          if ((str[j] == 'B' || a[j] <= mid) && !vis[j]) {
            vis[j] = 1;
          } else {
            break;
          }
        }
      }
    }
    // std::cerr << mid << '\n';
    // for (int i = 1; i <= n; i++) {
    //   std::cerr << vis[i] << ' ';
    // }
    // std::cerr << '\n';
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (!vis[i] && str[i] == 'B' && a[i] > mid) {
        cnt++;
        assert(false);
      }
      if (vis[i] && !vis[i - 1]) {
        cnt++;
      }
    }
    return cnt <= k;
  };
  int l = 0, r = n, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    // std::cerr << l << ' ' << r << '\n';
    if (check(b[mid])) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  std::cout << b[ans] << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}