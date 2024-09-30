#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0, cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < n; i++)
    cin >> a[i], sum += a[i], cnt1 += a[i] == 1, cnt2 += a[i] == 1000000000ll;
  sort(a.begin(), a.end());
  int tot = sum;
  if (n == 1) {
    cout << "NO\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      tot -= 2;
    } else {
      tot--;
    }

    if (tot < 0) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
}
// 1 1 1 1 2 2
// 2 2 2 2
// 1 1 1 3

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}