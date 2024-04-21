#include <bits/stdc++.h>
#define N 200001
using namespace std;

int pos[N], p[N];
int n, m, d;

int check(int x, int y) {
  int left = pos[y] - pos[x];
  int right = pos[x] + d - pos[y] + 1;
  if (d >= n - 1) right = 0x3f3f3f3f;
  return min(left, right);
}

void solve() {
  cin >> n >> m >> d;
  for (int i = 1; i <= n; i++)
    cin >> p[i], pos[p[i]] = i;
  int prev, a, ans = 0x3f3f3f3f;;
  cin >> prev;
  for (int i = 1; i < m; i++) {
    cin >> a;
    if (pos[prev] < pos[a] && pos[a] <= pos[prev] + d) {
      ans = min(ans, check(prev, a));
    } else {
      ans = 0;
    }
    prev = a;
  }
  cout << (ans == 0x3f3f3f3f ? -1 : ans) << '\n';
}

int main() {
  freopen("B.in", "r", stdin);
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}