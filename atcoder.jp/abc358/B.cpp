#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, a;
  cin >> n >> a;
  int prv = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    int cur = max(prv, x) + a;
    prv = cur;
    cout << cur << '\n';
  }

  return 0;
}