#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1

void solve() {
  std::string str;
  std::cin >> str;
  int q;
  std::cin >> q;
  int n = str.size();
  str = '#' + str;
  std::vector<std::array<std::set<int>, 2>> a(n + 1);
  std::array<std::set<int>, 2> s;
  std::vector<int> l(n + 1), r(n + 1), len(n + 1);
  int prv = 1;
  for (int i = 2; i <= n; i++) {
    if (str[i] != str[i - 1]) {
      a[i - prv][str[i - 1] - '0'].insert(prv);
      s[str[i - 1] - '0'].insert(i - prv);
      len[prv] = i - prv;
      r[prv] = i;
      l[i] = prv;
      prv = i;
    }
  }
  a[n + 1 - prv][str[n] - '0'].insert(prv);
  s[str[n] - '0'].insert(n + 1 - prv);
  while (q--) {
    int op, x;
    std::cin >> op >> x;
    auto p = s[op].lower_bound(x);
    if (p == s[op].end()) {
      std::cout << -1 << '\n';
      continue;
    }
    int pos = *a[op][*p].begin();
    if (len[pos] == x) {
      int newlen = len[pos] + len[r[pos]];

      a[op][x].erase(pos);
      a[op ^ 1][len[r[pos]]].erase(r[pos]);
      a[op ^ 1][newlen].insert(pos);
      
      r[pos] = r[r[pos]];

      len[pos] += x;
    } else {
      int newpos = pos + x;

      a[op][x].erase(pos);
      a[op][len[pos]].insert(len[pos] - le);


      l[r[pos]] = newpos;
      r[newpos] = r[pos];
      r[pos] = newpos;
      l[newpos] = pos;
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}