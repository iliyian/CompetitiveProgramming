#include <bits/stdc++.h>
#define N 100001
using namespace std;

int b[N << 2], maxd[N << 2], mind[N << 2], d[N << 2];

void solve() {
  int n, m;
  cin >> m >> n;

  memset(mind, 0x3f, sizeof(mind));
  memset(maxd, -0x3f, sizeof(maxd));
  memset(b, 0, sizeof(b));
  memset(d, 0, sizeof(d));

  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    b[l]++, b[r + 1]--;
  }
  int maxn = -1, minn = 1, num = 0;
  for (int i = 0; i < n; i++) {
    num += b[i];
    maxn = max(maxn, num), minn = min(minn, num);
  }
  cout << maxn - minn << '\n';
}

int main() {
  freopen("C.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}