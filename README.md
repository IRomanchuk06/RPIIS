
![фото бат](https://github.com/iis-32170x/RPIIS/assets/148863144/2b6b8aa0-0e08-43dc-8c0a-a7b6f41ca770)
```bat
@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION
echo %1
set /A y=0
set /A a=0
IF EXIST %1 GOTO :PROCESS_FILE
echo "File not exist"
GOTO :EOF

:PROCESS_FILE
 echo  "work with file"
set ff=%DATE:~0,2%
if %ff% GEQ 10 GOTO :g
set ff=%DATE:~1,1%
:g
for /F "tokens=* delims=" %%i IN (%1) DO ( 
   for %%j IN (%%i) DO (
 call set var1=%%j     
call  :NumSymbols   !var1!
      set /A  a+=!NumSymbols! 
   )
)  
goto :EXIT
:NumSymbols  
SETLOCAL ENABLEDELAYEDEXPANSION
    call set var=%~1
    call set out=%~0
    call set /A num=0 
  
    :startvarcount
    if defined var (
      set var=!var:~0,-1!

      set /A  num+=1
      goto startvarcount
    )

endlocal & set %out:~1%=%num%
exit /b
:EXIT
echo File %1 contains %a% symbols.
echo 
 for /F "tokens=* delims=" %%i IN (%1) DO ( for %%j IN (%%i) DO set /A y+=1 )  
echo kolichestvo slov = %y%
echo day = %ff%
set /A m=%ff%*%a%*%y%
echo proizvedenie = %m%
echo %m% > result.txt
echo otvet zapisan v result.txt
```
Данный код представляет собой скрипт на языке командной строки (batch script), который выполняет следующие действия:

1. Проверяет, существует ли файл, заданный в качестве аргумента командной строки. Если файл не существует, выводит сообщение "File not exist" и завершает выполнение скрипта.

2. Если файл существует, то начинает обработку файла.

3. Создает переменные "ff" и "a". Переменная "ff" получает значение дня текущей даты (первые 2 символа или первый символ, если день < 10). Переменная "a" инициализируется нулем и будет использоваться для подсчета символов в файле.

4. В цикле перебирает строки в файле. Для каждой строки выполняет внутренний цикл для каждого отдельного слова в строке.

5. Внутри внутреннего цикла вызывается функция :NumSymbols, которая подсчитывает количество символов в переданном слове и сохраняет результат в переменной "NumSymbols".

6. После выхода из внутреннего цикла, значение переменной "NumSymbols" добавляется к переменной "a" для подсчета общего количества символов в файле.

7. Выводится сообщение: "File %1 contains %a% symbols."

8. Далее происходит еще один цикл, который вычисляет количество слов в файле и сохраняет результат в переменной "y".

9. Производится вычисление произведения дня месяца (переменная "ff"), количества символов (переменная "a") и количества слов (переменная "y") и результат сохраняется в переменной "m".

10. Выводятся сообщения с результатами вычислений, а также записывается значение переменной "m" в файл "result.txt".

![фото ш](https://github.com/iis-32170x/RPIIS/assets/148863144/d863cb04-c5af-402e-96ed-bf85db79390d)

```sh
path="$1"
if [ -f "$path" ]; then
  echo "File exists"
else
  echo "File does not exist"
  exit
fi

data=$(date +%d)
word=$(wc -w < "$path")
letter=$(cat "$path" | tr -cd '[[:alpha:]]' | wc -c)
result=$((data * word * letter))
echo "Data: $data"
echo "Word count: $word"
echo "Letter count: $letter"
echo "Result: $result"
echo "$result" > result.txt
```
Данный код представляет собой скрипт на языке bash. Кратко о его функциональности:

1. Считывается путь к файлу из аргумента командной строки и сохраняется в переменной "path".
2. Проверяется, существует ли файл по указанному пути. Если файл существует, выводится сообщение "File exists". Если файла не существует, выводится сообщение "File does not exist" и выполнение скрипта прерывается.
3. Получается текущая дата и сохраняется в переменной "data".
4. Подсчитывается количество слов в файле по указанному пути с помощью команды "wc -w" ("wc" - утилита подсчета статистики по файлу).
5. Из содержимого файла удаляются все символы, за исключением букв, с помощью команды "tr -cd '[[:alpha:]]'". Затем подсчитывается количество оставшихся букв.
6. Вычисляется результат умножением значения "data" на значение "word", а затем на значение "letter". Результат сохраняется в переменной "result".
7. Выводится информация о переменных "data", "word", "letter" и "result".
8. Результат сохраняется в файл "result.txt".
