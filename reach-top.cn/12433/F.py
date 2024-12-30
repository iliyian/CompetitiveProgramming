import math

def gcd(a, b):
  return b if gcd(b, a % b) else a

def fac(x):
  if not x:
    return 1
  return x * fac(x - 1)

def isprime(x):
  if x < 2:
    return False
  for i in range(2, int(math.sqrt(x)) + 1):
    if x % i == 0:
      return False
  return True

a, b, c = 0, 1, 10
while c:
  if isprime(b):
    print(f'{b:<8}', end='')
    c -= 1
  a, b = b, a + b
print()