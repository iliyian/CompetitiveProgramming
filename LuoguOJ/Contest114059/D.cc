#include <iostream>
#include <array>
using namespace std;

int main() {
  int n;
  long long v = 0;
  cin >> n;
  array<int, 50005> d{}, r{};
  for (int i = 0; i < n; i++) {
    cin >> d[i] >> r[i];
    if (i) {
      int dist = d[i] - d[i-1];
      if (dist > r[i-1]) {
        v += dist - r[i-1];
      }
    }
  }
  cout << v;
  return 0;
}