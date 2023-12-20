#include <bits/stdc++.h>
#define N 105
using namespace std;

int d[N], s[N];

void solve() {
  int n;
  cin >> n;
  int ans = 0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    cin >> d[i] >> s[i];
    ans = min(ans, d[i] - 1 + (s[i] - 1) / 2 + 1);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}