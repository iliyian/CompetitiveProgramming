#/bin/bash
g++ 氯化钠.cpp -o 氯化钠.exe -g -O2
g++ dd.cpp -o dd.exe -g -O2
g++ bbf.cpp -o bbf.exe -g -O2

while :; do
./dd.exe > data.in
./氯化钠.exe < data.in > data.out
./bbf.exe < data.in > data.ans
if diff -q data.ans data.out > /dev/null; then
  echo "fine"
else
  exit
fi
done