#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;

void solve() {
  int k, x, a;
  cin >> k >> x >> a;
  int sum = 0;
  for (int i = 1; i <= x + 1; i++) {
    sum += sum / (k - 1) + 1;
  }
  if (sum <= a) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}