// date: 2024-03-29 16:58:20
// tag: 模拟，构造，排序
// AC

#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<array<int, 2>> cnt(N);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> b = a;
  sort(b.begin() + 1, b.end());
  for (int i = 1; i <= n; i++) {
    cnt[b[i]][i % 2]++;
  }
  for (int i = 1; i <= n; i++) {
    if (!cnt[a[i]][i % 2]) {
      cout << "NO\n";
      return;
    }
    cnt[a[i]][i % 2]--;
  }
  cout << "YES\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}