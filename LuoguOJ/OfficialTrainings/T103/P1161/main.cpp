#include <iostream>
#include <array>
using namespace std;

int main() {
  int n;
  cin >> n;
  array<bool, 2000001> lights{};
  while (n--) {
    double a;
    int t;
    cin >> a >> t;
    for (int i = 1; i <= t; i++) {
      lights[i * a] = !lights[i * a];
    }
  }

  for (int i = 1;; i++) {
    if (lights[i]) {
      cout << i;
      break;
    }
  }
  
  return 0;
}