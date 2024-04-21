// date: 2023/11/10
// wa#01: 搞错N和输入数据的反常格式：对称表不给0

#include <bits/stdc++.h>
using namespace std;

int a[501][501];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);

  int N;
  cin >> N;
  for (int i = 1; i <= N ; i++)
    for (int j = 1; j <= N; j++) {
      if (i == j) a[i][j] = 0;
      else if (j > i) cin >> a[i][j];
      else a[i][j] = a[j][i];
    }

  int ans = -1;
  for (int i = 1; i <= N; i++) {
    sort(a[i] + 1, a[i] + N + 1);
    ans = max(ans, a[i][N - 1]);
  }
  cout << 1 << '\n' << ans;
  return 0;
}