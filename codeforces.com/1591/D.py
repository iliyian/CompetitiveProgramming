import random
import sys

sys.stdout = open("D.in", "w")
# print(1)
print(100000)

for _ in range(100000):
  print(5)
  for _ in range(5):
    print(random.randint(1, 500000), end=' ')
  print()