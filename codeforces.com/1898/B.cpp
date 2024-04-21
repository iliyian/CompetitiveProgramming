#include <bits/stdc++.h>
#define N 200001
#define int long long
using namespace std;

int a[N];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int cur = a[n], ans = 0;
  for (int i = n; i >= 2; i--) {
    int t = ceil(double(a[i-1]) / a[i]);
    a[i - 1] = a[i - 1] / t;
    ans += t - 1;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}