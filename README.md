# BSUIR_cmd-bash


Данная лабораторная работа была предназначена для ознакомления с командной строкой операционных систем Windows и Linux. В рамках ЛР 1 необходимо создать исполняемый файл .bat и .sh в соответствии с заданным вариантом.

## Условие ЛР 1 (60 вариант)
Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит относительный путь к папке (как параметр пакетного файла). Если такой папки нет, то писать “Данной папки нет” и завершить выполнение программы. Если такая папка есть, то в ней создайте текстовый файл result.txt, содержащий список процессов, использовавших процессор более 10 минут. Список должен быть отсортирован по времени (от большего к меньшему)

## Описание алгоритма, пример запуска и выполнения программы

![image](https://github.com/iis-32170x/RPIIS/assets/144939284/e18d5c7a-51f0-4f8f-ad12-c07d2bced28b)

#### Переменные:
- _folder_path_ - хранит в себе относительный путь к файлу



#### Последовательность действий:
1. Ввод переменной _folder_path_ 

2. Проверка на наличие папки, и если папки нет то программа завершается с выводом сообщения "Папка не найдена"
3. Если папка есть , то создаем в ней текстовый файл result и записываем в него данные по условию


#### Используемые команды
1. _tasklist_ - отвечает за вывод процессов используемых прецессором
2. _awk_ -фильтрует процессы по времени (больше 10 мин)


#### Пример запуска:
Запускаем командную строку:
<img width="889" alt="image" src="https://github.com/iis-32170x/RPIIS/assets/144939284/0c10bd5f-42b6-4a19-870d-493002a3727f">

 Открытие .bat файла:
  Запуск .bat файла : "Путь к файлу"


