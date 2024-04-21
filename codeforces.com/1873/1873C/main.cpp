#include <bits/stdc++.h>
using namespace std;

int a[11][11] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
  {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
  {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
  {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
  {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
  {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
  {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
  {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  while (T--) {
    int ans = 0;
    char ch;
    for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++)
        cin >> ch, ans += (ch == 'X') * a[i][j];
    cout << ans << '\n';
  }
  return 0;
}