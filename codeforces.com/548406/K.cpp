#include <bits/stdc++.h>
#define int long long
using namespace std;

int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
std::string op = "URDL";

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  str = '#' + str;
  int x = 0, y = 0;
  for (int i = 1; i <= n; i++) {
    x += dx[op.find(str[i])];
    y += dy[op.find(str[i])];
    if (x == 1 && y == 1) {
      std::cout << "YES\n";
      return;
    }
  }
  std::cout << "NO\n";
  return;
}

signed main() {
  freopen("K.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}