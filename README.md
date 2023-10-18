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
    Запуск .bat файла -  "Имя файла"

   ![Снимок экрана (12)](https://github.com/iis-32170x/RPIIS/assets/144945398/a148b06f-e6b2-45d5-a338-78372ca29c0e)
  
     Ввод количества процессов 
     Вывод процессов, которые потребляют больше всего памяти по убыванию.

![Снимок экрана (13)](https://github.com/iis-32170x/RPIIS/assets/144945398/a193f04c-c161-4f6d-85c3-310ff8bc51fa)

Программа успешно заканчивает работу, после чего переходим в папку, где хранится .bat файл и замечаем новый файл соответствующий “имя_процесса дата”
.txt, давайте откроем его 

![Снимок экрана (14)](https://github.com/iis-32170x/RPIIS/assets/144945398/e1d071f1-1978-4843-ac9f-8f3b5c2f46b6)

Работа .bat файла окончена.

