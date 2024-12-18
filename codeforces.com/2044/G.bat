@echo off

:loop
K.d 10000 > K.in
K.c < K.in > K.ans
K < K.in > K.out
fc.exe /w K.out K.ans
if errorlevel 1 goto :end

goto :loop

:end
echo Files are different!

@echo off

:loop

G.d 