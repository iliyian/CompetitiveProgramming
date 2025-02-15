@echo off
:loop
M.d.exe 4 > M.in
M_Selection_Sort.exe < M.in > M.out
M.tmp.exe < M.in > M.ans
fc M.out M.ans >nul
if errorlevel 1 (
    echo Outputs differ!
    pause
    exit /b
)
goto loop