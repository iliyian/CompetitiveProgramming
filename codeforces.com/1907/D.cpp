// date: 2023/12/7
// tag: wisdom

#include <bits/stdc++.h>
#define N 200005
using namespace std;

int l[N], r[N];

int n;

bool check(int mid) {
  int lmax = 0, rmin = 0;
  for (int i = 1; i <= n; i++) {
    // possible current position
    lmax = max(lmax - mid, l[i]);
    rmin = min(rmin + mid, r[i]);
    if (lmax > rmin) return false;
  }
  return true;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  int lans = 0, rans = 0x3f3f3f3f, ans = -1;
  while (lans <= rans) {
    int mid = lans + (rans - lans >> 1);
    if (check(mid)) rans = mid - 1, ans = mid;
    else lans = mid + 1;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}