<h1> <B>BSUIR Лабораторная работа №2. </B> </h1>
В рамках лабоаторной работы №1 необходимо было создать исполняемый файл в соответствии с заданным вариантом.
<h2> Условие лаборатнорной работы 85 вариант: </h2>
Создать файл sh и bat, который выполняет следующее: 
<br>На вход пакетному файлу приходит число (как параметры пакетного файла). 
<br>Если число отрицательное, то выводим сегодняшнюю дату в формате mm-dd-yyyy, 
<br>если если число положительное и четное, то выводим текущую дату в формате mm/dd/yyyy, 
<br>если число положительное и нечетное то выводим текущий месяц.
<h3>Пример запуска и выполнения программы (.bat)</h2>
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/images/desktop.png"> </image>
Открываем командуную строку cmd (Win+R)
<hr>
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/images/cmd.png"> </image>
Запускаем файл с лабороторной работой
<hr>
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/images/first.value.png"> </image>
1) Число отрицательное (mm-dd-yyyy)
<hr>
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/images/second%2Cvalue.png"> </image>
2) Число положительное четное (mm/dd/yyyy)
<hr>
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/images/third.value.png"> </image>
3) Число положительное нечетное (mm)
<hr>
<h3>Пример запуска и выполнения программы (.sh) </h3>
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/images/openshell.png?raw=true"> </image>
Запускаем скрипт lab.sh как приложение.
<hr>
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/images/shellvalue1.png?raw=true"> </image>
1) Число отрицательное (mm-dd-yyyy)
<hr>
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/images/shellvalue2.png?raw=true"> </image>
2) Число положительное четное (mm/dd/yyyy)
<hr> 
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/images/shellvalue3.png?raw=true"> </image>
3) Число положительное нечетное (mm)
<hr>
<h2>Алгоритм и код скрипта: </h2>
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/images/batcode.png"> </image>
<h3>Алгоритм работы(.bat): </h3>
<I>1. Выводим сообщение пользовтелю "Eneter number" считывая его ответ в переменную n. </I>
<br><I>2. Создаем переменную s равную остатку от деления числа n на 2.</I>
<br><I>3. Возвращаем текущее локальное время и записываем его по соответствующим переменным.</I>
<br><I>4. Проверяем число введенное пользователем на удоволетворения условиям вывода. </I>
<br><I>5. Ожидаем пока пльзователь нажмет какую-либо клавишу. </I>
<h3>Разбор кода(.bat): </h3>
<I>1. <B>set /p n=Enter number</B> — Создаем переменную n с одноврменным выводом сообщения "Enter number:" пользователю и считываем его ввод записывая в переменную n.   </I>
<br><I>2. <B>set /a s= n %% 2</B> — Создаем переменную s равную остатку от деления числа n на 2.</I> 
<br><I>3. <B>for /f %%a in ('wmic path win32_LocalTime get * /value') do >nul set "%%a"</B> — Возвращаем текущее локальное время в формате WMI. Создается переменная среды с именем и значением, соответствующими элементу. Перенаправляем в нулевое устройство, чтобы не выводить значения на экран. </I>
<br><I>4. <B>if %n% lss 0 echo %Month%-%Day%-%Year% </B> — Условная констукция которая смотрит меньше ли значение переменной n чем 0, если да то выводим в формате mm-dd-yyyy </I>
<br><I>5. <B>if %n% gtr 0  if %s%  == 0  echo %Month%/%Day%/%Year% </B> — Условная констукция которая смотрит больше ли значение переменной n чем 0 и равен ли остаток этого числа при делении на 2 нулю, если да то выводим в формате mm/dd/yyyy </I>
<br><I>6. <B>if %n% gtr 0  if %s% == 1  echo %Month% </B> — Условная констукция в которая смотрит больше ли значение переменной n чем 0 и равен ли остаток этого числа при делении на 2 одному, если да то выводим текущий месяц. </I>
<br><I>7. <B>pause</B> — Останавливает выполнение программы и ожидает нажатия клавиши пользователем.</I>
<br><I>8. <B>exit</B> — Выход из программы.</I>
<hr>
<image src="https://github.com/iis-32170x/RPIIS/blob/%D0%9A%D1%83%D1%87%D1%83%D0%BA_%D0%A2/images/codeshell.png?raw=true"> </image>
<h3>Алгоритм работы(.sh): </h3>
-
<h3>Разбор кода(.sh): </h3>
-
<h2>Итог:</h2>
Приобрели базовые навыки работы с командной строкой. Написали скрипт соответствующий поставленой задаче.

