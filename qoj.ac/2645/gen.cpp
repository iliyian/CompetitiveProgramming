#include "testlib.h"
using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);

  std::cout << 1 << std::endl;
  int n = 300;
  std::cout << n << std::endl;
  std::vector<int> son(n + 1);
  for (int i = 2; i <= n; i++) {
    int x = rnd.next(1, i - 1);
    while (son[x] == 2) {
      x = rnd.next(1, i - 1);
    }
    son[x]++;
    std::cout << x << ' ';
  }
  std::cout << std::endl;
  std::cout << rnd.next(1, n) << std::endl;
  quitf(_ok, "generated");
}