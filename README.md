# Лабораторная работа 1

## Цель лабораторной работы №1:


 - Ознакомиться с командной строкой операционных систем _Windows_ и _Linux_.

 - Создать исполняемые файлы _.bat_ и _.sh_ в соответствии с заданными правилами.



## Условие Лабораторной работы №1. Вариант 18.
 ![image](1.png)



## Описание алгоритма. Пример запуска и выполнения программы.([_.bat_]() файл)
![image](2.png)
### Алгоритм программы


 1. Установливаем опцию `enabledelayedexpansion` для включения режима отложенного разрешения переменных 

 2. Проверяем существование папки, которая находиться по пути, переданному в качестве параметра пакетного файла,  с помощью условного оператора `if` 
 2.1 Если папки не существует переходим по ссылке `error1` для завершения выполнения пакетного файла с выводом соответствующего сообщения, иначе продолжаем выполнение пакетного файла
 3. Запускаем выполнения цикла в котором переменной `f` присваивается поочередно название файла из перечня всех файлов расположенных в папке и всех вложенных подпапках отсортированных в порядке возрастания размера
 4. На последнем шаге цикла переменная `f` принимает значение имени файла с наибольшим размером
 5. вызываем внутреннюю процедуру `size` с аргументом `f`, с целью использовать возможность вычисления размера необходимого нам файла командой `~z`
 
6. создаем результирующий файл `result.txt` и записываем в него текстовую строку
 7. выводим в результирующий файл размер файла переданного в виде аргумента
 8. инициализируем переменные `count`, `countlet`, `ln` и присваиваем им исходные значения равные `0`
 9. выводим в реультирующий файл текстовую строку
10. запускаем цикл, в котором поочередно перебираем строки в отрабатываемом файле
11. запускаем вложенный цикл, в котором перебираем поочередно слова в каждой строке полученной на этапе предыдущего цикла
12. увеличиваем переменную `count` на 1 считая количество слов в файле
13. выводим во временный файл обрабатываемое слово с целью подсчета количества его букв.
14. используем команду размера файла за вычетом 2 символов которые учитывают перенос строки, тем самым получая количество букв в слове.
15. увеличиваем переменную `countlet` на количество букв рассматриваемого слова.
16. выводим в результирующий файл количество слов, полученное в переменной `count`.
17. выводим в результирующий файл количество букв, полученное в переменной `countlet`.
18. выводим в результирующий файл количество строк, полученное командой `find`.
19. переходим в конец скрипта для завершения его работы.

## Пример работы программы:
![image](4.png)
## Описание алгоритма. Пример запуска и выполнения программы.([_.sh_]() файл)

### Алгоритм программы

 1. инициализируем возможность использования библиотеки команд `bash`
 2. проверяем на существование директории переданной в аргументе скрипта, в случае отсутствия завершаем выполнение скрипта, иначе продолжаем выполнение
 3. присваиваем переменной `f` файл с наибольшим размером из директории и всех вложенных поддиректорий
 4. выводим размер файла полученный командой `$stat` в результирующий файл 
 5. присваиваваем переменной `countlet` количество букв с помощью команды `$wc -m`
 6. присваиваваем переменной count количество слов с помощью команды `$wc -w`
 7. выводим `count` и `countlet` в результирующий файл
 8. выводим количество строк командой `wc -l` в результирующий файл
 9. завершаем работу скрипта

## Пример работы программы:

# Вывод
В ходе выполнения Лабораторной работы №1 были применены навыки работы с командной строкой в операционных системах Windows и Linux.Также разработала программы, которые реализовывали алгоритмы, соответствующие заданным условиям.

