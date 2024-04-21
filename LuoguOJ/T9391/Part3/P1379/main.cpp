// A*好像有种双向的感觉？因为更多的考虑了终点

#include <bits/stdc++.h>
using namespace std;

struct Matrix {
  array<array<int, 3>, 3> a;
  bool operator < (const Matrix b) const {
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        if (a[i][j] != b.a[i][j])
          return a[i][j] < b.a[i][j];
    return false;
  }
} trg, src;
set<Matrix> s;

int h(const Matrix &a) {
  int sum = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      sum += a.a[i][j] != trg.a[i][j];
  return sum;
}

struct Node {
  Matrix mat;
  int t;
  bool operator < (const Node &b) const {
    return t + h(mat) > b.t + h(b.mat);
  }
};
priority_queue<Node> q;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main() {
  freopen("data.in", "r", stdin);
  trg.a = {1, 2, 3, 8, 0, 4, 7, 6, 5};
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      char ch = cin.get();
      src.a[i][j] = ch - '0';
    }
  q.push({src, 0});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    Matrix &mat = node.mat;
    int t = node.t;
    if (h(mat) == 0) {
      cout << t;
      return 0;
    }
    int sx, sy;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        if (mat.a[i][j] == 0)
          sx = i, sy = j;
    for (int i = 0; i < 4; i++) {
      int xx = sx + dx[i], yy = sy + dy[i];
      if (xx < 0 || xx >= 3 || yy < 0 || yy >= 3) continue;
      swap(mat.a[xx][yy], mat.a[sx][sy]);
      if (!s.count(mat))
        s.insert(mat), q.push({mat, t + 1});
      swap(mat.a[xx][yy], mat.a[sx][sy]);
    }
  }
  cout << -1;
  return 0;
}