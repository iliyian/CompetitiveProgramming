import random, sys

sys.stdout = open("B.in", "w")

t, N = 1, int(1e5)
print(t)
for _ in range(t):
  print(N)
  for _ in range(N):
    print(random.randint(1, N), end=' ')
  print()