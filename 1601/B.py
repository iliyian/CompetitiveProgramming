import random, sys

sys.stdout = open("B.in", "w")

N = 300000
print(N)
for i in range(1, N + 1):
  print(random.randint(0, min(i, 1000)), end=' ')
print()
for i in range(1, N + 1):
  print(random.randint(0, min(N - i, 100)), end=' ')