import random, sys

sys.stdout = open("A.in", "w")

N = int(2e3)
print(N)

a = [random.randint(0, 10) for i in range(N)]
random.shuffle(a)

for i in a:
  print(i, end=' ')