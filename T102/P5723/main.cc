#include <cstdio>

bool isPrime(const int &n)
{
  for (int i = 2; i * i <= n; i++)
  {
    if (!(n % i))
      return false;
  }
  return true;
}

int main()
{
  int L, sum = 0, count = 0;
  scanf("%d", &L);
  for (int i = 2; sum + i <= L; i++)
  {
    if (isPrime(i)) {
      sum += i;
      count++;
      printf("%d\n", i);
    }
  }
  printf("%d", count);
  return 0;
}