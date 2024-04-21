#include <bits/stdc++.h>
using namespace std;

int r[50], b[50], w[50], n, m;

int solve(int s, int t) {
  int sum = 0;
  for (int i = 0; i < s; i++) sum += w[i];
  for (int i = s; i < t; i++) sum += b[i];
  for (int i = t; i < n; i++) sum += r[i];
  return sum;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    r[i] = b[i] = w[i] = 0;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < m; j++) {
      r[i] += str[j] != 'R',
      w[i] += str[j] != 'W',
      b[i] += str[j] != 'B';
    }
  }
  int ans = 0x3f3f3f3f;
  for (int s = 1; s <= n - 2; s++) {
    for (int t = s + 1; t <= n - 1; t++) {
      ans = min(ans, solve(s, t));
    }
  }
  cout << ans;
  return 0;
}