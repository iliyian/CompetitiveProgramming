// date: 2024-05-17 15:35:04
// tag: 构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("I.in", "r", stdin);
  freopen("I.out", "w", stdout);

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int n;
    cin >> n;
    cout << format("Case #{}:\nYES\n", t);
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        cout << format("{} {} {} {} {} {} {} {}\n", i, j, i, j, 1, i, j, 2);
      }
    }
  }

  return 0;
}