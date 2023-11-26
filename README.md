# Цель лабораторной работы №1:

- Ознакомиться с командной строкой операционных систем _Windows_ и _Linux_.
- Создать исполняемые файлы _.bat_ и _.sh_ в соответствии с заданными правилами.

# Условие Лабораторной работы №1. Вариант 79.

создайте файл sh и bat, который выполняет следующее: на вход пакетному файлу приходит число и название папки (как параметры пакетного файла). Создать папку с таким названием. В созданной папке создать файлы, количеством равным переданному на вход пакетному файлу числу. Названия файлов должно быть случайным (явно название не должно указываться). В каждый 3-й файлы записать фразу "Hello World"

# Описание алгоритма и переменных. Пример запуска и выполнения программы.([_.bat_]() файл)

``` bash 
setlocal EnableDelayedExpansion 
	set count=%1
	set folder_name=%2
	md "%folder_name%"  
	for /L %%i in (1,1,%count%) do (
		set "file_name=%%i"
		type nul > "%folder_name%\!file_name!.txt" 
		
		set /a "remainder=%%i %% 3" 
		
		if !remainder! == 0 echo Hello World > "%folder_name%\!file_name!.txt" 
	)
	endlocal
```
## Алгоритм программы

1. Установить опцию `enabledelayedexpansion`.
2. Определить и инициализировать переменные  `count`, `folder_name`, `remainder`.
3. Создать пустые файлы  `file_name`.
4. Каждый файл получает порядковую нумерацию.
6. Когда все файлы получили нумерацию, переменная `remainder` делится на три.
7. В каждом 3 файле `file_name`, выполнить следующие действия:
   - Написать "Hello World".
  

### Переменные

- `file_name`: имя каждого файла, пронумеровонго по порядку.
- `folder_name`: Содержит имя папки, которое введет пользователь.
- `count`: Содержит число файлов, которые создает пользователь.
- `remainder`: переменная для определения четности числа на 3.


## Пример запуска

Запускаем командную строку `(Win + R)`. Для открытия папки с .bat файлом вводим  
`cd путь_к_файлу`. После того, как написали путь пишем название папки и количество файлов, которые нужно создать в этой папке

![2](https://github.com/iis-32170x/RPIIS/assets/149573033/99579f94-21b9-44ab-a557-675ebcf6271a)


Файл запущен. Папка с файлами создана.

## Пример работы программы:


Запускаем.

![3](https://github.com/iis-32170x/RPIIS/assets/149573033/bf0196d1-3360-45ec-8615-19cb1b372dd0)


Программа работает. Появились новая папка с названием belka и в ней 10 файлов.

![4](https://github.com/iis-32170x/RPIIS/assets/149573033/5525a47a-017e-4b34-997e-07971adf1d66)


В результате программы было создано 10 файлов, как видно на скриншоте в каждом третьем находиться "Hello World".


![5](https://github.com/iis-32170x/RPIIS/assets/149573033/2b7d60d1-4b37-45e7-99c8-c094c48d31ac)


# Рассмотрим файл file.sh.

## Описание алгоритма и переменных. Пример запуска и выполнения программы.([_.sh_]() файл)

> Для создания файла с расширением .sh будем использовать ([_Gitbush_](https://git-scm.com/downloads).)

Пишем путь к файлу, количетсво файлов, которые пользователь хочет создать и название папки.


![6](https://github.com/iis-32170x/RPIIS/assets/149573033/9d5f0360-842a-491c-8b11-b0d6f6964cca)


Пакетнй файл выполнил свою работу, сомтрим на результат


![7](https://github.com/iis-32170x/RPIIS/assets/149573033/a345f5a0-618d-4e7e-a4a8-67ddfd00b5f8)


В ходе работы, мы создали папку "krytou", и в ней появились 10 файлов


![8](https://github.com/iis-32170x/RPIIS/assets/149573033/b73e41f7-bb1c-43e4-861f-7c30db6b0478)



![image](https://github.com/iis-32170x/RPIIS/assets/149573033/3d25eaef-882b-4b3b-bed2-8760073eae33)


Посмотрим на то, что написано в файлах.


![9](https://github.com/iis-32170x/RPIIS/assets/149573033/177b0339-90fd-4f02-ab53-eed573e4aaa9)


Поставленная задача была выполнена.

# Итог

В ходе выполнения Лабораторной работы №1 были применил навыки работы с командной строкой в операционных системах Windows и Linux.Также разработал программы, которые реализовывали алгоритмы, соответствующие заданным условиям.
