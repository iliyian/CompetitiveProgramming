#include <bits/stdc++.h>
#define N 1005
using namespace std;

int a[N], n;

bool check(int mid) {
  vector<int> b(n);
  for (int i = 0; i < n; i++)
    b[i] = max(0, a[i] - mid);
  for (int i = 1; i < n; i++) {
    if (b[i] < b[i - 1])
      return false;
  }
  return true;
}

void solve() {
  cin >> n;
  int ma = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ma = max(ma, a[i]);
  }
  int l = 0, r = ma, ans = -1;
  while (l <= r) {
    int mid = l + (r - l >> 1);
    if (check(mid)) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}