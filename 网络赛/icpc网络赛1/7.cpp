// date: 2024-09-17 21:28:28
// tag: 01化数组求中位数等的一种手段，及二分

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

using namespace __gnu_pbds;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::vector<std::vector<int>> b(n + 1, std::vector<int>(n + 1, LLONG_MAX));
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int idx = 0;
  for (int i = 1; i <= n; i++) {
    tree<std::pair<int, int>, null_type, std::less<>, rb_tree_tag, tree_order_statistics_node_update> s;
    for (int j = i; j <= n; j++) {
      s.insert({a[j], ++idx});
      b[i][j] = s.find_by_order((s.size() - 1) / 2)->first;
      // std::cout << b[i][j] << ' ';
    }
    // std::cout << '\n';
  }

  // return;

  auto check = [&](int mid) -> bool {
    std::vector<std::vector<int>> cnt(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        cnt[i][j] = (b[i][j] <= mid ? 1 : -1);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        cnt[i][j] += cnt[i - 1][j];
      }
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cnt[i][j] += cnt[i][j - 1];
      }
    }

    int ans = 0;
    for (int l = 1; l <= n; l++) {
      for (int r = l; r <= n; r++) {
        int siz = (r - l) * (r - l + 1) / 2;
        int res = cnt[r][r] - cnt[l - 1][r] - cnt[r][l - 1] + cnt[l - 1][l - 1];
        ans += (res >= 0);
      }
    }
    return ans >= (n * (n + 1) / 2 + 1) / 2;
  };
  int l = 1, r = 1e9 + 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else l = mid + 1;
  }
  std::cout << l << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}