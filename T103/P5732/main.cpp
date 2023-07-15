#include <iostream>
#include <array>
using namespace std;

int main() {
  int n;
  cin >> n;
  array<array<int, 20>, 20> triangle{};
  triangle[0][0] = 1;
  for (int i = 1; i < n; i++) {
    triangle[i][0] = triangle[i][i] = 1;
    for (int j = 1; j < i; j++)
      triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
  }
  cout << 1 << endl;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= i; j++)
      cout << triangle[i][j] << " ";
    cout << endl;
  }
  return 0;
}