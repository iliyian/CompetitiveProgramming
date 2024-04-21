import random, sys

sys.stdout = open("E.in", "w")

N = 200000

print(N)
for _ in range(N):
  print(random.randint(1, N), random.randint(1, 20))