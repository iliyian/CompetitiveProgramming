#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  array<int, 81> count{};
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++)
      for (int k = 1; k <= c; k++)
        count[i+j+k]++;
  }
  int ans = 0;
  for (int i = 3; i <= 80; i++)
    if (count[i] > count[ans])
      ans = i;
  cout << ans;
  return 0;
}