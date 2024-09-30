// 真tmd暴力，也能AC

#include <bits/stdc++.h>
#define N 150001
#define int long long
using namespace std;

int a[N], sum[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i], sum[i] = a[i] + sum[i - 1];
  int maxans = -1;
  for (int k = 1; k <= n; k++) {
    if (n % k) continue;
    int maxn = -1, minn = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= n - k + 1; i += k) {
      int r = i + k - 1;
      maxn = max(maxn, sum[r] - sum[i - 1]);
      minn = min(minn, sum[r] - sum[i - 1]);
    }
    maxans = max(maxans, abs(maxn - minn));
  }
  cout << maxans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}