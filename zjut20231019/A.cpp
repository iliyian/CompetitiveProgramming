#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int n, k, m;

struct Mat {
  int a[30][30];
  Mat() {
    memset(a, 0, sizeof(a));
  }
  Mat operator * (const Mat &b) {
    Mat res;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < n; k++) {
          res.a[i][j] += a[i][k] * b.a[k][j] % m;
          res.a[i][j] %= m;
        }
    return res;
  }
  void operator += (const Mat &b) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        a[i][j] += b.a[i][j];
        a[i][j] %= m;
      }
  }
  bool operator == (const Mat &b) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (a[i][j] != b.a[i][j])
          return false;
    return true;
  }
};

void print(const Mat &sum) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << sum.a[i][j] << ' ';
    cout << '\n';
  }
  cout << '\n';
}

map<Mat, bool> vis;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("A.in", "r", stdin);
  cin >> n >> k >> m;
  // m = 998244353;
  Mat a, sum, base;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a.a[i][j];
  base = a;

  vector<Mat> ans;

  for (int i = 1; i <= k; i++) {
    sum += a;

    cout << "i= " << i << '\n';
    print(sum);

    a = a * base;
  }

  print(sum);
  return 0;
}