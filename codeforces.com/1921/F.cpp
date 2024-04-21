// date: 2024/02/15 13:19:51
// tag: 带权前缀和，根号分治，
// 关键在于分治后需要O(1)回答，tle的几次都是O(n)根据后缀和的前缀和来回答了，
// 但是可以直接用带权前缀和实现O(1)回答后缀和的前缀和
// 算是新知识的模板题了
// 
// 差分的前缀和和前缀和的差分都是原数组这点挺有意思

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int w = sqrt(n) + 0.5;
  vector<vector<int>> f(w, vector<int>(n + 1)), g(w, vector<int>(n + 1));
  for (int i = 1; i < w; i++) {
    for (int j = 1; j <= n; j++) {
      // 类似于几阶几阶
      f[i][j] = a[j] * (j / i) + (j - i >= 1 ? f[i][j - i] : 0);
      g[i][j] = a[j] + (j - i >= 1 ? g[i][j - i] : 0);
    }
  }
  for (int t = 0; t < q; t++) {
    int s, d, k;
    cin >> s >> d >> k;
    if (d >= w) {
      int ans = 0;
      for (int i = 1; i <= k; i++) {
        ans += a[s + (i - 1) * d] * i;
      }
      cout << ans << ' ';
    } else {
      int ans = f[d][s + d * (k - 1)] - (s - d >= 1 ? f[d][s - d] : 0);
      // 一般差分
      ans -= (s / d - 1) * (g[d][s + d * (k - 1)] - (s - d >= 1 ? g[d][s - d] : 0));
      // 修改权重
      cout << ans << ' ';
    }
  }
  cout << '\n';
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