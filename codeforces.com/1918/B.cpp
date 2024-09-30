#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  vector<pair<int, int>> c(n);
  for (int i = 0; i < n; i++)
    cin >> a[i], c[i].first = a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i], c[i].second = b[i];
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](const int &x, const int &y) {
    // int xsum = max(a[x] - (x + 1), 0) + max(b[x] - (x + 1), 0),
    //   ysum = max(a[y] - (y + 1), 0) + max(b[y] - (y + 1), 0);
    // int xsum = abs(a[x] - (x + 1)) + abs(b[x] - (x + 1)),
    //   ysum = abs(a[y] - (y + 1)) + abs(b[y] - (y + 1));
    int xsum = a[x] + b[x],
      ysum = a[y] + b[y];
    int xd = a[x] - b[x],
      yd = a[y] - b[y];
    if (xsum == ysum) return abs(xd) < abs(yd);
    return xsum < ysum;
  });
  for (int i = 0; i < n; i++)
    cout << a[id[i]] << " \n"[i == n - 1];
  for (int i = 0; i < n; i++)
    cout << b[id[i]] << " \n"[i == n - 1];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}