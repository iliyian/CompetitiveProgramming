#include <cstdio>

bool isPalin(int n) {
  if (n < 10 || n == 11) return true;
  char num[9];
  int len = 0;
  while (n) {
    num[len++] = n % 10;
    n /= 10;
  }
  for (int i = 0; i <= len / 2; i++)
    if (num[i] != num[len - 1 - i])
      return false;
  return true; 
}

bool isPrime(const int &n) {
  if ((n != 11 && 10 <= n && n <= 19) || (1000 <= n && n <= 9999) || (100000 <= n && n <= 999999) || (10000000 <= n && n <= 99999999)) return false;
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++)
    if (!(n % i))
      return false;
  return true;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  if (a <= 2) printf("2\n");
  if (a % 2 == 0) a++;
  for (int i = a; i <= b; i += 2) {
    if (i >= 10000000) break;
    if (isPrime(i) && isPalin(i))
      printf("%d\n", i);
  }
  return 0;
}