/*

LLLLLLLLLLL             IIIIIIIIIIYYYYYYY       YYYYYYYIIIIIIIIII               AAA               NNNNNNNN        NNNNNNNN
L:::::::::L             I::::::::IY:::::Y       Y:::::YI::::::::I              A:::A              N:::::::N       N::::::N
L:::::::::L             I::::::::IY:::::Y       Y:::::YI::::::::I             A:::::A             N::::::::N      N::::::N
LL:::::::LL             II::::::IIY::::::Y     Y::::::YII::::::II            A:::::::A            N:::::::::N     N::::::N
  L:::::L                 I::::I  YYY:::::Y   Y:::::YYY  I::::I             A:::::::::A           N::::::::::N    N::::::N
  L:::::L                 I::::I     Y:::::Y Y:::::Y     I::::I            A:::::A:::::A          N:::::::::::N   N::::::N
  L:::::L                 I::::I      Y:::::Y:::::Y      I::::I           A:::::A A:::::A         N:::::::N::::N  N::::::N
  L:::::L                 I::::I       Y:::::::::Y       I::::I          A:::::A   A:::::A        N::::::N N::::N N::::::N
  L:::::L                 I::::I        Y:::::::Y        I::::I         A:::::A     A:::::A       N::::::N  N::::N:::::::N
  L:::::L                 I::::I         Y:::::Y         I::::I        A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N
  L:::::L                 I::::I         Y:::::Y         I::::I       A:::::::::::::::::::::A     N::::::N    N::::::::::N
  L:::::L         LLLLLL  I::::I         Y:::::Y         I::::I      A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N
LL:::::::LLLLLLLLL:::::LII::::::II       Y:::::Y       II::::::II   A:::::A             A:::::A   N::::::N      N::::::::N
L::::::::::::::::::::::LI::::::::I    YYYY:::::YYYY    I::::::::I  A:::::A               A:::::A  N::::::N       N:::::::N
L::::::::::::::::::::::LI::::::::I    Y:::::::::::Y    I::::::::I A:::::A                 A:::::A N::::::N        N::::::N
LLLLLLLLLLLLLLLLLLLLLLLLIIIIIIIIII    YYYYYYYYYYYYY    IIIIIIIIIIAAAAAAA                   AAAAAAANNNNNNNN         NNNNNNN

 * 
 * ==============================================================================
 * @Author : iliyian
 * @File   : E.cpp
 * @Time   : 2025-10-15 22:05:07
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

struct V_DCC {
  int n;
  std::vector<std::vector<int>> ver, col;
  std::vector<std::vector<std::pair<int, int>>> eCol;
  std::vector<std::pair<int, int>> eS;
  std::vector<int> dfn, low, S;
  int now, cnt;
  std::vector<bool> point;
  V_DCC(int n) : n(n) {
    ver.resize(n + 1);
    dfn.resize(n + 1);
    low.resize(n + 1);
    col.resize(n * 2 + 1);
    eCol.resize(n * 2 + 1);
    point.resize(n + 1);
    S.clear();
    eS.clear();
    cnt = now = 0;
  }
  void add(int x, int y) {
    if (x == y) return;
    // ver[x].insert(y);
    // ver[y].insert(x);
    ver[x].push_back(y);
    ver[y].push_back(x);
  }
  void tarjan(int x, int root) {
    low[x] = dfn[x] = ++now;
    S.push_back(x);
    if (x == root && !ver[x].size()) {
      ++cnt;
      col[cnt].push_back(x);
      // col[cnt].insert(x);
      return;
    }
    int flag = 0;
    for (auto y : ver[x]) {
      if (dfn[y] == 0 || dfn[y] < dfn[x]) {
        eS.push_back({x, y});
      }
      if (!dfn[y]) {
        tarjan(y, root);
        low[x] = std::min(low[x], low[y]);
        if (dfn[x] <= low[y]) {
          eS.push_back({x, y});
          flag++;
          if (x != root || flag > 1) {
            point[x] = true;
          }
          int pre = 0;
          cnt++;
          do {
            pre = S.back();
            col[cnt].push_back(pre);
            S.pop_back();
          } while (pre != y);
          int _x, _y;
          do {
            _x = eS.back().first, _y = eS.back().second;
            if (_x > _y && x < y || _x < _y && x > y) std::swap(_x, _y);
            eCol[cnt].push_back({_x, _y});
          } while (_x != x || _y != y);
          col[cnt].push_back(x);
        }
      } else {
        low[x] = std::min(low[x], dfn[y]);
      }
    }
  }
  std::pair<int, std::vector<std::vector<int>>> rebuild() {
    work();
    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1; i <= cnt; i++) {
      for (auto j : col[i]) {
        if (point[j]) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
    return {cnt, adj};
  }
  void work() {
    for (int i = 1; i <= n; i++) {
      if (!dfn[i]) {
        tarjan(1, i);
      }
    }
  }
};

void solve(int _t) {
  int n, m;
  std::cin >> n >> m;
  V_DCC dcc(n);
  std::vector<std::pair<int, int>> e;
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    dcc.add(x, y);
    e.push_back({x, y});
  }
  dcc.rebuild();
  int cnt = dcc.cnt;
  auto &ver = dcc.ver;
  auto &col = dcc.col;
  auto &point = dcc.point;
  auto &eCol = dcc.eCol;
  for (int i = 1; i <= cnt; i++) {
    for (auto u : col[i]) {
      std::cerr << u << ' ';
    }
    std::cerr << '\n';
    for (auto [x, y] : eCol[i]) {
      std::cerr << x << ' ' << y << '\n';
    }
    std::cerr << '\n';
  }
  // for (int i = 1; i <= cnt; i++) {
  //   std::cerr << i << ": ";
  //   for (auto u : col[i]) {
  //     std::cerr << u << ' ';
  //   }
  //   std::cerr << '\n';
  // }
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << point[i] << ' ';
  // }
  // std::cerr << '\n';
  // return;
  std::vector<int> in(n + 1), dis(n + 1), now(n + 1);
  bool flag = true;
  int siz = -1;
  std::vector<int> p(cnt + 1);
  std::ranges::iota(p, 0);
  std::ranges::sort(p.begin() + 1, p.end(), [&](auto x, auto y) {
    return col[x].size() < col[y].size();
  });
  // std::mt19937_64 rd(std::random_device{}());
  // std::shuffle(p.begin() + 1, p.end(), rd);
  // for (int c = 1; c <= cnt; c++) {
  int tot = 0;
  // std::cerr << cnt << '\n';
  for (int i = 1; i <= cnt; i++) {
    int c = i;
    // std::cerr << c << ' ' << col[c].size() << ' ';
    if (col[c].size() <= 2) {
      continue;
    }
    for (int u : col[c]) {
      in[u] = dis[u] = 0;
      now[u] = c;
    }
    for (int u : col[c]) {
      // tot = 0;
      for (int v : ver[u]) {
        in[v]++;
        tot++;
      }
      // std::cerr << tot << ' ';
    }
    // std::cerr << '\n';
    // std::cerr << tot << '\n';
    int s = -1, t = -1;
    for (int u : col[c]) {
      if (in[u] != 2) {
        if (s == -1) {
          s = u;
        } else if (t == -1) {
          t = u;
        } else {
          flag = false;
          break;
        }
      }
    }
    if (s == -1) {
      if (siz == -1) {
        siz = col[c].size();
      } else if (siz != col[c].size()) {
        flag = false;
        break;
      }
      continue;
    }
    if (t == -1) {
      flag = false;
      break;
    }
    auto dfs = [&](this auto &&self, int u, int p) -> void {
      ++tot;
      if (u == t) {
        if (dis[u] && dis[u] != dis[p] + 1) {
          flag = false;
        }
        dis[u] = dis[p] + 1;
        if (siz != -1 && dis[u] != (siz - 2) / 2 + 2) {
          flag = false;
        }
        return;
      }
      if (dis[u]) {
        return;
      }
      dis[u] = dis[p] + 1;
      for (int v : ver[u]) {
        if (v != p && now[v] == c && flag) {
          self(v, u);
        }
      }
    };
    dfs(s, 0);
    if (!flag) {
      break;
    }
    // std::cerr << "s = " << s << ", t = " << t << ", dis[t] = " << dis[t] << '\n';
    dis[t] = dis[t] * 2 - 2;
    if (siz == -1) {
      siz = dis[t];
    } else if (siz != dis[t]) {
      flag = false;
      break;
    }
    for (int u : col[c]) {
      std::erase_if(ver[u], [&](auto x) {
        return now[x] == c && !point[x];
      });
    }
  }
  std::cout << (flag ? "Yes" : "No") << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  for (int i = 1; i <= t; i++) {
    solve(i);
  }

  return 0;
}
