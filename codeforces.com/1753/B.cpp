// date: 2024-05-28 21:03:05
// tag: 进制，构造

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int n, x;
  cin >> n >> x;

  vector<int> a(n + 1), v(x + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    v[a[i]]++;
  }
  for (int i = 1; i < x; i++) {
    v[i + 1] += v[i] / (i + 1);
    v[i] %= i + 1;
    if (v[i]) {
      cout << "No\n";
      return 0;
    }
  }
  cout << (v[x] ? "Yes\n" : "No\n");

  return 0;
}