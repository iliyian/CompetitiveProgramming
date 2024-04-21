#include <cstdio>
#include <cmath>

// bool isPrime(const int &x)
// {
//   for (int i = 2; i * i <= x; i++)
//   {
//     if (!(x % i))
//       return false;
//   }
//   return true;
// }

// n只有两个质因数，哎

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    if (!(n % i)) {
      printf("%d", n / i);
      break;
    }
  }
  return 0;
}