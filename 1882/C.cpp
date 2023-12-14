#include <bits/stdc++.h>
#define N 200005
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}