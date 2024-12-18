@echo off
setlocal enabledelayedexpansion
for /r %%i in (*_*) do (
    set "filename=%%~ni"
    set "newfilename=!filename:_=!"
    ren "%%i" "!newfilename!%%~xi"
)
