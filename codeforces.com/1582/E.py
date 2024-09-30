import random
import sys

sys.stdout = open("E.in", "w")

print(1)
print(100000)
for i in range(100000):
  print(random.randint(1, 1000000000), end=' ')