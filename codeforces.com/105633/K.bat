@echo off
setlocal enabledelayedexpansion

:loop
    echo Running test case...
    REM 生成测试数据（注意参数是100000）
    K.d.exe 10 5 > K.in
    if !errorlevel! neq 0 (
        echo Error: Failed to generate input
        exit /b
    )

    REM 运行第一个程序
    type K.in | K_Scheduling_Two_Meetings.exe > K.out
    if !errorlevel! neq 0 (
        echo Error: K_Scheduling_Two_Meetings.exe failed to run
        exit /b
    )

    REM 运行第二个程序
    type K.in | K.bf > K.ans
    if !errorlevel! neq 0 (
        echo Error: K.bf.exe failed to run
        exit /b
    )

    REM 比较输出文件
    fc K.out K.ans > nul
    if !errorlevel! equ 0 (
        echo Test passed
    ) else (
        echo Test failed! Showing diff:
        fc K.out K.ans
        exit /b
    )
goto loop
endlocal