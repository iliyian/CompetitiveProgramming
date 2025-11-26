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
 * @File   : H.cpp
 * @Time   : 2025-10-27 19:56:58
 * ==============================================================================
*/

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < 729; i++) {
    int j = i;
    std::array<int, 9> dif;
    dif.fill(0);
    for (int k = 0; k < 6; k++) {
      int val = j % 3; j /= 3;
      if (val) {
        for (int t = k + 1; t <= k + 3; t++) {
          dif[t] += val;
        }
      }
    }
    std::vector<std::array<int, 9>> cnt(n + 1);
    cnt[0].fill(0);
    std::vector<int> cnts(6561);
    auto toval = [&](std::array<int, 9> &a) {
      int ans = 0;
      for (int i = 8; i >= 1; i--) {
        ans = ans * 3 + a[i] % 3;
      }
      return ans;
    };
    for (int r = 0, l = 0; r < n; r++) {
      cnt[r + 1] = cnt[r];
      cnt[r + 1][a[r]]++;
      while (l < r + 1) {
        bool flag = true;
        for (int j = 1; j <= 8; j++) {
          if (cnt[r + 1][j] - cnt[l][j] < dif[j]) {
            flag = false;
            break;
          }
        }
        if (!flag) {
          break;
        }
        cnts[toval(cnt[l])]++;
        l++;
      }
      int s = 0;
      for (int i = 8; i >= 1; i--) {
        s = s * 3 + (cnt[r + 1][i] - dif[i]) % 3;
        if (cnt[r + 1][i] < dif[i]) {
          goto end;
        }
      }
      ans += cnts[s];
      end:;
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
