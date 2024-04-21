import sys, random

sys.stdout = open("C.in", "w")

print(1)
print(2000, 2000, int(1e18))

for _ in range(2000):
  print('a' if random.randint(0, 1) else '*', end='')