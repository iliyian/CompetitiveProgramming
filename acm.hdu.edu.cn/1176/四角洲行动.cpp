#include <bits/stdc++.h>
#define ll long long
#define N 2005
#define INF -50005
using namespace std;
int a, b, c, d, v[10][N], ans;
int get4() {
  if (v[4][0])
    return v[4][v[4][0]];
  return 0;
}
int get3() {
  if (v[3][0])
    return v[3][v[3][0]];
  return 0;
}
int get2() {
  if (v[2][0])
    return v[2][v[2][0]];
  return 0;
}
int get22() {
  if (v[2][0] > 2)
    return v[2][v[2][0] - 1];
  return 0;
}
int get1() {
  if (v[1][0])
    return v[1][v[1][0]];
  return 0;
}
int get12() {
  if (v[1][0] > 1)
    return v[1][v[1][0] - 1];
  return 0;
}
int get13() {
  if (v[1][0] > 2)
    return v[1][v[1][0] - 2];
  return 0;
}
int get14() {
  if (v[1][0] > 3)
    return v[1][v[1][0] - 3];
  return 0;
}
void solve() {
  ans = 0;
  cin >> a >> b >> c >> d;
  v[5][0] = v[6][0] = v[7][0] = 0;
  for (int i = 1; i <= 4; i++) {
    cin >> v[i][0];
    for (int j = 1; j <= v[i][0]; j++)
      cin >> v[i][j];
    sort(v[i] + 1, v[i] + v[i][0] + 1);
  }
  while (a--) {
    if (get1())
      ans += get1(), v[1][0]--;
    else
      break;
  }
  for (int i = 0; i <= b && i <= v[2][0]; i++) {
    for (int j = 0; j <= c && j <= v[3][0]; j++) {
      for (int k = 0; j + k <= c; k++) {
        for (int l = 0; l <= d && l <= v[4][0]; l++) {
          int x = (b - i) * 2 + k + 3 * (c - j - k) +
        }
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--)
    solve();
  return 0;
}