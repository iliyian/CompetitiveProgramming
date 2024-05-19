#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int n, vall, valr;
  cin >> n >> vall >> valr;
  vector<int> a(n + 1), s(n + 1), id(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
    id[i] = i;
  }
  vector<int> d((n + 2) << 1);
  auto add = [&](int x, int c) {
    for (int i = x + 1; i <= n + 1; i += i & -i) {
      d[i] += c;
    }
  };
  auto sum = [&](int x) {
    int ans = 0;
    for (int i = x + 1; i > 0; i -= i & -i) {
      ans += d[i];
    }
    return ans;
  };
  sort(id.begin(), id.end(), [&s](const int &x, const int &y) {
    return s[x] < s[y];
  });
  int ans = 0;
  int l = 0, rl = 0, rr = -1;
  while (l <= n) {
    while (rl <= n && s[id[rl]] - s[id[l]] < vall) add(id[rl++], -1);
    while (rr < n && s[id[rr + 1]] - s[id[l]] <= valr) add(id[++rr], 1);
    ans += sum(n) - sum(id[l]);
    l++;
  }
  cout << ans << '\n';

  return 0;
}