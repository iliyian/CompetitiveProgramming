#include <bits/stdc++.h>
#define int long long
using namespace std;

// What are you doing at the end of the world? Are you busy? Will you save us?
// What are you doing while sending {}? Are you busy? Will you send {}?"
// an = 139 * 2 ^ (n-1) - 64 ?

int len = 77, b = 64;
string str = "\"What are you doing at the end of the world? Are you busy? Will you save us?\"";
array<string, 3> strs = {
  "\"What are you doing while sending ",
  "? Are you busy? Will you send ",
  "?\""
};
// [1, 33]
// [34, 34 + 139*2^(n-2)-64 - 1]
// [34 + 138*2^(n-2)-64, ]

char query(int n, int k) {
  if (n == 0) return k <= len ? str[k] : '.';
  int prv = 141 * (1 << n - 1) - 64;
  if (k <= 34) return strs[0][k];
  if (k <= 35 + prv - 1) return query(n - 1, k - 34);
  if (k <= 35 + prv + 29 - 1) return strs[1][k - 34 - prv];
  if (k <= prv * 2 + 64 - 1) return query(n - 1, k - prv - 64);
  if (k <= prv * 2 + 65) return '?';
  return '.';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int n, k;
    cin >> n >> k;
    cout << query(n, k);
  }

  return 0;
}


