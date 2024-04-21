#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  map<int, int> cnt;
  int ma = -1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
    ma = max(ma, x);
  }
  for (int i = 0; i <= ma; i++) {
    if (!cnt[i] || (i > 0 && cnt[i] > cnt[i - 1])) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}