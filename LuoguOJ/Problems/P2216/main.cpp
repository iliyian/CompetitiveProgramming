// date: 2024/01/25 12:00:07
// tag: 二维单调队列求二维RMQ问题及其答案的合并
// 暴力

#include <bits/stdc++.h>
#define N 1005
using namespace std;

int a[N][N], X[N][N], Y[N][N], x[N][N], y[N][N];

void solve() {
  int r, c, n;
  cin >> r >> c >> n;
  for (int i = 1; i <= r; i++)
    for (int j = 1; j <= c; j++)
      cin >> a[i][j];

  for (int i = 1; i <= r; i++) {
    deque<int> Q;
    for (int j = 1; j <= c; j++) {
      while (!Q.empty() && Q.front() <= j - n)
        Q.pop_front();
      while (!Q.empty() && a[i][Q.back()] <= a[i][j])
        Q.pop_back();
      Q.push_back(j);
      if (j >= n) X[i][j - n + 1] = a[i][Q.front()];
    }
  }
  for (int j = 1; j <= c - n + 1; j++) {
    deque<int> Q;
    for (int i = 1; i <= r; i++) {
      while (!Q.empty() && Q.front() <= i - n)
        Q.pop_front();
      while (!Q.empty() && X[Q.back()][j] <= X[i][j])
        Q.pop_back();
      Q.push_back(i);
      if (i >= n) Y[i - n + 1][j] = X[Q.front()][j];
    }
  }

  for (int i = 1; i <= r; i++) {
    deque<int> q;
    for (int j = 1; j <= c; j++) {
      while (!q.empty() && q.front() <= j - n)
        q.pop_front();
      while (!q.empty() && a[i][q.back()] >= a[i][j])
        q.pop_back();
      q.push_back(j);
      if (j >= n) x[i][j - n + 1] = a[i][q.front()];
    }
  }
  for (int j = 1; j <= c - n + 1; j++) {
    deque<int> q;
    for (int i = 1; i <= r; i++) {
      while (!q.empty() && q.front() <= i - n)
        q.pop_front();
      while (!q.empty() && x[q.back()][j] >= x[i][j])
        q.pop_back();
      q.push_back(i);
      if (i >= n) y[i - n + 1][j] = x[q.front()][j];
    }
  }

  int ans = 0x3f3f3f3f;
  for (int i = 1; i <= r - n + 1; i++) {
    for (int j = 1; j <= c - n + 1; j++) {
      // cout << Y[i][j] << ':' << y[i][j] << ' ';
      ans = min(ans, Y[i][j] - y[i][j]);
    }
    // cout << '\n';
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}