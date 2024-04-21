#include <bits/stdc++.h>
#define N 200005
// #define int long long
using namespace std;

int a[N], n, len;

bool check(int mid) {
  for (int l = 1; l <= len - mid + 1; l++) {
    int r = l + mid - 1;
    if (a[r] - a[l] < n)
      return true;
  }
  return false;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a + 1, a + 1 + n);
  len = unique(a + 1, a + 1 + n) - (a + 1);
  // int l = 1, r = len, ans = -1;
  // while (l <= r) {
  //   int mid = (l + r) / 2;
  //   if (check(mid)) l = mid + 1, ans = mid;
  //   else r = mid - 1;
  // }  
  int l = 1, r = 1, ans = -1;
  while (r <= len) {
    for (; r <= len; r++) {
      if (a[r] - a[l] >= n)
        break;
    }
    ans = max(ans, r - l);
    l++;
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}