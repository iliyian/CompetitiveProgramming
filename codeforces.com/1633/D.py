import random, sys

sys.stdout = open("D.in", "w")

t, n, k = 100, 10, int(1e6)
print(t)

for _ in range(t):
  print(n, k)
  for i in range(n):
    print(1000 - i, end=' ')
  print()
  for _ in range(n):
    print(random.randint(1, int(1e6)), end=' ')
  print()
