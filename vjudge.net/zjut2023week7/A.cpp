#include <bits/stdc++.h>
#define N 105
using namespace std;

int n;

struct Mat {
  array<array<int, N>, N> a;
  Mat operator * (const Mat &b) {
    Mat res;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++)
          res.a[i][j] += a[i][k] * b.a[k][j];
    return res;
  }
};

istream& operator >> (istream &is, Mat &a) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      is >> a.a[i][j];
  return is;
}

ostream& operator << (ostream &os, const Mat &a) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cout << a.a[i][j] << " \n"[j == n - 1];
  return os;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  cin >> n;
  Mat a, b;
  cin >> a >> b;
  cout << a * b;
  return 0;
}