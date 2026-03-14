#include <bits/stdc++.h>
using namespace std;
const int Mod = 1'000'000'007;
void upd(int &x, int y) {
  x += y;
  if (x >= Mod)
    x -= Mod;
}
int n, m, k, f[105][105][8005], tr[128][8005];
int E(int sum, int mul, int cur) { return (sum * k + mul) * k + cur; }
char s[155][155];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  int MxS = k * k * k;
  for (int sum = 0; sum < k; sum++) {
    for (int mul = 0; mul < k; mul++) {
      for (int cur = 0; cur < k; cur++) {
        for (char dig = '0'; dig <= '9'; dig++)
          tr[dig][E(sum, mul, cur)] = E(sum, mul, (cur * 10 + dig - '0') % k);
        tr['+'][E(sum, mul, cur)] = E((sum + mul * cur) % k, 1, 0);
        tr['-'][E(sum, mul, cur)] = E((sum + mul * cur) % k, k - 1, 0);
        tr['*'][E(sum, mul, cur)] = E(sum, (mul * cur) % k, 0);
      }
    }
  }
  for (int i = 1; i <= n; i++)
    scanf("%s", s[i] + 1);
  s[n][m + 1] = '+';
  f[1][1][E(0, 1, (s[1][1] - '0') % k)] = 1;
  for (int x = 1; x <= n; x++)
    for (int y = 1 + (x == 1); y <= m + (x == n); y++) {
      char ch = s[x][y];
      for (int st = 0; st < MxS; st++) {
        if (isdigit(ch) or isdigit(s[x - 1][y]))
          upd(f[x][y][tr[ch][st]], f[x - 1][y][st]);
        if (isdigit(ch) or isdigit(s[x][y - 1]))
          upd(f[x][y][tr[ch][st]], f[x][y - 1][st]);
      }
    }
  printf("%d\n", f[n][m + 1][E(0, 1, 0)]);
  return 0;
}
