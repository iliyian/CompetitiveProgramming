// date: 2024/02/19 15:51:17
// tag: 我无法创造的，我就无法理解
// 遇事不决前缀和（x

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  string str;
  cin >> n >> str;
  reverse(str.begin(), str.end());
  while (str.back() == '0') {
    str.pop_back();
    n--;
  }
  reverse(str.begin(), str.end());
  vector<int> a(n + 1);
  for (int i = 0; i < n; i++) {
    a[i + 1] = str[i] - '0';
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  reverse(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++) {
    if (a[i] >= 10) {
      if (i >= n) {
        a.push_back(a[i] / 10);
        n++;
      } else {
        a[i + 1] += a[i] / 10;
      }
      a[i] %= 10;
    }
  }
  for (int i = a.size() - 1; i >= 1; i--) {
    cout << a[i];
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}