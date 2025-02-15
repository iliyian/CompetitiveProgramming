#include <bits/stdc++.h>
using namespace std;

constexpr int N = 50;

int a[N + 1], b[N + 1][N + 1], c[N + 1][N + 1];
int d[N * N + 1];

int mex(int len) {
  int mex = 0;
  sort(d + 1, d + len + 1);
  for (int i = 1; i <= len; i++) {
    if (d[i] == mex) {
      mex++;
    }
  }
  return mex;
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      for (int k = i; k <= j; k++) {
        d[k - i + 1] = a[k];
      }
      b[i][j] = mex(j - i + 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int cnt = 0;
      for (int l = i; l <= j; l++) {
        for (int r = l; r <= j; r++) {
          d[++cnt] = b[l][r];
        }
      }
      c[i][j] = mex(cnt);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      d[++cnt] = c[i][j];
    }
  }
  std::cout << mex(cnt) << '\n';
}