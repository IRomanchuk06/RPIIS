@echo off
chcp 1251
setlocal enabledelayedexpansion
set /p input=������� ���� � �����:
set "fas=%input%"

rem ��������� ������������� ��������� �����
IF not EXIST "%fas%" (
  echo ������ ����� ���
  exit /b
)

rem ����� ������ .txt
(for /r "%fas%" %%F in (*.txt) do (
    rem ����� ����� "v" ��� "V"
    for /f "tokens=*" %%A in ('findstr /i "\<[vV][a-zA-Z]*[^ ]*" "%%F"') do (
        rem ��������� ������ �� ����� � ���������, ���������� �� ��� � "v"
        for %%W in (%%A) do (
            set "word=%%W"
            set "word=!word:~0,1!"
            if /i "!word!"=="v" (
                set "found="
                echo %%W>>result.txt
            )
        )
    )
))

pause