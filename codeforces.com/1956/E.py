import random, sys

sys.stdout = open("E2.in", "w")

t = 100
print(t)

N = int(2e4)

for _ in range(t):
  print(N)
  for _ in range(N):
    print(random.randint(1, int(1e9)), end=' ')
  print()