#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), f(n + 1), mx(n + 1, -0x3f3f3f3f);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    f[i] = max(f[i - 1], mx[a[i]] + i);
    mx[a[i]] = max(mx[a[i]], f[i - 1] - i + 1);
  }
  cout << f[n] << '\n';
}
// f[i] = max(f[i], f[j - 1] + i - j + 1(a[i] == a[j]));

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}