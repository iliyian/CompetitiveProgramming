#include <bits/stdc++.h>
using namespace std;

int a[200001], f[200001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int N, L, R, ans = -0x3f3f3f3f;
  cin >> N >> L >> R;
  deque<int> q;
  memset(f, -0x3f, sizeof(f));
  f[0] = 0;
  for (int i = 0; i <= N; i++)
    cin >> a[i];
  for (int i = L; i <= N; i++) {
    while (!q.empty() && q.front() < i - R)
      q.pop_front();
    while (!q.empty() && f[q.back()] < f[i - L])
      q.pop_back();
    q.push_back(i - L);
    // q.front() == before == i - L
    f[i] = f[q.front()] + a[i];
    if (i + R > N)
      ans = max(ans, f[i]);
  }
  cout << ans << '\n';
  return 0;
}