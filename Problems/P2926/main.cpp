#include <bits/stdc++.h>
using namespace std;

int a[100001], cnt[1000001], t[1000001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, maxn = -1;
  cin >> n;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++)
    cin >> a[i], maxn = max(maxn, a[i]), t[a[i]]++;
  // 为什么 maxn <<< n ?????
  // 存在大量重复数字 ?????
  for (int i = 1; i <= maxn; i++) {
    if (!t[i]) continue;
    for (int j = 1; j * i <= maxn; j++) {
      if (t[i * j]) cnt[i * j] += t[i];
    }
  }
  for (int i = 0; i < n; i++)
    cout << cnt[a[i]] - 1 << '\n';
  return 0;
}