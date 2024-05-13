import random, sys

sys.stdout = open("C.in", "w")

t, N = 40000, int(6)

print(t)
for _ in range(t):
  print(N)
  print(0, 0, end=' ')
  for i in range(N - 2):
    print(random.randint(0, int(1e9)), end=' ')
  print()
  for i in range(N):
    print(random.randint(0, int(1e9)), end=' ')
  print()