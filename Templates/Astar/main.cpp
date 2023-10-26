#include <bits/stdc++.h>
using namespace std;

struct Matrix {
  array<array<int, 5>, 5> a;
  bool operator < (const Matrix b) const {
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
        if (a[i][j] != b.a[i][j])
          return a[i][j] < b.a[i][j];
    return false;
  }
} src, trg;

int h(const Matrix &a) {
  int sum = 0;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      sum += a.a[i][j] != trg.a[i][j];
  return max(0, sum - 1); // ??????
}

struct Node {
  Matrix mat;
  int t, x, y;
  bool operator < (const Node &b) const {
    return t + h(mat) > b.t + h(b.mat);
  }
};

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void solve() {
  int sx, sy;
  for (int i = 0; i < 5; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < 5; j++) {
      char ch = str[j];
      if (ch == '1') src.a[i][j] = 1;
      else if (ch == '0') src.a[i][j] = -1;
      else if (ch == '*') src.a[i][j] = 0, sx = i, sy = j;
    }
  }

  set<Matrix> s;
  priority_queue<Node> q;
  
  q.push({src, 0, sx, sy});
  while (!q.empty()) {
    Node node = q.top(); q.pop();
    Matrix &mat = node.mat;
    int t = node.t, x = node.x, y = node.y;
    if (h(mat) == 0) {
      cout << t << '\n';
      return;
    }
    if (t == 15) continue;
    for (int i = 0; i < 8; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if (xx < 0 || xx >= 5 || yy < 0 || yy >= 5) continue;
      swap(mat.a[xx][yy], mat.a[x][y]);
      if (t + 1 + h(mat) <= 15 && !s.count(mat))
        s.insert(mat), q.push({mat.a, t + 1, xx, yy});
      swap(mat.a[xx][yy], mat.a[x][y]);
    }
  }
  cout << "-1\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int T;
  cin >> T;
  trg.a = {1,1,1,1,1, -1,1,1,1,1, -1,-1,0,1,1, -1,-1,-1,-1,1, -1,-1,-1,-1,-1};
  while (T--) solve();
  return 0;
}
