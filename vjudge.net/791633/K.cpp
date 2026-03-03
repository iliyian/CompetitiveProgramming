/*

LLLLLLLLLLL             IIIIIIIIIIYYYYYYY       YYYYYYYIIIIIIIIII AAA NNNNNNNN
NNNNNNNN L:::::::::L             I::::::::IY:::::Y       Y:::::YI::::::::I A:::A
N:::::::N       N::::::N L:::::::::L             I::::::::IY:::::Y
Y:::::YI::::::::I             A:::::A             N::::::::N      N::::::N
LL:::::::LL             II::::::IIY::::::Y     Y::::::YII::::::II A:::::::A
N:::::::::N     N::::::N L:::::L                 I::::I  YYY:::::Y   Y:::::YYY
I::::I             A:::::::::A           N::::::::::N    N::::::N L:::::L I::::I
Y:::::Y Y:::::Y     I::::I            A:::::A:::::A          N:::::::::::N
N::::::N L:::::L                 I::::I      Y:::::Y:::::Y      I::::I A:::::A
A:::::A         N:::::::N::::N  N::::::N L:::::L                 I::::I
Y:::::::::Y       I::::I          A:::::A   A:::::A        N::::::N N::::N
N::::::N L:::::L                 I::::I        Y:::::::Y        I::::I A:::::A
A:::::A       N::::::N  N::::N:::::::N L:::::L                 I::::I Y:::::Y
I::::I        A:::::AAAAAAAAA:::::A      N::::::N   N:::::::::::N L:::::L I::::I
Y:::::Y         I::::I       A:::::::::::::::::::::A     N::::::N N::::::::::N
  L:::::L         LLLLLL  I::::I         Y:::::Y         I::::I
A:::::AAAAAAAAAAAAA:::::A    N::::::N     N:::::::::N
LL:::::::LLLLLLLLL:::::LII::::::II       Y:::::Y       II::::::II   A:::::A
A:::::A   N::::::N      N::::::::N L::::::::::::::::::::::LI::::::::I
YYYY:::::YYYY    I::::::::I  A:::::A               A:::::A  N::::::N N:::::::N
L::::::::::::::::::::::LI::::::::I    Y:::::::::::Y    I::::::::I A:::::A
A:::::A N::::::N        N::::::N LLLLLLLLLLLLLLLLLLLLLLLLIIIIIIIIII
YYYYYYYYYYYYY    IIIIIIIIIIAAAAAAA                   AAAAAAANNNNNNNN NNNNNNN

 *
 * ==============================================================================
 * @Author  : iliyian
 * @File    : K.cpp
 * @Time    : 2026-02-23 15:42:28
 * @Comment :
 * ==============================================================================
*/

#include <bits/stdc++.h>
#include <chrono>
#define int long long

int pos[]{0, 4, 0, 1, 2, 3, 5, 6, 7, 8};

std::vector<std::array<int, 3>> all_three{{2, 1, 9}, {3, 1, 8}, {4, 1, 7},
                                          {5, 1, 6}, {2, 3, 4}, {2, 5, 7},
                                          {4, 6, 9}, {7, 8, 9}};

void solve() {
  auto s=clock();
  int n, m, k, t;
  std::cin >> n >> m >> k >> t;
  std::vector<int> a(k + 1);
  for (int i = 1; i <= k; i++) {
    std::cin >> a[i];
  }
  bool unhappy = false;

  std::vector<int> now_filled(9, -1), final_got(m + 1);

  auto all_same = [&](int a, int b, int c) {
    if (now_filled[pos[a]] == -1)
      return false;
    if (now_filled[pos[b]] == -1)
      return false;
    if (now_filled[pos[c]] == -1)
      return false;
    return now_filled[pos[a]] == now_filled[pos[b]] &&
           now_filled[pos[a]] == now_filled[pos[c]];
  };

  int now_at = 1;
  auto send_gift = [&](int x) {
    if (n + x > k) {
      unhappy = true;
    }
    n += x;
  };

  auto capture_one = [&](int position) {
    final_got[now_filled[position]]++;
    now_filled[position] = -1;
  };

  while (1) {
    auto T=clock(); 
    if ((double)(T-s)/CLOCKS_PER_SEC>=0.98) {
      break;
    }
    std::set<int> set_of_all;
    bool have_op_15 = false;

    // op 1
    bool over_round = false;
    for (int j = 1; j <= 9; j++) {
      if (now_filled[pos[j]] == -1 && now_at <= std::min(k, n)) {
        int col = a[now_at++];
        now_filled[pos[j]] = col;
        have_op_15 = true;
        if (col == t) {
          send_gift(1);
        }
        if (col == 0) {
          capture_one(pos[j]);
          send_gift(1);
          over_round = true;
          break;
        }
      }
    }
    if (over_round) {
      continue;
    }

    // op 2
    for (int i = 0; i < 9; i++) {
      if (now_filled[i] != -1) {
        set_of_all.insert(now_filled[i]);
      }
    }
    if (set_of_all.size() == 9) {
      // if (now_filled[pos[1]] != -1) {
        capture_one(pos[1]);
      // }
      continue;
    }

    // op 3
    bool have_op_34 = false;
    bool have_special_block = false;
    for (auto &[x, y, z] : all_three) {
      if (all_same(x, y, z)) {
        have_op_34 = true;
        send_gift(5);
        if (x == 1 || y == 1 || z == 1) {
          have_special_block = true;
        }
        if (x != 1) {
          capture_one(pos[x]);
        }
        if (y != 1) {
          capture_one(pos[y]);
        }
        if (z != 1) {
          capture_one(pos[z]);
        }
      }
    }

    // op 4
    for (int x = 1; x <= 9; x++) {
      for (int y = x + 1; y <= 9; y++) {
        if (now_filled[pos[x]] == now_filled[pos[y]] &&
            now_filled[pos[x]] != -1) {
          send_gift(1);
          if (x == 1 || y == 1) {
            have_special_block = true;
          }
          have_op_34 = true;
          if (x != 1) {
            capture_one(pos[x]);
          }
          if (y != 1) {
            capture_one(pos[y]);
          }
        }
      }
    }

    // op 5
    if (have_special_block) {
      capture_one(pos[1]);
      have_op_15 = true;
    }

    // op 6
    if (!have_op_15 && !have_op_34) { // 2 will not effect
      for (int i = 1; i <= 9; i++) {
        if (now_filled[pos[i]] != -1) {
          capture_one(pos[i]);
        }
      }
      break;
    } else {
      bool have_one = false;
      for (int i = 1; i <= 9; i++) {
        if (now_filled[pos[i]] != -1) {
          have_one = true;
        }
      }
      if (!have_one) {
        send_gift(10);
      }
    }
  }

  for (int i = 0; i <= m; i++) {
    std::cout << final_got[i] << ' ';
  }
  std::cout << '\n';
  if (unhappy) {
    std::cout << "Unhappy! " << n - k << '\n';
  }
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
