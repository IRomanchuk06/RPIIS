# BSUIR_cmd-bash
Данная лабораторная работа была предназначена для ознакомления с командной строкой операционных систем Windows и Linux. В рамках ЛР 1 необходимо создать исполняемый файл .bat и .sh в соответствии с заданным вариантом.
## Условие ЛР 1 (82 вариант)
![image](https://github.com/iis-32170x/RPIIS/assets/147264756/ccad6678-8eec-4af5-a0d9-fbaed95b1c83)
## Описание алгоритма, пример запуска и выполнения программы (.bat файл)
```@echo off
set /a date1 = %date:~0,1%
set /a date2 = %date:~1,1%
set /a date3 = %date:~2,1%
set /a date4 = %date:~3,1%
set /a date5 = %date:~4,1%
set /a date6 = %date:~5,1%
set /a date7 = %date:~6,1%
set /a date8 = %date:~7,1%
if %date1% geq %date1% if %date1% geq %date2% if %date1% geq %date3% if %date1% geq %date4% if %date1% geq %date5% if %date1% geq %date6% if %date1% geq %date7% if %date1% geq %date8% set /a a=%date1%
if %date2% geq %date1% if %date2% geq %date2% if %date2% geq %date3% if %date2% geq %date4% if %date2% geq %date5% if %date2% geq %date6% if %date2% geq %date7% if %date2% geq %date8% set /a a=%date2%
if %date3% geq %date1% if %date3% geq %date2% if %date3% geq %date3% if %date3% geq %date4% if %date3% geq %date5% if %date3% geq %date6% if %date3% geq %date7% if %date3% geq %date8% set /a a=%date3%
if %date4% geq %date1% if %date4% geq %date2% if %date4% geq %date3% if %date4% geq %date4% if %date4% geq %date5% if %date4% geq %date6% if %date4% geq %date7% if %date4% geq %date8% set /a a=%date4%
if %date5% geq %date1% if %date5% geq %date2% if %date5% geq %date3% if %date5% geq %date4% if %date5% geq %date5% if %date5% geq %date6% if %date5% geq %date7% if %date5% geq %date8% set /a a=%date5%
if %date6% geq %date1% if %date6% geq %date2% if %date6% geq %date3% if %date6% geq %date4% if %date6% geq %date5% if %date6% geq %date6% if %date6% geq %date7% if %date6% geq %date8% set /a a=%date6%
if %date7% geq %date1% if %date7% geq %date2% if %date7% geq %date3% if %date7% geq %date4% if %date7% geq %date5% if %date7% geq %date6% if %date7% geq %date7% if %date7% geq %date8% set /a a=%date7%
if %date8% geq %date1% if %date8% geq %date2% if %date8% geq %date3% if %date8% geq %date4% if %date8% geq %date5% if %date8% geq %date6% if %date8% geq %date7% if %date8% geq %date8% set /a a=%date8%
set /a b=%a%/2*2
if %a%==%b% (  echo > d:%a% ) else (echo Hello )
pause
```
### Переменные:
- date1 - 1е число даты
- date2 - 2е число даты
- date3 - 3е число даты
- date4 - 4е число даты
- date5 - 5е число даты
- date6 - 6е число даты
- date7 - 7е число даты
- date8 - 8е число даты
- a - наибольшее число даты
- b - переменная для проверки на четность
### Методы:
- set /a - инициализирует переменную, ключ /а указывает, что строка справа от знака равенства является числовым выражением.
- if - оператор условного выполнения команд.
- geq - оператор сравнения, больше или равно.
- echo - вывод текста на экран консоли, вывод значения переменной в название файла.
- date - значение текущей даты.
### Последовательность действий
1. Присваивание перменным зачения чисел даты
2. Сравнение переменных для поиска наибольшего числа
3. Присваевание перменной а значения наибольшего числа
4. Проверка на четность
5. Создание файла с максимальной числом в названии, если число оказалось четным, или вывод Неllo в консоль, если нет
### Пример запуска
![image](https://github.com/iis-32170x/RPIIS/assets/147264756/e3e3b12b-c78c-4971-bb5f-f574d5aafaa6)
![image](https://github.com/iis-32170x/RPIIS/assets/147264756/e6602093-ca91-4933-a335-862d0b9f9700)
![image](https://github.com/iis-32170x/RPIIS/assets/147264756/570ff8f4-3cc2-43f0-b6ae-1cad8dbabbdf)
## Описание алгоритма, пример запуска и выполнения программы (.sh файл)
```
#!/bin/bash
mkdir /home/mayu/Рабочий\ стол/papka
date +%Y-%m-%d > /home/mayu/Рабочий\ стол/papka/data.txt
grep -o "[0-9]" /home/mayu/Рабочий\ стол/papka/data.txt > /home/mayu/Рабочий\ стол/papka/cifri.txt
counter=1
while [ $counter -le 8 ]
do
m[$counter]=`sed -n "$counter"p /home/mayu/Рабочий\ стол/papka/cifri.txt`
((counter++))
done
counter=1
while [ $counter -le 8 ]
do
if (( ${m[$counter]} >= ${m[1]} )) && (( ${m[$counter]} >= ${m[2]} )) && (( ${m[$counter]} >= ${m[3]} )) && (( ${m[$counter]} >= ${m[4]} )) && (( ${m[$counter]} >= ${m[5]} )) && (( ${m[$counter]} >= ${m[6]} )) && (( ${m[$counter]} >= ${m[7]} )) && (( ${m[$counter]} >= ${m[8]} )); then 
				a=${m[$counter]}
				fi
((counter++))
done
let "b=$a/2*2"
			if [ $b == $a ]; then
				echo > /home/mayu/Рабочий\ стол/papka/"$a"
			else
				echo "Hello"
			fi
rm /home/mayu/Рабочий\ стол/papka/data.txt
rm /home/mayu/Рабочий\ стол/papka/cifri.txt
read -p "Press any key"
```
### Переменные:
- counter - счетчик элементов в массиве
- а - наибольшее число в дате
- b - переменная для проверки на четность
### Методы:
- mkdir - создания новых каталогов.
- date +%Y-%m-%d - значение текущей даты, ключи +%Y-%m-%d для вывода даты в виде год-месяц-число.
- grep -o - поиск в файле, ключ -о позволяет выводить отдельно нужные нам элементы.
- while [условие] do - цикл, который повторяет действия, пока словие истинно.
- sed -n - редактор текста, ключ -n позволяет отобразить только те строки, где выполнилась замена.
- if - оператор условного выполнения команд.
- let - присваивание значений переменной с арифметическими операциями.
- echo - вывод текста на экран консоли, вывод значения переменной в название файла.
- rm - удаление файлов и каталогов.
### Последовательность действий
1. Создание папки для папки для последующей работы в ней
2. Вывод даты в файл
3. Разделение чисел даты и вывод их в отдельный файл
4. Создание массива и присваевание каждому элементу массива числа даты
5. Сравнение между собой значений элементов массива
6. Присваевание перменной а значения наибольшего числа
7. Проверка на четность
8.  Создание файла с максимальной числом в названии, если число оказалось четным, или вывод Неllo в консоль, если нет
### Пример запуска
![изображение](https://github.com/iis-32170x/RPIIS/assets/147264756/a9153013-8ae2-4456-87db-7f36f4bd6118)
![изображение](https://github.com/iis-32170x/RPIIS/assets/147264756/5fc313fb-326e-4f83-96d5-cd01e40fbdff)
![изображение](https://github.com/iis-32170x/RPIIS/assets/147264756/92619596-0425-45b2-ae40-7f37d4330c9d)
