@REM @echo off

g++ dd.cpp -o dd.exe -g -O2
g++ lhn.cpp -o lhn.exe -g -O2
g++ bbf.cpp -o bbf.exe -g -O2

:loop
dd.exe > data.in
lhn.exe < data.in > data.out
bbf.exe < data.in > data.ans
fc data.ans data.out > nul
if %errorlevel% equ 1 (
    exit /b
)
goto loop