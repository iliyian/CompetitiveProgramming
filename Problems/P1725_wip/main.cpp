#include <bits/stdc++.h>
using namespace std;

int a[200000], f[200000];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int N, L, R, ans = -1;
  cin >> N >> L >> R;
  deque<int> q;
  for (int i = 0; i <= N; i++)
    cin >> a[i];
  for (int i = 0; i <= N; i++) {
    while (!q.empty() && q.front() < i - L) q.pop_front();
    while (!q.empty() && a[q.back()] >= a[i - L]) q.pop_back();
    q.push_back(i - L);
    f[i] = f[q.front()] + a[i];
    if (i + R > N)
      ans = max(ans, f[i]);
  }
  cout << ans;
  return 0;
}