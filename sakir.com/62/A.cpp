#include <bits/stdc++.h>
// #define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  string str;
  int k;
  cin >> str >> k;

  int len = min(signed(str.size()), 5);
  string s = str.substr(0, len);
  vector<string> v;
  for (int le = 1; le <= len; le++) {
    for (int l = 0; l + le <= str.size(); l++) {
      int r = l + le;
      v.push_back(str.substr(l, r - l));
    }
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  sort(v.begin(), v.end());
  for (auto i : v) {
    cout << i << ' ';
  }
  cout << '\n';
  cout << v[k - 1];

  return 0;
}