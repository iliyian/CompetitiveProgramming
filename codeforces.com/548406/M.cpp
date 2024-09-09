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
  for (int i = 1; i <= n - 2; i++) {
    int x = a[i], y = a[i + 1], z = a[i + 2];
    if (x + y > z) {
      std::cout << "YES\n";
      return;
    }
  }
  std::cout << "NO\n";
}

signed main() {
  freopen("M.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}