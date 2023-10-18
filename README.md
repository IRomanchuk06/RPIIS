# BSUIR_cmd-bash


Данная лабораторная работа была предназначена для ознакомления с командной строкой операционных систем Windows и Linux. В рамках ЛР 1 необходимо создать исполняемый файл .bat и .sh в соответствии с заданным вариантом.

## Условие ЛР 1 (60 вариант)
Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит относительный путь к папке (как параметр пакетного файла). Если такой папки нет, то писать “Данной папки нет” и завершить выполнение программы. Если такая папка есть, то в ней создайте текстовый файл result.txt, содержащий список процессов, использовавших процессор более 10 минут. Список должен быть отсортирован по времени (от большего к меньшему)

## Описание алгоритма, пример запуска и выполнения программы

![image](https://github.com/iis-32170x/RPIIS/assets/144939284/e18d5c7a-51f0-4f8f-ad12-c07d2bced28b)

#### Переменные:
- _folder_path_ - хранит относительный путь к файлу



#### Последовательность действий:
1.Ввод переменной _folder_path_ ,которая хранит в себе относительный путь к папке
2.Проверка на наличие папки, и если папки нет то программа завершается с выводом сообщения "Данной папки нет"
3.Если папка есть , то создаем в ней текстовый файл result и записываем в него данные по условию 
