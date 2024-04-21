// date: 2024-03-13 20:43:43
// tag: 2-sat
// wa#01: 输出答案错误
// wa#02: 比的是scc的值而不是索引...写成3-sat
// tle#03: 疑似卡常过分了？hack1疑似所有题解都过不了？

#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int n, d;
  cin >> n >> d;
  string str;
  cin >> str;
  str = '#' + str;
  int m;
  cin >> m;
  vector<int> hx(m + 1), hy(m + 1);
  vector<char> ha(m + 1), hb(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> hx[i] >> ha[i] >> hy[i] >> hb[i];
    ha[i] = tolower(ha[i]), hb[i] = tolower(hb[i]);
  }

  vector<int> pos;

  for (int i = 1; i <= n; i++) {
    if (str[i] == 'x') {
      pos.push_back(i);
    }
  }

  auto change = [&str](int x, char h, bool f) {
    int t = (x - 1) * 2;
    if (str[x] == 'a') {
      if (h != 'b') t++;
    }
    if (str[x] == 'b') {
      if (h != 'a') t++;
    }
    if (str[x] == 'c') {
      if (h != 'a') t++;
    }
    return t ^ f;
  };

  auto check = [&]() {
    vector<vector<int>> g(n * 2);

    for (int i = 1; i <= m; i++) {
      if (str[hx[i]] == ha[i]) continue;
      if (str[hy[i]] == hb[i]) {
        // x可行接不可行
        g[change(hx[i], ha[i], false)].push_back(change(hx[i], ha[i], true));
      } else {
        g[change(hx[i], ha[i], false)].push_back(change(hy[i], hb[i], false));
        g[change(hy[i], hb[i], true)].push_back(change(hx[i], ha[i], true));
      }
    }

    vector<int> dfn(n * 2), low(n * 2), scc(n * 2);
    vector<bool> ins(n * 2);
    stack<int> s;
    int dfncnt = 0, scc_cnt = 0;

    auto tarjan = [&](auto self, int u) -> void {
      dfn[u] = low[u] = ++dfncnt;
      ins[u] = true;
      s.push(u);
      for (int v : g[u]) {
        if (!dfn[v]) {
          self(self, v);
          low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
          low[u] = min(low[u], dfn[v]);
        }

      }
      if (dfn[u] == low[u]) {
        ++scc_cnt;
        while (true) {
          int x = s.top(); s.pop();
          ins[x] = false;
          scc[x] = scc_cnt;
          if (x == u) break;
        }
      }
    };

    for (int i = 0; i < n * 2; i++) {
      if (!dfn[i]) {
        tarjan(tarjan, i);
      }
    }
    for (int i = 0; i < n * 2; i += 2) {
      if (scc[i] == scc[i ^ 1]) {
        return;
      }
    }

    for (int i = 1; i <= n; i++) {
      int x = (i - 1) * 2;
      if (str[i] == 'a') {
        if (scc[x] < scc[x ^ 1]) cout << 'B';
        else cout << 'C';
      } else if (str[i] == 'b') {
        if (scc[x] < scc[x ^ 1]) cout << 'A';
        else cout << 'C';
      } else if (str[i] == 'c') {
        if (scc[x] < scc[x ^ 1]) cout << 'A';
        else cout << 'B';
      }
    }

    exit(0);
  };

  auto dfs = [&](auto self, int cur) {
    if (cur == d) {
      check();
      return;
    }
    for (int i = 0; i < 2; i++) {
      str[pos[cur]] = i + 'a';
      self(self, cur + 1);
    }
  };
  dfs(dfs, 0);
  cout << -1 << '\n';

  return 0;
}