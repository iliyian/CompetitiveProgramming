#include <bits/stdc++.h>
#define N 300005
using namespace std;

int a[N], s[N];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("D.in", "r", stdin);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = n; i >= 1; i--)
    s[i] = s[i + 1] + a[i];
  sort(s + 1, s + 1 + n, greater<int>());
  int ans = 0;
  for (int i = 1; i < k; i++)
    ans += s[i];
  cout << ans;
}