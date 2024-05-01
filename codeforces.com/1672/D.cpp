// date: 2024-05-01 14:02:36
// tag: 双指针

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  int i = n, j = n;

  vector<int> cnt(n + 1);
  while (j) {
    if (a[i] == b[j]) {
      i--, j--;
    } else {
      if (b[j] == b[j + 1]) {
        cnt[b[j--]]++;
      } else if (cnt[a[i]]) {
        cnt[a[i--]]--;
      } else {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
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