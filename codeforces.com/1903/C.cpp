// 后缀和数组真 tmd 妙
// 层层叠叠

#include <bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;

int a[N], sum[N];

// big brother is watching you

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sum[n + 1] = 0;
  for (int i = n; i >= 1; i--)
    // suffix
    sum[i] = a[i] + sum[i + 1];
  int ans = sum[1]; // basis
  for (int i = 2; i <= n; i++) {
    if (sum[i] > 0)
      ans += sum[i];
  }
  cout << ans << '\n';
  return;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}