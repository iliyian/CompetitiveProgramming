// date: 2024-05-03 15:48:28
// tag: 贪心，分块

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  string str;
  cin >> n >> str;
  int ans = 0;
  for (int i = 0; i < n - 1; i += 2) {
    ans += str[i] != str[i + 1];
  }
  cout << ans << ' ';
  ans = 0;
  bool f = false;
  int pre = -1;
  for (int i = 0; i < n - 1; i += 2) {
    if (str[i] == str[i + 1]) {
      f = true;
      if (str[i] != pre) {
        pre = str[i];
        ans++;
      }
    }
  }
  cout << (f ? ans : 1) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B2.in", "r", stdin);
  freopen("B2.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}