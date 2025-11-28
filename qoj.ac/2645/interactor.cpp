#include "testlib.h"
using namespace std;

int main(int argc, char** argv) {
  registerInteraction(argc, argv);

  int t = inf.readInt();
  cout.flush();
  while (t--) {
    int n = inf.readInt(2, 30000);
    cout << n << std::endl;

    std::vector<int> pa(n + 1), dep(n + 1);
    for (int i = 2; i <= n; i++) {
      int x = inf.readInt(1, i - 1);
      cout << x << ' ';
      pa[i] = x;
      dep[i] = dep[x] + 1;
    }
    std::cout << std::endl;

    auto dis = [&](int x, int y) {
      int ans = 0;
      while (dep[x] != dep[y]) {
        if (dep[x] < dep[y]) std::swap(x, y);
        x = pa[x];
        ans++;
      }
      while (x != y) {
        x = pa[x], y = pa[y];
        ans += 2;
      }
      return ans;
    };

    int left = 40;
    bool found = false;

    int ans = inf.readInt(1, n);

    for (int i = 1; i <= 40; i++) {
      char op = ouf.readChar();
      if (op == '?') {
        int x = ouf.readInt(1, n), k = ouf.readInt(0, n);
        if (dis(ans, x) <= k) {
          std::cout << 1 << std::endl;
        } else {
          std::cout << 0 << std::endl;
        }
      } else if (op == '!') {
        int guess = ouf.readInt(1, n);
        if (ans == guess) {
          found = true;
        }
        break;
      } else {
        quitf(_wa, "expected ! or ?");
      }
    }
    if (!found) {
      quitf(_wa, "failed to guess\n");
    }
  }
  quitf(_ok, "ok");
}