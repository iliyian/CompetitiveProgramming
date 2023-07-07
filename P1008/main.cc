#include <cstdio>
#include <cstring>
int counts[10];

bool check(int n) {
  int a = n%10; n /= 10;
  int b = n%10; n /= 10;
  int c = n%10;
  if (a == 0 || b == 0 || c == 0) return false;
  if (counts[a]) return false;
  counts[a] = 1;
  if (counts[b]) return false;
  counts[b] = 1;
  if (counts[c]) return false;
  counts[c] = 1;
  return true;
}

int main() {
  memset(counts, 0, sizeof(counts));
  for (int a = 123; a < 333; a++) {
    int b = a*2, c = a*3;
    if (!check(a) || !check(b) || !check(c)) {
      memset(counts, 0, sizeof(counts));
    } else {
      memset(counts, 0, sizeof(counts));
      printf("%d %d %d\n", a, b, c);
    }
  }
  return 0;
}