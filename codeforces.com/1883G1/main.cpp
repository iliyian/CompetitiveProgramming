// date: 2023/12/11
// sort doesn't matters

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int _; cin >> _;
  while (_--) {
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    a.push_back(1);
    for (int i = 0; i < n - 1; i++) {
      int x; cin >> x;
      a.push_back(x);
    }
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int cur = 0, cnt = 0;
    for (int i = 0; i < a.size(); i++) {
      int idx = upper_bound(b.begin() + cur, b.end(), a[i]) - b.begin();
      if (idx == n) break;
      cnt++;
      cur = idx + 1;
    }
    cout << n - cnt << '\n';
  } 
}