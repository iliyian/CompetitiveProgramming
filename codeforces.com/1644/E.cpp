// date: 2024-04-24 11:36:13
// tag: 模拟

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  int f = -1;
  int x = 1 + (str[0] == 'D'), y = 1 + (str[0] == 'R');
  for (int i = 1; i < str.size(); i++) {
    x += str[i] == 'D', y += str[i] == 'R';
    if (f == -1 && str[i] != str[i - 1]) f = i;
  }
  if (f == -1) {
    cout << n << '\n';
    return;
  }
  int w = n - y + 1, h = n - x + 1;
  int ans = w * h;
  int px = x, py = y;
  for (int i = str.size() - 1; i >= f; i--) {
    if (str[i] == 'D') {
      ans += w;
    } else {
      ans += h;
    }
    x -= str[i] == 'D', y -= str[i] == 'R';
  }
  cout << ans + f << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}