from random import *
import sys

sys.stdout = open("M.in", "w")

N = 289
print(N)
for i in range(17):
  for j in range(17):
    print(i + 1, j + 1)
  # print(randint(int(-1e9), int(1e9)), randint(int(-1e9), int(1e9)))