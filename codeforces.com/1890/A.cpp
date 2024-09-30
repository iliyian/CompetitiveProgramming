#include <bits/stdc++.h>
using namespace std;

int a[101];
map<int, int> cnt;
// a + b = b + a = c + d

void solve() {
  int n, sum = 0, maxn, maxcnt = -1;
  cin >> n;
  cnt.clear();
  for (int i = 0; i < n; i++) {
    cin >> a[i], cnt[a[i]]++;
  }
  if (cnt.size() > 2) {
    cout << "NO\n";
    return;
  }
  if (abs(cnt.begin()->second - cnt.rbegin()->second) > 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}