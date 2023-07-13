#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << int((a + b / 10.0) / 1.9) << std::endl;
  return 0;
}