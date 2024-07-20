#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  string str;
  cin >> str;
  int cnt = 0;
  int tot = n;
  vector<int> pos(tot + 1, 1);
  array<stack<int>, 4> s;
  for (int i = 1; i <= tot; i++) {
    s[1].push(tot - i + 1);
  }
  auto dfs = [&](auto self, int a, int b, int c, int dep) -> void {
    if (dep == 0) {
      return;
    }
    self(self, a, c, b, dep - 1);
    pos[s[a].top()] = c;
    s[c].push(s[a].top());
    s[a].pop();
    cout << (++cnt) << ": ";
    for (int i = 1; i <= tot; i++) {
      cout << pos[i] - 1 << ' ';
    }
    cout << '\n';
    cout << cnt << ": ";
    for (int i = 0; i < tot; i++) {
      cout << (cnt >> i & 1) << ' ';
    }
    cout << '\n';
    // cout << a << "->" << c << '\n';
    self(self, b, a, c, dep - 1);
  };
  dfs(dfs, 1, 2, 3, tot);

  vector<char> ans(n);
  for (int i = 0; i < n; i++) {
    int x = str[n - i - 1] - '0';
    int a = 0;
    if (n - i - 2 >= 0) a += str[n - i - 1 - 1] - '0';
    if (n - i - 3 >= 0) a += 2 * (str[n - i - 3] - '0');
    a = (a + 1 + !(i % 2)) % 3;
    if (x == 0) a = ((a - 1) % 3 + 3) % 3;
    ans[n - i - 1] = 'A' + a;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i];
  }

  return 0;
}