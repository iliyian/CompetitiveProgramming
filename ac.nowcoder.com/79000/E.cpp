#include <bits/stdc++.h>
#define int long long
#define N 100005
#define lc p << 1
#define rc p << 1 | 1
using namespace std;

vector<int> pos[N * 2];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pos[x + N].push_back(i);
  }
  for (int _ = 1; _ <= q; _++) {
    int l, r, t;
    cin >> l >> r >> t;
    t += N;
    r--, l--;
    int p = (r - l + 1) / n, cnt = 0;
    if (r / n == l / n) {
      r %= n, l %= n;
      int lt = lower_bound(pos[t].begin(), pos[t].end(), l)
         - pos[t].begin();
      int rt = upper_bound(pos[t].begin(), pos[t].end(), r)
         - pos[t].begin() - 1;
      cnt = rt - lt + 1;
    } else {
      cnt += (r / n - (l / n + 1)) * pos[t].size();
      l %= n, r %= n;
      cnt += pos[t].size() - (lower_bound(pos[t].begin(), pos[t].end(), l)
         - pos[t].begin() - 1);
      cnt += upper_bound(pos[t].begin(), pos[t].end(), r)
         - pos[t].begin() - 1;
    }
    cout << cnt * (cnt - 1) / 2 << '\n';
  }

  return 0;
}