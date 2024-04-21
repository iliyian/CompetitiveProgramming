import sys
import random

sys.stdout = open("E.in", "w")

print("1\n300000 300000")
for i in range(1, 300001):
  print(random.randint(1, 300000), end=' ')

for i in range(1, 300001):
  print(random.randint(1, 300000), random.randint(1, 300000))