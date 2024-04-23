// date: 2024-04-21 21:36:46
// tag: 注意，非标准并查集，不需要记录历史

#include <bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> pa(N);
  iota(pa.begin(), pa.end(), 0);
  auto find = [&](auto self, int x) -> int {
    return x == pa[x] ? x : pa[x] = self(self, pa[x]);
  };
  vector<array<int, 3>> q(n + 1);
  deque<int> a;
  for (int i = 1; i <= n; i++) {
    cin >> q[i][0];
    if (q[i][0] == 1) {
      cin >> q[i][1];
    } else {
      cin >> q[i][1] >> q[i][2];
    }
  }
  for (int i = n; i >= 1; i--) {
    if (q[i][0] == 2) {
      pa[q[i][1]] = pa[q[i][2]];
    } else {
      a.push_front(pa[q[i][1]]);
    }
  }

  for (auto x : a) {
    cout << x << ' ';
  }

  return 0;
}