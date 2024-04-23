import random, sys

sys.stdout = open("D.in", "w")

N = int(1e6)
print(N)

for _ in range(N):
  print(random.randint(1, N), end=' ')