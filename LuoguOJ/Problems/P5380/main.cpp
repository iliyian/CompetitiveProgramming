// 一潭死水

#include <bits/stdc++.h>
using namespace std;

int a[10][9] = {
  {-5, -4, -3, -2, -1, -2, -3, -4, -5},
  {0, 0, 0, 0, 0, 0, 0, 0, 0},
  {-6, 0, 0, 0, 0, 0, 0, 0, -6},
  {-7, 0, -7, 0, -7, 0, -7, 0, -7},
  {0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0},
  {7, 0, 7, 0, 7, 0, 7, 0, 7},
  {6, 0, 0, 0, 0, 0, 0, 0, 6},
  {0, 0, 0, 0, 0, 0, 0, 0, 0},
  {5, 4, 3, 2, 1, 2, 3, 4, 5}
};

bool get(int n, int &x, int &y) {
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 9; j++)
      if (a[i][j] == n) {
        x = i, y = j;
        return true;
      }
  return false;
}

int dx1[] = {-1, 0, 1, 0}, dy1[] = {0, 1, 0, -1};
int dx2[] = {-1, -1, 1, 1}, dy2[] = {-1, 1, 1, -1};
int dx3[] = {-1, -1, 1, 1}, dy3[] = {-1, 1, 1, -1};
int dxx4[] = {-1, 0, 1, 0}, dyy4[] = {0, 1, 0, -1};
int dx4[] = {-2, -2, -1, 1, 2, 2, 1, -1},
    dy4[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dx6[] = {-1, 1, 1, -1}, dy6[] = {1, 1, -1, -1},
    djx[] = {0, 1}, djy[] = {1, 0};
int dx7[] = {-1, -1, 0, 1, 1, 1, 0, -1},
    dy7[] = {0, 1, 1, 1, 0, -1, -1, -1};

inline bool in(int x, int y) {
  if (x < 0 || x >= 10 || y < 0 || y >= 9) return false;
  return true;
}

inline bool sameTeam(int a, int b) {
  return a * b > 0;
}

bool isok(int sx, int sy, int tx, int ty) {
  if (sameTeam(a[sx][sy], a[tx][ty])) return false;
  switch (abs(a[sx][sy])) {
    case 1:
      for (int i = 0; i < 4; i++)
        if (sx + dx1[i] == tx && sy + dy1[i] == ty)
          return true;
    return false;
    case 2:
      for (int i = 0; i < 4; i++)
        if (sx + dx2[i] == tx && sy + dy2[i] == ty)
          return true;
    return false;
    case 3:
      for (int i = 0; i < 4; i++) {
        int xx = sx + dx3[i], yy = sy + dy3[i];
        if (!in(xx, yy) || a[xx][yy]) continue;
        if (xx + dx3[i] == tx && yy + dy3[i] == ty)
          return true;
      }
    return false;
    case 4:
      for (int i = 0; i < 4; i++) {
        int ix = sx + dxx4[i], iy = sy + dyy4[i];
        if (!in(ix, iy) || a[ix][iy]) continue;
        int j = i * 2, k = i * 2 + 1;
        int jx = sx + dx4[j], jy = sy + dy4[j],
            kx = sx + dx4[k], ky = sy + dy4[k];
        if (jx == tx && jy == ty) return true;
        if (kx == tx && ky == ty) return true;
      }
    return false;
    case 5:
      if (sx == tx) {
        if (sy == ty) return false;
        int miny = min(sy, ty), maxy = max(sy, ty);
        for (int y = miny + 1; y <= maxy - 1; y++)
          if (a[sx][y])
            return false;
        return true;
      } else if (sy == ty) {
        if (sx == tx) return false;
        int minx = min(sx, tx), maxx = max(sx, tx);
        for (int x = minx + 1; x <= maxx - 1; x++)
          if (a[x][sy])
            return false;
        return true;
      }
    return false;
    case 6:
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
          int ix = sx + dx6[i] * djx[j],
              iy = sy + dy6[i] * djy[j];
          if (!in(ix, iy) || a[ix][iy]) continue;
          ix += dx6[i], iy += dy6[i];
          if (!in(ix, iy) || a[ix][iy]) continue;
          if (ix + dx6[i] == tx && iy + dy6[i] == ty)
            return true;
        }
      }
    return false;
    case 7:
      for (int i = 0; i < 8; i++)
        if (sx + dx7[i] == tx && sy + dy7[i] == ty)
          return true;
    return false;
    default:
    return false;
  }
}

bool isAttack(bool P) {
  int cx, cy;
  get(P ? 1 : -1, cx, cy);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 9; j++) {
      if (!sameTeam(P ? 1 : -1, a[i][j]) && isok(i, j, cx, cy))
        return true;
    }
  }
  return false;
}

void find(int tx, int ty, int &x, int &y) {
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 9; j++)
      if (!sameTeam(a[tx][ty], a[i][j]) && isok(i, j, tx, ty))
        x = i, y = j;
}

bool isWin(bool P) {
  int cx, cy;
  return !get(P ? 1 : -1, cx, cy);
  // 我也不知道为什么是这样的

  // if (!get(P ? 1 : -1, cx, cy)) return true;
  // if (!isAttack(P)) return false;
  // for (int i = 0; i < 4; i++) {
  //   int xx = cx + dx1[i], yy = cy + dy1[i];
  //   if (!in(xx, yy) || sameTeam(P ? 1 : -1, a[xx][yy])) continue;
  //   int t = a[xx][yy];
  //   swap(a[xx][yy], a[cx][cy]);
  //   a[cx][cy] = 0;

  //   bool f = true;
  //   if (!isAttack(P)) {
  //     f = false;
  //   }
  //   swap(a[xx][yy], a[cx][cy]);
  //   a[xx][yy] = t;
  //   if (!f) return false;
  // }
  // int fx, fy;
  // find(cx, cy, fx, fy);
  // for (int i = 0; i < 10; i++)
  //   for (int j = 0; j < 9; j++)
  //     if (isok(i, j, fx, fy))
  //       return false;
  return true;
}

string m[8] = {"", "captain", "guard", "elephant", "horse", "car", "duck", "soldier"};

void printName(int n) {
  cout << (n > 0 ? "blue" : "red") << ' '
       << m[abs(n)] << ';';
}

void debug() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 9; j++)
      cout << a[i][j] << ' ';
    cout << '\n';
  }
}

int main() {
  bool over = false;
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false); cin.tie(0);
  int Q;
  cin >> Q;
  bool P = false;
  for (int i = 0; i < Q; i++) {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int &S = a[sx][sy], &T = a[tx][ty];
    bool ok = isok(sx, sy, tx, ty);
    if (!ok || over || !sameTeam(P ? 1 : -1, S)) {
      cout << "Invalid command\n";
      continue;
    }

    printName(S);
    if (T) printName(T);
    else cout << "NA;";

    T = S;
    S = 0;

    if (i == 243)
      bool a = true;

    bool attack = isAttack(P) || isAttack(!P);
    bool win = isWin(!P);
    if (win) over = true;

    cout << (attack ? "yes" : "no") << ';'
         << (win ? "yes" : "no") << '\n';

    P = !P;
    // if (i == 243) debug();
  }
  return 0;
}