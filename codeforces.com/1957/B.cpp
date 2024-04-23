#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> ans;
  if (n == 1) {
    cout << k << '\n';
    return;
  }
  int sum = 0, cnt = 0, len = 0;
  for (int i = 30; i >= 0; i--) {
    if (k >> i & 1) {
      len = i;
      break;
    }
  }
  cout << ((1 << len) - 1) << ' ';
  cout << (k - ((1 << len) - 1)) << ' ';
  for (int i = 0; i < n - 2; i++) {
    cout << 0 << ' ';
  }

  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}