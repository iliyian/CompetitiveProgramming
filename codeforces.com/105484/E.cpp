#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string str;
  std::cin >> str;
  if (str.size() < 7) {
    std::cout << 0 << '\n';
    return;
  }
  int cnt = 0, ans = 0;
  for (int i = 0; i < str.size() - 6; i++) {
    if (str.substr(i, 7) == "nanjing") {
      cnt++;
    }
  }
  ans = std::max(ans, cnt);
  str += str;
  str = '#' + str;
  k = std::min(k, n);
  for (int i = 2; i <= k + 1; i++) {
    if (str.substr(i - 1, 7) == "nanjing") {
      cnt--;
    }
    if (str.substr(i + n - 7, 7) == "nanjing") {
      cnt++;
    }
    // std::cout << i + n - 7 << '\n';
    ans = std::max(ans, cnt);
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