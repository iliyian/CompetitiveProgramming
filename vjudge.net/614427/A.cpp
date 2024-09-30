#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int n;
  cin >> n;
  // vector<pair<double, double>> k(n + 1);
  unordered_map<double, set<int>> m;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    double x = a / b, y = c / d;
    double k1 = y / (x + 1), k2 = (y + 1) / x;
    // k[i] = {y / (x + 1), (y + 1) / x};

    

  }

  return 0;
}