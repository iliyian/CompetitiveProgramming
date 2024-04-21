#include <bits/stdc++.h>
using namespace std;

int a[10001][101];
bitset<101> s[10001];
int ans = 0, n, m;

int turn(int i, int j) {
  int t = a[i][j];
  ans = (ans + t) % 20123;
  for (int k = 0; k < t; k++, j++) {
    if (j == m) j = 0;
    while (!s[i][j]) {
      j++;
      if (j == m) j = 0;
    }
  }
  return j - 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("data.in", "r", stdin);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      int sig;
      cin >> sig >> a[i][j];
      s[i][j] = sig;
    }
  }
  int S;
  cin >> S;
  for (int i = 1; i <= n; i++) {
    S = turn(i, S);
  }
  cout << ans;
  return 0;
}