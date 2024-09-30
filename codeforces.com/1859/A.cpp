#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int mi = 0x3f3f3f3f;
  for (int i = 0; i < n; i++)
    cin >> a[i], mi = min(mi, a[i]);
  sort(a.begin(), a.end());
  int cnt = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == mi) {
      cnt++;
    } else {
      break;
    }
  }
  if (cnt == a.size()) {
    cout << "-1\n";
    return;
  }
  cout << cnt << ' ' << a.size() - cnt << '\n';
  for (int i = 0; i < a.size(); i++) {
    if (i == cnt) cout << '\n';
    cout << a[i] << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}