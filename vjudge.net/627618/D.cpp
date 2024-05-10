#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;

  auto ask = [](int x, int y) {
    cout << "? " << x << ' ' << y << '\n';
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
  };

  vector<int> vis(n + 1);
  
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}