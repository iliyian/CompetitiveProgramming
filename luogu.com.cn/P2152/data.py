import sys
import random

sys.stdout = open("main.in", "w")

len = 10000

for t in range(2):
  print(random.randint(1, 9), end='')
  for i in range(1, len):
    print(random.randint(0, 9), end='')
  print('\n')
