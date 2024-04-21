// date: 2023/12/7
// tag: simplify, wisdom, divide and conquer

#include <bits/stdc++.h>
#define int long long
using namespace std;

int cnt[10];

void solve() {
  int n, ans = 1;
  cin >> n;
  while (n) {
    int x = n % 10;
    ans *= cnt[x];
    n /= 10;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("E.in", "r", stdin);
  int t; cin >> t;

  for (int i = 0; i <= 9; i++)
    for (int j = 0; j <= 9; j++)
      for (int k = 0; k <= 9; k++)
        if (i + j + k <= 9)
          cnt[i + j + k]++;

  while (t--) solve();
  return 0;
}