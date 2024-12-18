#include <cstdio>
#include <bitset>
#include <cmath>
using namespace std;

bitset<1024> square[1024];

void pray(int x, int y, int len) {
  if (len == 1) return;
  int mid = len / 2;
  for (int i = x; i < x + mid; i++)
    for (int j = y; j < y + mid; j++)
      square[i][j] = 0;
  pray(x + mid, y, mid);
  pray(x, y + mid, mid);
  pray(x + mid, y + mid, mid);
}

int main() {
  for (int i = 0; i < 1024; i++) square[i].flip();
  int n;
  scanf("%d", &n);
  int len = pow(2, n);
  pray(0, 0, len);
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++)
      printf("%d ", square[i][j] ? 1 : 0);
    putchar('\n');
  }
  return 0;
}