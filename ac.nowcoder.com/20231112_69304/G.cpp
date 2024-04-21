#include <bits/stdc++.h>
using namespace std;

int a[100002], d[100002], n, k;
bitset<100002> vis;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("G.in", "r", stdin);
  cin >> n >> k;
  a[1] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > 7)
      a[i] = a[i - 1], vis[i] = true;
    d[i] = a[i] - a[i - 1];
    if (abs(d[i]) > k && i > 1) {
      vis[i] = true;
      if (i < n && abs(a[i + 1] - a[i - 1]) <= k * 2)
        a[i] = (a[i + 1] + a[i - 1]) / 2;
      else a[i] = a[i - 1];
    }
  }
  cout << vis.count();
  return 0;
}