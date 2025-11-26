from cyaron import *

N = 5201314
MOD = int(1e9) + 7
ans = [0] * (N + 1)
fac = 1
for i in range(1, N + 1):
  fac = fac * i % MOD
  ans[i] = (ans[i - 1] + fac) % MOD * i % MOD

tot = 0
for data_id in range(6):
  input_io = IO(file_prefix="mexsp", data_id=data_id + 1)
  t = 1000000
  if data_id == 5:
    t = 201314
  input_io.input_writeln(t)
  for i in range(t):
    tot += 1
    input_io.input_writeln(tot)
    input_io.output_writeln(ans[tot])
  
  