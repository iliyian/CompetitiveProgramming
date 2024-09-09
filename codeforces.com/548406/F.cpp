#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  str = '#' + str;
  int ans = 0;
  for (int i = 1; i <= n; i += 2) {
    if (str[i] == str[i + 1]) {
      str[i] = (str[i] == 'a' ? 'b' : 'a');
      ans++;
    }
  }
  std::cout << ans << '\n';
  std::cout << str.substr(1) << '\n';
}

signed main() {
  freopen("F.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}