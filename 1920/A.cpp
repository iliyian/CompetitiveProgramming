// date: 2024/01/30 21:59:27
// tag: 水

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> neq;
  int lmit = -0x3f3f3f3f, rmit = 0x3f3f3f3f;
  for (int i = 0; i < n; i++) {
    int op, x;
    cin >> op >> x;
    if (op == 1) {
      lmit = max(lmit, x);
    } else if (op == 2) {
      rmit = min(rmit, x);
    } else {
      neq.push_back(x);
    }
  }
  int ans = rmit - lmit + 1;
  ans -= count_if(neq.begin(), neq.end(), [&](const int x) {
    return lmit <= x && x <= rmit;
  });
  cout << max(0, ans) << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}