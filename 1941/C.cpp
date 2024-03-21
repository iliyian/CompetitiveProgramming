#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  int ans = 0;
  int pre = 0, pos;
  vector<int> a;
  while ((pos = str.find("pie", pre)) != string::npos) {
    a.push_back(pos);
    pre = pos + 1;
  };
  pre = 0;
  while ((pos = str.find("map", pre)) != string::npos) {
    a.push_back(pos);
    pre = pos + 1;
  };
  sort(a.begin(), a.end());
  for (int i = 0; i < signed(a.size()) - 1; i++) {
    if (a[i] < a[i + 1] - 2) {
      ans++;
    }
  }
  if (!a.empty()) ans++;
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}