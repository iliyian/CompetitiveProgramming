// date: 2024-11-11 19:22:59
// tag: 树形dp，概率dp

#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int mod = 998244353;

void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;
  std::string str;
  std::cin >> str;
  int x = 0, y = 0;
  for (int t = 0; t <= 1e4; t++) {
    char ch = str[t % n];
    if (x == a && y == b) {
      std::cout << "YES\n";
      return;
    }
    if (ch == 'N') y++;
    if (ch == 'E') x++;
    if (ch == 'W') x--;
    if (ch == 'S') y--;
  }
  std::cout << "NO\n";
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