#include <bits/stdc++.h>
using namespace std;

int sum[500001], a[500001];

int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m, ans = -0x3f3f3f3f;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i], sum[i] = sum[i - 1] + a[i];
  deque<int> q;
  q.push_back(0);
  for (int i = 1; i <= n; i++) {
    while (!q.empty() && q.front() + m < i)
      q.pop_front();
    ans = max(ans, sum[i] - sum[q.front()]);
    while (!q.empty() && sum[q.back()] >= sum[i])
      q.pop_back();
    q.push_back(i);
  }
  cout << ans;
  return 0;
}