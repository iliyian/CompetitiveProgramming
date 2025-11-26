from cyaron import *

run = 0

while True:
  run += 1
  print("Running:", run)
  for data_id in range(1):
    input_io = IO(file_prefix="mexs", data_id=data_id+1)
    
    t = 1
    input_io.input_writeln(t)
    for test_id in range(t):
      # n = int(randint(1, 5000))
      n = 1000000
      input_io.input_writeln(n)
      
      for i in range(n):
        input_io.input_write(randint(0, n + 1))
        
      input_io.input_writeln()
      
    # Compare.program("./ok.exe", input=input_io, std_program="./bf.exe")
  break