@echo off
title 对拍脚本

:loop
rem 调用 E.d.exe 生成数据并保存到 E.in
E.d.exe 100 > E.in

rem 运行 E.exe 并将输出保存到 E.out
E.exe < E.in > E.out

rem 运行 E.a.exe 并将输出保存到 E.ans
E.a.exe < E.in > E.ans

rem 对比 E.out 和 E.ans
fc E.out E.ans > nul 2>&1
if errorlevel 1 (
    echo 发现不同！
    echo ------------------- E.in -------------------
    type E.in
    echo ------------------- E.out -------------------
    type E.out
    echo ------------------- E.ans -------------------
    type E.ans
    pause
    exit /b
)

goto loop
