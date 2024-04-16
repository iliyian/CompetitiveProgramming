import random, sys

sys.stdout = open("B.in", "w")

N = 1000000000
print(100000)
for _ in range(100000):
  print(random.randint(1, N // 2) * 2, random.randint(1, N // 2) * 2)