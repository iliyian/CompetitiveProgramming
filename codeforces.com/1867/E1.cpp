#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  auto ask = [](int x) {
    int ans;
    cout << "? " << x << '\n';
    cout.flush();
    cin >> ans;
    return ans;
  };
  int ans = 0, i;
  for (i = 1; i + k - 1 <= n; i += k) {
    ans ^= ask(i);
  }
  while (i <= n) {
    ans ^= ask(i - k + 1);
    i++;
  }
  cout << "! " << ans << '\n';
  cout.flush();
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E1.in", "r", stdin);
  freopen("E1.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}