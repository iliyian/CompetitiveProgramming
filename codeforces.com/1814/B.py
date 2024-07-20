import sys, random

sys.stdout = open("B.in", "w")

T, N = 100, int(1e9)

print(T)
for _ in range(T):
  print(random.randint(1, N), random.randint(1, N))