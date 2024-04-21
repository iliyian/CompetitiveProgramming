#include <bits/stdc++.h>
using namespace std;

int a[100001], mind[100001], sum[100001];
bitset<100001> vis;

void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= 30; i++)
    mind[i] = i;
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i <= q; i++) {
    int x;
    cin >> x;
    for (int j = 1; j <= 30; j++)
      if (mind[j] >= x)
        mind[j] = x - 1, sum[j] += 1 << x - 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 30; j >= 1; j--) {
      if (a[i] % (1 << j) == 0) {
        a[i] += sum[j];
        break;
      }
    }
    cout << a[i] << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("B.in", "r", stdin);
  int t; cin >> t;
  while (t--) solve();
  return 0;
}