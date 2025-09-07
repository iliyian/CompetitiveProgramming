import math
n = 4000000
sum = 0
for i in range(n):
  sum += math.log2(i + 1)
print(sum)