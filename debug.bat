@echo off
set generator = %1
set output = %2
set answer = %3
for /l %%i in (1, 1, 100) do (
    echo %%i

    %~1 %%i 5 > inputf.txt
    %2 < inputf.txt > outputf.txt
    %3 < inputf.txt > answer.txt

    fc outputf.txt answer.txt || goto :out
)

:out