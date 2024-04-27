from random import randint
import sys

sys.stdout = open("A.in", "w")

n, m = int(1e5), int(1e5)
print(n, m)

for _ in range(m):
  u = randint(1, n - 1)
  v = randint(u + 1, n)
  print(u, v, randint(1, 2))