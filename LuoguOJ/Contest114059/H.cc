#include <iostream>
#include <array>
using namespace std;

int n, m, k;

array<array<int, 101>, 101> rect{};
array<array<int, 101>, 101> sums{};
array<array<int, 101>, 101> diff{};

int getCount() {
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (diff[i][j] >= 0)
        count++;
  }
  return count;
}

int getSum(int x, int y) {
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += rect[i][y];
  for (int j = 0; j < m; j++)
    sum += rect[x][j];
  return sum;
}

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < m; j++) {
      cin >> rect[i][j];
    }
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      diff[i][j] = rect[i][j] - getSum(i, j);
  int ans = 0;
  while (getCount() < k) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        diff[i][j] += n + m - 1;
      }
    }
    ans++;
  }
  cout << ans;
  return 0;
}