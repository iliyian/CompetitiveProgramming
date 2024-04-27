// date: 2024-04-25 14:45:01
// tag: 反集

#include <bits/stdc++.h>
#define int long long
#define N 1000000
using namespace std;

void solve() {
  int n, c;
  cin >> n >> c;
  vector<int> a(n + 1), s(c + 1);
  vector<int> exi(c + 1);
  vector<int> non;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    exi[a[i]] = true;
  }
  for (int i = 1; i <= c; i++) {
    s[i] = s[i - 1] + exi[i];
  }
  for (int i = 1; i <= c; i++) {
    if (!exi[i]) {
      non.push_back(i);
    }
  }

  for (int i = 1; i <= c; i++) {
    if (exi[i]) {
      for (auto r : non) {
        if (i * r > c) break;
        if (s[min(c, i * (r + 1) - 1)] - s[i * r - 1]) {
          cout << "No\n";
          return;
        }
      }
    }
  }
  cout << "Yes\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}