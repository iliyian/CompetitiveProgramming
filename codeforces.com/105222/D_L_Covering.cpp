#include <bits/stdc++.h>
#define int long long

std::string p4[] = {
  "CLD.",
  "UDCL",
  "DCLD",
  "CLRC",
};

std::string p5[] = {
  "RCCL.",
  "DUURC",
  "CLRCU",
  "CLDUD",
  "URCRC",
};

std::string p22[] = {
  "D.",
  "CL",
};

std::string p25[] = {
  "CLDD.",
  "URCCL"
};

std::string p52[] = {
  "D.",
  "CL",
  "CL",
  "UD",
  "RC",
};

std::string p47[] = {
  "CLDCLD.",
  "URCUDCL",
  "CLDDCLD",
  "URCCLRC",
};

std::string p74[] = {
  "CLD.",
  "UDCL",
  "DCLD",
  "CLRC",
  "CLCL",
  "UDUD",
  "RCRC",
};

std::string p7[] {
  "CLRCCL.",
  "UDDUURC",
  "RCCLDDU",
  "CLDRCCL",
  "URCCLCL",
  "CLDUDUD",
  "URCRCRC",
};

std::string p[] = {
  "CLD",
  "URC",
  "CLD",
  "URC",
  "CLD",
  "URC",
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n + 1, std::string(m + 1, '.'));
  if (n * m % 3 != 1) {
    std::cout << "No\n";
    return;
  }
  std::cout << "Yes\n";
  int lst = n;
  for (int i = n; i > 7; i -= 6) {
    lst = i - 6;
    for (int j = 1; j <= m - 1; j += 2) {
      a[i - 5][j] = 'C', a[i - 5][j + 1] = 'L';
      a[i - 4][j] = 'U', a[i - 4][j + 1] = 'D';
      a[i - 3][j] = 'R', a[i - 3][j + 1] = 'C';
      a[i - 2][j] = 'C', a[i - 2][j + 1] = 'L';
      a[i - 1][j] = 'U', a[i - 1][j + 1] = 'D';
      a[i - 0][j] = 'R', a[i - 0][j + 1] = 'C';
    }
    if (m % 2) {
      for (int k = -5; k <= 0; k++) {
        for (int j = m - 2; j <= m; j++) {
          a[i + k][j] = p[k + 5][j - (m - 2)];
        }
      }
    }
  }
  // int ls = -1;
  for (int i = 1; i <= lst - 1; i += 2) {
    int r = 0;
    for (int j = 1; m - (j) >= 7; j += 6) {
      // std::cerr << "qwq\n";
      r = j + 4;
      a[i][j] = 'C', a[i][j + 1] = 'L', a[i][j + 2] = 'D', a[i][j + 3] = 'C', a[i][j + 4] = 'L', a[i][j + 5] = 'D';
      a[i + 1][j] = 'U', a[i + 1][j + 1] = 'R', a[i + 1][j + 2] = 'C', a[i + 1][j + 3] = 'U', a[i + 1][j + 4] = 'R', a[i + 1][j + 5] = 'C';
    }
    if (lst % 2) {
      for (int j = 1; j <= r; j += 2) {
        a[lst - 2][j] = 'C', a[lst - 2][j + 1] = 'L';
        a[lst - 1][j] = 'U', a[lst - 1][j + 1] = 'D';
        a[lst - 0][j] = 'R', a[lst - 0][j + 1] = 'C';
      }
    }
  }
  auto fill = [&](int x, int y, int h, int w, std::string *p) {
    // return;
    for (int i = x; i <= x + h - 1; i++) {
      for (int j = y; j <= y + w - 1; j++) {
        a[i][j] = p[i - x][j - y];
      }
    }
  };
  for (int i = 1; i <= m; i++) {
    if (a[1][i] == '.') {
      for (int j = 1; j <= n + 1; j++) {
        if (j == n + 1 || a[j][i] != '.') {
          int h = j - 1, w = (m - i + 1);
          // std::cerr << h << ' ' << w << '\n';
          if (h == 2 && w == 2) {
            fill(1, i, h, w, p22);
          }
          if (h == 2 && w == 5) {
            fill(1, i, h, w, p25);
          }
          if (h == 5 && w == 2) {
            fill(1, i, h, w, p52);
          }
          if (h == 5 && w == 5) {
            fill(1, i, h, w, p5);
          }
          if (h == 4 && w == 4) {
            fill(1, i, h, w, p4);
          }
          if (h == 4 && w == 7) {
            fill(1, i, h, w, p47);
          }
          if (h == 7 && w == 4) {
            fill(1, i, h, w, p74);
          }
          if (h == 7 && w == 7) {
            fill(1, i, h, w, p7);
          }
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cout << a[i][j];
    }
    std::cout << '\n';
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