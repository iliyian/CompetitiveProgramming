import sys
from random import randint as rand

sys.stdout = open("D.in", "w")

t, n, m, k = 10000, 20, 20, 10
N = int(1e6)
print(t)
for _ in range(t):
  print(n, m, k)
  for _ in range(n):
    print(rand(1, N), end=' ')
  print()
  for _ in range(m):
    print(rand(1, N), end=' ')
  print()