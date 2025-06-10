#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const ull Mod = 1'0000'0000'0000'1029;
void read(ull &x) {
  x = 0;
  char c = getchar();
  while (!isdigit(c))
    c = getchar();
  while (isdigit(c)) {
    x = x * 10 + (c ^ '0');
    c = getchar();
  }
}
ull T, n, q, a[64];
int main() {
  freopen("binary.in", "r", stdin);
  freopen("binary.out", "wb", stdout);
  for (read(T); T; T--) {
    memset(a, -1, sizeof a);
    ull x, fin = 0;
    read(n);
    read(q);
    for (; n; n--) {
      read(x);
      for (int i = 0; i < 64; i++)
        if ((1ull << i) & x)
          a[i] &= x;
    }
    for (; q; q--) {
      read(x);
      ull ans = -1, cur = 0;
      for (int i = 63; i >= 0; i--) {
        if ((1ull << i) & x)
          cur |= a[i];
        else
          ans = min(ans, cur | a[i]);
      }
      fin ^= min(cur, ans) % Mod;
    }
    printf("%llu\n", fin);
  }
  return 0;
}
