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
 * @Author  : iliyian
 * @File    : C_By_the_Assignment.cpp
 * @Time    : 2025-12-05 14:33:22
 * @Comment : 果然分高的题目还是会稍微设计一些图论知识吗（）这就是*2000的世界吗（感觉前面奇偶环分析和独立性都是好想的，
              但是确实没有在几十分钟内想到，环就是无向图上的双连通分量。以及双连通好像只在无向图上有意义？

              tmd最讨厌金价上涨的一集，即使是1g也根本无法送给好朋友，实在是太贵重了，但其他的礼物也真的真的真的真的很难选。
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

/**   割边与割边缩点（EBCC）
 *    2023-05-11: https://codeforces.com/contest/118/submission/205426518
**/
std::set<std::pair<int, int>> E;

struct EBCC {
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel;
    int cur, cnt;
    
    EBCC() {}
    EBCC(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void dfs(int x, int p) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            if (dfn[y] == -1) {
                E.emplace(x, y);
                dfs(y, x);
                low[x] = std::min(low[x], low[y]);
            } else if (bel[y] == -1 && dfn[y] < dfn[x]) {
                E.emplace(x, y);
                low[x] = std::min(low[x], dfn[y]);
            }
        }
        
        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }
    
    std::vector<int> work() {
        dfs(0, -1);
        return bel;
    }
    
    struct Graph {
        int n;
        std::vector<std::pair<int, int>> edges;
        std::vector<int> siz;
        std::vector<int> cnte;
    };
    Graph compress() {
        Graph g;
        g.n = cnt;
        g.siz.resize(cnt);
        g.cnte.resize(cnt);
        for (int i = 0; i < n; i++) {
            g.siz[bel[i]]++;
            for (auto j : adj[i]) {
                if (bel[i] < bel[j]) {
                    g.edges.emplace_back(bel[i], bel[j]);
                } else if (i < j) {
                    g.cnte[bel[i]]++;
                }
            }
        }
        return g;
    }
};

constexpr int mod = 998244353;

void solve() {
  E.clear();
  int n, m, V;
  std::cin >> n >> m >> V;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  EBCC ebcc(n);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    ebcc.addEdge(x, y);
  }
  auto bel = ebcc.work();
  // for (int i = 0; i < n; i++) {
  //   std::cerr << bel[i] << ' ';
  // }
  std::vector<int> col(n + 1);
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (!col[i]) {
      std::vector<int> vals;
      col[i] = 1;
      bool hasoddring = false;
      [&](this auto &&self, int u) -> void {
        vals.push_back(a[u]);
        for (int v : ebcc.adj[u]) {
          if (bel[v] != bel[i]) {
            continue;
          }
          if (col[v]) {
            if (col[v] != 3 - col[u]) {
              hasoddring = true;
            }
            continue;
          }
          col[v] = 3 - col[u];
          self(v);
        }
      } (i);
      // std::cerr << hasoddring << ' ' << has0 << ' ' << hasup0 << '\n';
      if (!hasoddring) {
        int v = -1;
        bool havem1 = false;
        for (auto i : vals) {
          if (i != -1) {
            if (v == -1) {
              v = i;
            } else if (v != i) {
              std::cout << 0 << '\n';
              return;
            }
          } else {
            havem1 = true;
          }
        }
        if (v == -1) {
          ans = ans * V % mod;
        }
      } else {
        for (auto i : vals) {
          if (i > 0) {
            std::cout << 0 << '\n';
            return;
          }
        }
      }
    }
  }
  std::cout << ans << '\n';
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
