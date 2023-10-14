#include <bits/stdc++.h>
using namespace std;

double f[10001][10001];

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int N, A, Q;
  cin >> N >> A >> Q;
  double P = A / 100.0;
  f[0][0] = 1;
  if (N > 50) {
    cout << "1.000";
    return 0;
  }
  for (int i = 1; i <= N; i++) {
    char c;
    cin >> c;
    for (int j = 0; j <= i; j++) {
      if (c == '0')
        f[i][j] = f[i - 1][j] * P + 
          (j ? f[i - 1][j - 1] * (1 - P) : 0);
      else
        f[i][j] = f[i - 1][j] * (1 - P) + 
          (j ? f[i - 1][j - 1] * P : 0);
    }
  }
  double ans = 0;
  for (int i = Q; i <= N; i++)
    ans += f[N][i];
  cout << fixed << setprecision(3) << ans;
  return 0;
}