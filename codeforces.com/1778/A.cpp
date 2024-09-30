#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, sum = 0, prev, a;
  cin >> n >> prev;
  sum += prev;
  bool f1 = false, f2 = false;
  for (int i = 1; i < n; i++) {
    cin >> a;
    sum += a;
    if (a == prev && prev == -1)
      f1 = true;
    if (a != prev)
      f2 = true;
    prev = a;
  }
  if (f1) cout << sum + 4 << '\n';
  else if (f2) cout << sum << '\n';
  else cout << sum - 4 << '\n';
}

int main() {
  freopen("A.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}