#include <iostream>
#include <array>
using namespace std;

array<array<int, 201>, 201> rect;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) 
      cin >> rect[i][j];
  }
  for (int i = 0; i < n; i++) {
    bool flag = false;
    for (int j = 0; j < m; j++)
      if (rect[i][j]) {
        flag = true;
        break;
      }
    cout << (flag ? 1 : 0) << " ";
  }
  cout << endl;
  for (int j = 0; j < m; j++) {
    bool f = false;
    for (int i = 0; i < n; i++)
      if (rect[i][j]) {
        f = true;
        break;
      }
    cout << (f ? 1 : 0) << " ";
  }
  cout << endl;
  for (int j = m - 1; j >= 0; j--) {
    for (int i = 0; i < n; i++)
      cout << rect[i][j] << " ";
    cout << endl;
  }
  return 0;
}