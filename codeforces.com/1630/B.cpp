// date: 2024-04-23 13:31:48
// tag: 构造，滑动窗口

// 先解决核心，再解决形式。
// 对于一个问题，如果发现它的具体形式考虑起来非常复杂，
// 那么不妨把具体的形式扔掉，寻找它背后隐藏的规律和性质，
// 回到最根本的问题和要求中去，等确定了这些问题的答案，
// 再反过来去确定具体的形式。

// 本题中具体表现为首先确定y-x的必然最小值，再确定划分

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> id(n + 1);
  iota(id.begin() + 1, id.end(), 1);
  sort(id.begin(), id.end(), [&](const int &x, const int &y) {
    return a[x] < a[y];
  });
  int len = n - (n - k) / 2, x = id[1], y = id[n];
  for (int r = len, l = 1; r <= n; r++, l++) {
    if (a[id[r]] - a[id[l]] < a[y] - a[x]) {
      y = id[r], x = id[l];
    }
  }
  x = a[x], y = a[y];
  cout << x << ' ' << y << '\n';
  vector<int> b(n + 1);
  int cnt = 0;
  for (int i = 1, prv = 0; i <= n; i++) {
    cnt += a[i] >= x && a[i] <= y;
    if (i - prv - cnt < cnt) {
      b[i] = true;
      cnt = 0, prv = i;
    }
  }
  cnt = 0;
  for (int i = 1, prv = 1; i <= n; i++) {
    if (b[i] && cnt < k - 1 || i == n) {
      cout << prv << ' ' << i << '\n';
      prv = i + 1;
      cnt++;
    }
  }
  cout << '\n';
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