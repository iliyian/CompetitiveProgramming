// 分组优化思想
// 请自行在草稿纸上推演 O(n) 的美妙，也就是找规律然后优化罢了
// 1x(1x2+sum) + 3x(3x2+sum) + ... + 2x(2x2+sum') + ...

#include <bits/stdc++.h>
#define mod 10007
using namespace std;

int num[100001], color[100001], cnt[100001][2], sum[100001][2];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> num[i];
  for (int i = 1; i <= n; i++) {
    cin >> color[i];
    cnt[color[i]][i % 2]++;
    sum[color[i]][i % 2] += num[i];
    sum[color[i]][i % 2] %= mod;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += i * ((cnt[color[i]][i % 2] - 2) * num[i] % mod + sum[color[i]][i % 2]) % mod;
    ans %= mod;
  }
  cout << ans;
  return 0;
}