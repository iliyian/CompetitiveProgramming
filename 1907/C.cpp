// darte: 2023/12/7
// tag: wisdom

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  map<char, int> cnt;
  int ma = -1;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    cnt[c]++;
    ma = max(ma, cnt[c]);
  }
  cout << max(n % 2, ma * 2 - n) << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}