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
 * @File    : A.cpp
 * @Time    : 2025-11-08 20:37:39
 * @Comment : 
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int getd(char ch) {
  if (ch == 'U') return 0;
  if (ch == 'R') return 1;
  if (ch == 'D') return 2;
  return 3;
}

std::vector<std::string> c;

void move(char ch, std::vector<std::string> &a) {
  // for (char ch : ans) {
  int d = getd(ch);
  std::vector<std::string> b(a.size(), std::string(a[0].size(), '0'));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[i].size(); j++) {
      int xx = i + dx[d], yy = j + dy[d];
      if (a[i][j] == '0') continue;
      if (xx >= 0 && xx < a.size() && yy >= 0 && yy < a[i].size() && c[xx][yy] == '1') {
        b[xx][yy] |= 1;
      } else {
        b[i][j] |= 1;
      }
    }
  }
  a = std::move(b);
  // }
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n);
  int sx = 0, sy = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '1') {
        sx = i, sy = j;
      }
    }
  }
  c = a;
  std::vector<std::vector<int>> dis(n, std::vector<int>(m, -1)), pre(n, std::vector<int>(m));
  std::queue<std::pair<int, int>> q;
  dis[sx][sy] = 0;
  q.push({sx, sy});
  auto in = [&](int x, int y) {return x >= 0 && x < n && y >= 0 && y < m;};
  int rev[] = {2, 3, 0, 1};
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (in(xx, yy) && dis[xx][yy] == -1 && a[xx][yy] == '1') {
        dis[xx][yy] = dis[x][y] + 1;
        pre[xx][yy] = rev[i];
        q.push({xx, yy});
      }
    }
  }
  std::string ans, dr = "URDL";
  while (1) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += std::ranges::count(a[i], '1');
    }
    if (cnt == 1) break;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '1') {
          move(dr[pre[i][j]], a);
          ans.push_back(dr[pre[i][j]]);
          goto end;
        }
      }
    }
    end:;
  }
  // for (auto i : a) {
  //   std::cerr << i << '\n';
  // }
  // std::cerr << '\n';
  std::cout << ans << '\n';
  // if (n == 20 && m == 20) {
  //   for (int j = 14; j < 20; j++) {
  //     std::cerr << a[j];
  //   }
  //   std::cerr << '\n';
  // }
  // check(ans, a);
  // std::cerr << ans.size() << '\n';
  // int s = 0;
  // while (s + ans.size() <= 50000) {
  //   s += ans.size();
  //   std::cout << ans;
  // }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
