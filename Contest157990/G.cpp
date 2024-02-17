#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  string a, b;
  cin >> a >> b;
  int cnt1 = 0, cnt2 = 0;
  b = '#' + b;
  for (int i = 1; i <= q; i++) {
    cnt1 += b[i] == '1', cnt2 += b[i] == '2';
  }
  cnt1 %= 2, cnt2 %= 2;
  if (cnt1) {
    reverse(a.begin(), a.end());
  }
  a = '#' + a;
  for (int i = 1; i <= n; i++) {
    cout << char(((a[i] - '0') ^ cnt2) + '0');
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}