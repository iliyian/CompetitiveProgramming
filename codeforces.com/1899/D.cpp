#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  // 离散化也成
  map<int, int> cnt;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ans += cnt[a];
    if (a == 2) ans += cnt[1];
    else if (a == 1) ans += cnt[2];
    cnt[a]++;
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