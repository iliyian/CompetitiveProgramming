// 我实在是太崇拜蒋老师了
// 蒋老师实在是太厉害了
// 好后悔去年没跟蒋老师合影

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
 * @File   : D_Inversion_Value_of_a_Permutation.cpp
 * @Time   : 2025-10-08 22:20:21
 * ==============================================================================
*/

// 这玩意是真想不到能用bitset

#include <bits/stdc++.h>
#define int long long

std::bitset<500> dp[31];

void solve() {
  int n, k;
  std::cin >> n >> k;
  k = n * (n - 1) / 2 - k;
  if (!dp[n][k]) {
    std::cout << 0 << '\n';
    return;
  }
  std::vector<int> ans;
  for (int i = 1; i <= n; i++) {
    // 如果可解，一定存在解的路径，且必然可以自小向大
    // 蒋老师实在是太优雅了
    // 我实在是太崇拜蒋老师了
    // 蒋老师实在是太厉害了
    // 啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
    if (dp[n - i][k - i * (i - 1) / 2]) {
      n -= i, k -= i * (i - 1) / 2;
      for (int j = 1; j <= i; j++) {
        ans.push_back(n + j); // 太优雅了，蒋老师的键盘没有backspace
      }
      i--;
    }
  }
  for (auto i : ans) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  dp[0][0] = 1;
  for (int i = 0; i <= 30; i++) {
    for (int j = 1; j + i <= 30; j++) {
      dp[i + j] |= dp[i] << (j * (j - 1) / 2);
    }
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
