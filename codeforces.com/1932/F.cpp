// date: 2024-02-27 12:47:59
// tag: CE#01: 复制了两次上去

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 2);
  vector<array<int, 2>> seg(k + 1);
  for (int i = 1; i <= k; i++) {
    int l, r;
    cin >> l >> r;
    a[l]++, a[r + 1]--;
    seg[i] = {l, r};
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  sort(seg.begin(), seg.end(), [](const array<int, 2> &x, const array<int, 2> &y) {
    return x[1] < y[1];
  });
  vector<int> minl(k + 2);
  minl[k + 1] = 0x3f3f3f3f;
  for (int i = k; i >= 1; i--) {
    minl[i] = min(minl[i + 1], seg[i][0]);
  }
  vector<int> dp(n + 1);
  for (int i = 1; i <= n; i++) {
    int x = lower_bound(seg.begin() + 1, seg.end(), 
      array<int, 2>{0x3f3f3f3f, i},
      [](const array<int, 2> &x, const array<int, 2> &y){
        return x[1] < y[1];
      }) - seg.begin();
    if (minl[x] <= i) {
      dp[i] = max(dp[i - 1], dp[minl[x] - 1] + a[i]);
    } else {
      dp[i] = dp[i - 1];
    }
  }
  cout << dp[n] << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("F.in", "r", stdin);
  freopen("F.out", "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}