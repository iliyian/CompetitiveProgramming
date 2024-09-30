#include <bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;

int a[N], id[N], sum[N], nxt[N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int _; cin >> _;
  while (_--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    iota(id + 1, id + 1 + n, 1);
    sort(id + 1, id + 1 + n, [&](const int &x, const int &y) {
      return a[x] < a[y];
    });
    map<int, int> ans;
    for (int i = 1; i <= n; i++) {
      if (nxt[i - 1] >= i) {
        nxt[i] = nxt[i - 1];
        sum[i] = sum[i - 1];
        // avoid over adding
      } else {
        sum[i] = sum[i - 1] + a[id[i]];
        nxt[i] = i;
        while (nxt[i] + 1 <= n && sum[i] >= a[id[nxt[i] + 1]]) {
          sum[i] += a[id[nxt[i] + 1]];
          nxt[i]++;
        }
      }
      ans[a[id[i]]] = nxt[i] - 1;
    }
    for (int i = 1; i <= n; i++)
      cout << ans[a[i]] << " \n"[i == n];
  }
}