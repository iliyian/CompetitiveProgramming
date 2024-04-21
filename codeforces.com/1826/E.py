import random
import sys

sys.stdout = open("E.in", "w")

print(500, 5000)

for i in range(5000):
  print(random.randint(1, 1000000000), end=' ')
print()

for _ in range(500):
  for i in range(5000):
    print(random.randint(1, i + 1), end=' ')
  print()