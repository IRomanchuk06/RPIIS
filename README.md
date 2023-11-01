# ЛАБОРАТОРНАЯ РАБОТА №1
В рамках ЛР 1 необходимо создать файл с разрешением bat. и sh. в соответствии с заданным вариантом. Цель данной лаборотоной работы - ознакомится с командными строками операционных систем Windows и Linux.

## Условие ЛР1 (67 вариант)

![image](https://github.com/iis-32170x/RPIIS/assets/148442454/7519e6d1-e521-4cc2-a976-fb84517de373)

# Описание алгоритма, пример запуска и выполнения программы (.bat)

![image](https://github.com/iis-32170x/RPIIS/assets/148442454/40689611-950f-490f-9df2-4dcda7dd044f)

## Алгоритм программы
1. Отключаем вывод команд на экран.
2. Запрашиваем относительный путь папки.
3. Предварительно генерируем три псевдослучайных числа и находим их сумму.
4. Проверяем наличие папки в текущей директории.
5. Если папка не существует, то в консоль выводится "Данной папки нет" и программа закрывается.
6. Если папка существует, то создаём текстовый документ под названием "Numbers.txt" и записываем в него три псевдослучайных числа.
7. Программа проверяет сумму этих чисел на чётность.
8. Если сумма чисел является чётным числом, то программа создаёт файл с данными окружающей среды и считает в нём количество симоволов "\", количество которых записывает в конец файл с данными окружающей среды.
9. Если сумма чисел является нечётным числом, то программа запрашивает дату, которую сразу же разбивает на отдельные числовые переменные:день, месяц, год. Затем она считает их сумму, создаёт файл "Date.txt", в который и записывает получившееся значение.

### Переменные
- directory_file:Содержит относительный путь к папке.
- MIN: содержит минимально допустимое значение псевдослучайных чисел.
- MAX: содержит маскимально допустимое значение псевдослучайных чисел.
- range: содержит верхнюю и нижнюю границу псевднослучайных чисел .
- First_number: содержит первое псевдослучайное число.
- Second_number: содержит второе псевдослучайное число.
- Third_number: содержит третье псевдослучайное число.
- summa: содержит сумму псевдослучайных чисел.
- proverka: содержит данные о чётности числа.

## Разбор кода
1. chcp 65001: устанавливает кодировку командной строки на UTF-8..
2. @echo off: отключает вывод команд на экран.
3. set /p directory_file=" ": пользователь вводит относительный путь к папке, который сохраняется в переменной directory_file.
4. If Exist "%directory_file%\*.*" : проверяет, существует ли папка, указанная в переменной directory_file.
5. Echo %First_number%, %Second_number%, %Third_number% > Numbers.txt: создаёт текстовый документ под названием "Numbers.txt" и записывает в него три псевдослучайных числа.
6. If %proverka% == 0: проверяет сумму псевдослучайных чисел на чётность
7. set > Enviroment.txt: создаёт текстовый файл с переменными среды
8. grep -o "\" C:\Users\derne\Desktop\Enviroment.txt | grep -c .>>Enviroment.txt: производит подсчёт символа "\" в файле "Enviroment.txt" и записывает его в конец файла "Enviroment.txt"
9.  for /f "tokens=1,2,3 delims=." %%a in ("%date%") do: получает информацию о текущей дате, разбивает на день, месяц, год и записывает в токены под номером 1,2,3 соответственно
10. if !month! LSS 10 ( set "month=!month:~1!"): проверка числа месяца на ноль первой цифрой, если число меньше 10, то оно переписывается,начиная со второй цифры
11. if !day! LSS 10 (set "day=!day:~1!"): проверка числа дня на ноль первой цифрой, если число меньше 10, то оно переписывается,начиная со второй цифры
12. set /a sum=!day!+!month!+!year!: подсчёт суммы чисел текущей даты
13. Echo !sum! > Date.txt: запись суммы в текстовый документ "Date.txt"
14. Echo Данной папки нет: выводит сообщение о том, что указанной папки не существует.
15. pause: останавливает выполнение программы и ожидает нажатия клавиши пользователем.

## Пример и алгоритм работы:

Запуск bat файла с папкой sigma:

![image](https://github.com/iis-32170x/RPIIS/assets/148442454/9cf87e50-b325-4920-8f33-6492514294e1)

Содержимое рабочего стола после нескольких запусков:

![image](https://github.com/iis-32170x/RPIIS/assets/148442454/888147a8-8e18-4f98-8b53-f50260ebb120)

Содержимое папки Numbers.txt:

![image](https://github.com/iis-32170x/RPIIS/assets/148442454/13f47f6a-8d8c-467c-87c7-435e6a01d9f2)


![image](https://github.com/iis-32170x/RPIIS/assets/148442454/ee0457ea-f0c4-46c6-b232-ef7bcab15394)

![image](https://github.com/iis-32170x/RPIIS/assets/148442454/0dcf32e4-c300-45b2-b69b-44e917faac9b)

![image](https://github.com/iis-32170x/RPIIS/assets/148442454/42b0fe8e-5721-4354-a781-6a1e4a437c56)


