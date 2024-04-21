#include <iostream>
#include <array>
using namespace std;

array<int, 10> arr{};

void check(int n) {
  while (n) {
    arr[n % 10]++;
    n /= 10;
  }
}

int main() {
  ios::sync_with_stdio(false);

  int m, n;
  cin >> m >> n;
  for (int i = m; i <= n; i++) {
    check(i);
  }
  for (int i = 0; i < 10; i++)
    cout << arr[i] << " ";
  return 0;
}