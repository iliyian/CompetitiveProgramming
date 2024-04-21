#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[200001], n, x;

bool check(int h) {
  int cost = 0;
  for (int i = 0; i < n; i++)
    cost += max(0ll, h - a[i]);
  return cost <= x;
}

void solve() {
  cin >> n >> x;
  int r = -1;
  for (int i = 0; i < n; i++)
    cin >> a[i], r = max(r, a[i]);
  int l = 0, ans = r + 1;
  r += x;
  while (l <= r) {
    int mid = l + (r - l >> 1);
    if (check(mid)) l = mid + 1, ans = mid;
    else r = mid - 1;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}