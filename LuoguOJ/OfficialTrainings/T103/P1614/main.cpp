#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
  int n, m, sum = 0;
  cin >> n >> m;
  array<int, 3000> a{};
  array<int, 3000> prevSum{};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    if (i + 1 >= m) {
      sum -= i - m >= 0 ? a[i - m] : 0;
      prevSum[i] = sum;
    }
  }
  // for (int i = 0; i < n; i++) {
  //   cout << "prevSum[" << i << "]=" << prevSum[i] << endl;
  // }
  sort(prevSum.begin() + m - 1, prevSum.begin() + n);
  cout << prevSum[m-1];
  return 0;
}

/*
8 3
1
4
7
3
1
2
4
3
*/