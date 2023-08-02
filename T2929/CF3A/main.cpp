#include <bits/stdc++.h>
using namespace std;

int main() {
  char sx, sy, tx, ty;
  string ans;
  int cnt = 0;
  cin >> sx >> sy >> tx >> ty;
  sx = sx - 'a' + 1, tx = tx - 'a' + 1;
  sy = sy - '0', ty = ty - '0';
  while (sx != tx || sy != ty) {
    if (sx < tx) ans += 'R', sx++;
    if (sx > tx) ans += 'L', sx--;
    if (sy < ty) ans += 'U', sy++;
    if (sy > ty) ans += 'D', sy--;
    cnt++;
    ans += '\n';
  }
  cout << cnt << '\n' << ans;
  return 0;
}