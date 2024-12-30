#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  std::cin >> n;
  int sum = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    sum += x;
    int t = sqrt(sum);
    if (t * t == sum && t % 2 == 1) {
      ans++;
    }
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
