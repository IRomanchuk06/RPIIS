@echo off 
chcp 1251
if not exist File1.txt type nul>File1.txt
if not exist File2.txt type nul>File2.txt
attrib -h File2.txt
if exist log.txt del log.txt
set /p f1=������� ���� � ������� �����: 
start %f1%
pause
set /p f2=������� ���� �� ������� �����: 
start %f2%
pause
type nul>log.txt
fc /c File1.txt File2.txt>>log.txt
set r=%ERRORLEVEL%
if %r%==0 (
    echo ����� ���������, �� ����������:
    echo ����� �������>>log.txt
    echo ������� ���������� ������� ����� � �������>>log.txt
    type File1.txt
) else (
    echo ����� �� �������
    echo ����� �� �������>>log.txt
    del File1.txt
    echo ������� ������ ����>>log.txt
    attrib +h File2.txt 
    echo ������ ������ ���� �������>>log.txt
)
pause
