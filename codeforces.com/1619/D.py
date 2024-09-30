import random, sys

sys.stdout = open("D.in", "w")

N = 1e4

print(int(N))
for _ in range(int(N)):
  print(2, 5)
  for i in range(2):
    for j in range(5):
      print(random.randint(1, int(1e9)), end=' ')
    print()