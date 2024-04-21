#include <cstdio>
#include <iostream>
#define mod 9901
using namespace std;

int a, b, sa, n[10010][2], cot = 0, ans = 1;

int quick_pow(int ml, int nl) // 快速幂
{
  int s = 1;
  while (nl > 0) {
    if (nl % 2 == 1) {
      s = (s % mod) * (ml % mod) % mod;
    }
    ml = ml * ml % mod;
    nl = nl >> 1;
  }
  return s % mod;
}

int sum(int x, int y) {
  int k = 0;
  y = y * b;
  if (x % mod == 1) {
    k = (y + 1) % mod; // 当逆元不存在时
  } else {
    k = (quick_pow(x % mod, y + 1) - 1) % mod *
        quick_pow((x - 1) % mod, mod - 2) % mod; // 当逆元存在时
  }

  return k % mod;
}

int main() {
  freopen("data.in", "r", stdin);
  scanf("%d%d", &a, &b);
  if (a == 0) // 特判，0的因数和就是0
  {
    printf("0\n");
    return 0;
  }
  for (int i = 2; i * i <= a; i++) // 分解质因数
  {
    if (a % i == 0) {
      cot++;
      n[cot][0] = i; // 记录质因数
      n[cot][1] = 1; // 记录幂次
      a = a / i;
      while (a % i == 0) {
        n[cot][1]++; // 记录幂次
        a = a / i;
      }
    }
  }
  if (a != 1) // 可能a仍为因子
  {
    cot++;
    n[cot][0] = a;
    n[cot][1] = 1;
  }
  for (int i = 1; i <= cot; i++) {
    ans = ans * sum(n[i][0], n[i][1]) % mod;
  }
  printf("%d\n", (ans % mod + mod) % mod);
  return 0;
}