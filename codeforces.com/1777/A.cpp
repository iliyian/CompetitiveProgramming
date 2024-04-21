#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, prev, ans = 0;
  cin >> n >> prev;
  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;
    if (a % 2 == prev % 2)
      ans++;
    prev = a;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}