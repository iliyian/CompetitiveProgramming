#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  vector<int> num;
  scanf("%d", &n);
  num.push_back(n);
  while (n != 1) {
    if (!(n & 1)) {
      n >>= 1;
      num.push_back(n);
    } else {
      n = n * 3 + 1;
      num.push_back(n);
    }
  }
  reverse(num.begin(), num.end());
  for (int i = 0; i < num.size(); i++) {
    printf("%d ", num[i]);
  }
  return 0;
}