n = 1000000000000000000000000000051

while True:
  f = True
  for i in range(2, int(n)):
    if i * i > n:
      break
    if n % i == 0:
      f = False
      print(n, "mod", i, "==", 0)
      break
  if f:
    print(n)
  n = n + 1