#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), vis(n + 1);
  for (int i = 1; i <= m; i++) {
    int p, x;
    std::cin >> p >> x;
    a[p] = x;
    vis[p] = true;
  }
  if (m < 3) {
    std::cout << "Yes\n";
    return;
  }
  int l = 1, r = n;
  while (l <= n && !vis[l]) l++;
  while (r >= l && !vis[r]) r--;
  for (int i = l + 1, j = r - 1; i < j; i++, j--) {
    if (vis[i] && vis[j] && a[i] + a[j] != a[l] + a[r]) {
      std::cout << "No\n";
      return;
    }
  }
  std::cout << "Yes\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}