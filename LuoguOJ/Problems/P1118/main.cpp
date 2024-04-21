// 仍然要 tmd -O2

#include <bits/stdc++.h>
using namespace std;

int a[15];
int b[13][12] = { 
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0,0,0,0,0},
  {1,1,0,0,0,0,0,0,0,0,0,0},
  {1,2,1,0,0,0,0,0,0,0,0,0},
  {1,3,3,1,0,0,0,0,0,0,0,0},
  {1,4,6,4,1,0,0,0,0,0,0,0},
  {1,5,10,10,5,1,0,0,0,0,0,0},
  {1,6,15,20,15,6,1,0,0,0,0,0},
  {1,7,21,35,35,21,7,1,0,0,0,0},
  {1,8,28,56,70,56,28,8,1,0,0,0},
  {1,9,36,84,126,126,84,36,9,1,0,0},
  {1,10,45,120,210,252,210,120,45,10,1,0},
  {1,11,55,165,330,462,462,330,165,55,11,1}
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n, ans;
  cin >> n >> ans;
  for (int i = 0; i < n; i++)
    a[i] = i + 1;
  // for (int i = 1; i <= 12; i++) {
  //   for (int j = 0; j < i; j++) {
  //     if (!j || j == i) b[i][j] = 1;
  //     else b[i][j] = b[i - 1][j] + b[i - 1][j - 1];
  //   }
  // }

  // cout << '{';
  // for (int i = 0; i <= 12; i++) {
  //   cout << '{';
  //   for (int j = 0; j < i; j++)
  //     cout << b[i][j] << ',';
  //   for (int j = i; j < 12; j++)
  //     cout << (j == 11 ? "0" : "0,");
  //   cout << "},\n";
  // }
  // cout << '}';

  // return 0;

  do {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      sum += a[i] * b[n][i];
      if (sum > ans) break;
    }
    if (sum == ans) {
      for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
      return 0;
    }
  } while (next_permutation(a, a + n));
  return 0;
}