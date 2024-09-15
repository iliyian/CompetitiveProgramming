#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  freopen("L.in", "r", stdin);
  int n, T;
  std::cin >> n >> T;
  int ans = 2;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    ans = std::max(ans, (x + T - 1) / T);
  }
  std::cout << ans << '\n';
}