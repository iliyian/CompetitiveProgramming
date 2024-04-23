import random, sys

sys.stdout = open("D.in", "w")

N = int(2e5)
print(N, N)
for _ in range(N):
  print(random.randint(1, N), end=' ')
