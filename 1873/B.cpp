#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int mi = 10, ans = 1, cnt = 0;
  for (int i = 0; i < n; i++)
    cin >> a[i], mi = min(mi, a[i]),
      ans *= max(a[i], 1), cnt += !a[i];
  if (cnt >= 2) {
    cout << 0 << '\n';
  } else if (cnt == 1) {
    cout << ans << '\n';
  } else cout << (ans / mi * (mi + 1)) << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}