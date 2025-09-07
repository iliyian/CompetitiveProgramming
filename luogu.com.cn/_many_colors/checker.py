from cyaron import *

# for data_id in range(1):
while True:
  t = 1
  test_data = IO(file_prefix="color", data_id=1)
  # test_data = IO()
  
  test_data.input_writeln(t)
  for i in range(t):
    n = int(6)
    w = int(6)
    test_data.input_writeln(n)
    for _ in range(n):
      test_data.input_write(randint(1, w))
    test_data.input_writeln()
    tr = Graph.tree(n)
    test_data.input_write(tr.to_str(output=Edge.unweighted_edge))
  
  Compare.program("./ok.exe", input=test_data, std_program="./bf.exe")
  