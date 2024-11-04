#include <bits/stdc++.h>
#define int long long

signed main() {
  freopen("N.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::map<double, int> m;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    std::string str;
    std::cin >> str;
    double s = std::stod(str.substr(0, str.size() - 1));
    if (s == 15.0) {
      std::cout << "nebuchadnezzar\n";
    } else if (s == 12.0) {
      std::cout << "balthazar\n";
    } else if (s == 0.75) {
      std::cout << "standard\n";
    } else {
      if (!m[s]) m[s] = ++cnt;
      int t = m[s];
      while (t) {
        std::cout << char(t % 26 + 'a');
        t /= 26;
      }
      std::cout << '\n';
    }
  }
  return 0;
}