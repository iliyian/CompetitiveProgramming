// date: 2024/01/26 13:42:56
// tag: 所谓的尺取法和双端点表示的单调队列，
// 以及基于操作的特殊性使用倍增操作法

#include <bits/stdc++.h>
#define int long long
#define N 1000005
using namespace std;

int n, k, m;

bitset<N> vis;

void solve() {
  cin >> n >> k >> m;
  vector<int> a(n + 1), nxt(n + 1);
  deque<int> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  nxt[1] = 1 + k;
  int head = 1, tail = 1 + k;
  for (int i = 2; i <= n; i++) {
    while (tail + 1 <= n && a[i] - a[head] > a[tail + 1] - a[i])
      head++, tail++;
    if (a[i] - a[head] < a[tail] - a[i])
      nxt[i] = tail;
    else
      nxt[i] = head;
  }

  vector<int> nxt2(n + 1), pos(n + 1);
  iota(pos.begin(), pos.end(), 0);
  while (m) {
    if (m & 1) {
      for (int i = 1; i <= n; i++)
        pos[i] = nxt[pos[i]];
    }

    for (int i = 1; i <= n; i++)
      nxt2[i] = nxt[nxt[i]];
    for (int i = 1; i <= n; i++)
      nxt[i] = nxt2[i];

    m >>= 1;
  }
  for (int i = 1; i <= n; i++)
    cout << pos[i] << ' ';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _;
  // cin >> _;
  int _ = 1;
  while (_--)
    solve();
}