T = int(input())

mx = 1e200
f = [0, 3, 20]

len = 2
for i in range(3, 200000):
  f.append(6 * f[i - 1] - f[i - 2] + 2)
  len += 1
  if f[-1] > mx:
    break

# for i in f:
#   print(i)

for _ in range(T):
  n = int(input())
  l, r = 1, len
  ans = -1
  while l <= r:
    mid = (l + r) // 2
    if f[mid] > n:
      ans = f[mid]
      r = mid - 1
    else:
      l = mid + 1
  print(ans)