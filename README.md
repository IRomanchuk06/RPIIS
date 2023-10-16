# BSUIR cmd-bash
В рамках ЛР 1 необходимо создать файл с разрешением *bat.* и *sh.* в соответствии с заданным вариантом.
Цель данной лаборотоной работы - ознакомится с командными строками операционных систем *Windows* и *Linux*.

# Условие ЛР1 (41 вариант)
![image](https://github.com/iis-32170x/RPIIS/assets/144945398/a818acf3-39ad-41af-b15f-a19f575d898b)

# Описание алгоритма, пример запуска и выполнения программы (.bat)

![Снимок экрана (11)](https://github.com/iis-32170x/RPIIS/assets/144945398/c0124185-9073-4340-bc27-326422e4606b)

#### Используемые переменные:
- *N* - переменная, которая получает значение из параметра командной строки.
- *count* - переменная, используемая для подсчета количества итераций в цикле.
- *max_mem_process* -  переменная, которая хранит текущую строку с процессом с наибольшим использованием памяти.
- *first_line* -  переменная, которая хранит первую строку из результата команды tasklist.
- *day, month, year* - переменные, используемые для хранения текущей даты.
- *formatted_dat* -  переменная, которая хранит отформатированную дату.
- *filename* -  переменная, которая хранит имя файла для записи.

 ## Разбор кода:

      setlocal enabledelayedexpansion
Режим отложенного расширения переменных среды. Позволяет использовать перезаписывающиеся переменные с !...!.

## Пример и алгоритм работы:
    Запуск командной строки 
    
![Снимок экрана (9)](https://github.com/iis-32170x/RPIIS/assets/144945398/d0580b63-e1b6-41ee-a5a8-a01fd69a062c)

    Открытие .bat файла:
    Переход к папке - _cd_путь к папке_
    Запуск .bat файла - start "Имя файла"

 
