#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> pri = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void solve() {
  int n;
  cin >> n;
  for (int p : pri) {
    if (n % p) {
      cout << p << '\n';
      return;
    }
  }
  cout << n + 1 << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}