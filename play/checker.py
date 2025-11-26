from cyaron import *

for data_id in range(1):
  n = int(1e7)
  
  input_io = IO(file_prefix="mul", data_id=data_id + 1)
  
  input_io.input_write(randint(1, 9), separator='')
  for i in range(n - 1):
    input_io.input_write(randint(0, 9), separator='')
  input_io.input_writeln()
  
  input_io.input_write(randint(1, 9), separator='')
  for i in range(n // 2 - 1):
    input_io.input_write(randint(0, 9), separator='')
  input_io.input_writeln()
  