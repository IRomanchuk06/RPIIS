# BSUIR_cmd-bash

Данная лабораторная работа была предназначена для ознакомления с командной строкой операционных систем **Windows** и **Linux**.
В рамках ЛР 1 необходимо создать исполняемый файл _.bat_ и _.sh_ в соответствии с заданным вариантом.

## Условие ЛР 1 (61 вариант)

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/task.png)

## Описание алгоритма, пример запуска и выполнения программы ([_.bat_](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/LAB1.bat) файл)

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/bat1.png)

На вход программе приходит 2 относительных пути к папкам. Одна из них содержит .txt файлы и другие, вторая - пустая.

#### Переменные:

- _folder1_ - хранит путь к первой папке.
- _folder2_ - хранит путь ко второй папке.
  
#### Методы:

- _exist_ - проверяет существование папки с веденным путем.
- _move_ - перемещает файл.
- _attrib_ - присваивает атрибут.

#### Последовательность действий:

1. Ввод переменных _folder1_ и _folder2_.
2. Проверка на существование файлов с путями _folder1_ и _folder2_.
3. В случае валидности двух переменных - пункт 4,  иначе - завершает работу с выводом отладочной информации.
4. Переносит все файлы формата _.txt_ из первой папки во вторую.

#### Пример запуска

Запустим командную строку **cmd** любым удобным способом

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/bat3%20(2).png)

После запуска нас встречает командная строка. Для выполнения нашего [_.bat_](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/LAB1.bat) файла, перейдём в соответствующую папку для запуска нашего файла с помощью пути файла.

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/bat3.png)

Ваш .bat файл успешно запущен!

#### Пример выполнения программы

Перед демонстрацией работы программы создадим 2 произвольные папки: первая папка содержит несколько файлов .txt и другие, вторая - пустая

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/qw.png)

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/er.png)


На входе программа, соответствуя условию, запрашивает путь первой папки, а после и второй папки. Для отображения полного функционала введём для начала корректные данные

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/bat3.png)

Программа успешно заканчивает работу, после чего переходим в папку, где хранились .txt файлы, и замечаем что их там нет; переходим во вторую папку и замечаем .txt файлы из первой папки.

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/r1.png)

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/r2.png)

Для проверки корректности работы программы, так же введём несуществующие пути

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/r3.png)

#### На этом функционал .bat файла заканчивается. Теперь рассмотрим подробнее .sh файл

## Описание алгоритма, пример запуска и выполнения программы ([_.sh_](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/lab1.sh) файл)

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/sh1.png)

На вход программе приходит 2 относительных пути к папкам. Одна из них содержит .txt файлы и другие, вторая - пустая.

#### Переменные:

- _folder1_ - хранит путь к первой папке.
- _folder2_ - хранит путь ко второй папке.

#### Методы:

- _checkNumber_ - проверяет переменную **number** на валидность
- _checkPath_ - проверяет переменную **path** на валидность

#### Последовательность действий:

1. Ввод переменных _folder1_ и _folder2_.
2. Проверка на существование файлов с путями _folder1_ и _folder2_.
3. В случае валидности двух переменных - пункт 4,  иначе - завершает работу с выводом отладочной информации.
4. Переносит все файлы формата _.txt_ из первой папки во вторую.

#### Пример запуска

Запустим командную строку **git bash** любым удобным способом

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/sh2.png)

После запуска нас встречает командная строка. Для выполнения нашего [_.sh_](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/lab1.sh) файла, перейдём в соответствующую папку для запуска нашего файла с помощью консольной команды _cd_ (change directory)

      cd путь_к_файлу

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/sh3.png)

Для выполнения любого .sh файла, необходимо прописать консольную команду

     ./название_файла.sh

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/sh4.png)

Ваш .sh файл успешно запущен!

#### Пример выполнения программы

Перед демонстрацией работы программы создадим 2 произвольные папки: первая папка содержит несколько файлов .txt и другие, вторая - пустая

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/qw.png)

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/er.png)


На входе программа, соответствуя условию, запрашивает путь первой папки, а после и второй папки. Для отображения полного функционала введём для начала корректные данные

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/sh5.png)

Программа успешно заканчивает работу, после чего переходим в папку, где хранились .txt файлы, и замечаем что их там нет; переходим во вторую папку и замечаем .txt файлы из первой папки.

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/sh6.png)

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/sh7.png)

Для проверки корректности работы программы, так же введём несуществующие пути

![image](https://github.com/iis-32170x/RPIIS/blob/%D0%A8%D0%B0%D1%80%D0%BA%D0%BE_%D0%A1/sh8.png)

# Итог

Во время ЛР 1 были применены навыки работы в командной строке **Windows** и **Linux**. Были созданы программы, выполняющие алгоритмы, соответствующие условиям ЛР 1
