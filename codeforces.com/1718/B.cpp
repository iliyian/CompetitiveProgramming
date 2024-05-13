// date: 2024-05-12 13:07:01
// tag: 贪心，模拟

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> fib;

void solve() {
  int k;
  cin >> k;
  vector<pair<int, int>> c(k);
  int sum = 0;
  for (int i = 0; i < k; i++) {
    cin >> c[i].first;
    sum += c[i].first;
    c[i].second = i + 1;
  }
  int pos = lower_bound(fib.begin(), fib.end(), sum + 1) - fib.begin();
  if (pos == fib.size()) {
    cout << "NO\n";
    return;
  }

  sort(c.begin(), c.end());
  int len = pos - 1, prv = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (c.back().first < fib[i]) {
      cout << "NO\n";
      return;
    }
    int r = c.size() - 1;
    int x = r;
    while (x > 0 && c[x - 1].first >= fib[i]) x--;

    bool f = false;
    for (int j = r; j >= x; j--) {
      if (c[j].second != prv) {
        f = true;
        c[j].first -= fib[i];
        prv = c[j].second;
        break;
      }
    }
    if (!f) {
      cout << "NO\n";
      return;
    }

    sort(c.begin(), c.end());
  }
  cout << "YES\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int pprv = 0, prv = 0, cur = 1;
  while (cur <= 1e12) {
    fib.push_back(cur);
    pprv = prv;
    prv = cur;
    cur = pprv + prv;
  }

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}