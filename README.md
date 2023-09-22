# ПОИИС
Репозиторий дисциплины Представление и обработка информации в интеллектуальных системах 
(Representation and processing of information in intelligent systems) для групп потока 32170х.
С условиями лабораторных работ можно ознакомиться в папке соответствующего семестра.

# Цель лабораторной работы №1:
* Ознакомиться с командной строкой операционных систем *Windows* и *Linux*.
* Создать исполняемые файлы *.bat* и *.sh* в соответствии с заданными правилами.

# Условие Лабораторной работы №1. Вариант 56.
   
![image](https://github.com/iis-32170x/RPIIS/assets/144939580/378b14c4-8add-4505-9698-10d222d17196)


# Описание алгоритма и переменных. Пример запуска и выполнения программы.([_.bat_]() файл)

   ![image](https://github.com/iis-32170x/RPIIS/assets/144939580/a0389e26-c3d4-4366-a224-6dd8f28b6418)   

## Последовательность действий алгоритма:
* ***Ввод относительного или абсолютного пути к папке.***
* ***Проверка существования папки.***
* ***Папка существует:***
  >* Начинаем осуществлять поиск по папке и её подкаталогах.
  >* Находим все файлы с расширением *.txt.
  >* В каждом файлов находим слова, которые начинаются с буквы v или V.
  >* Записываем все эти слова в файл result.txt.

* ***Папка не существует:***
  > Информируем о том, что данной папки нет. Заершаем программу.

### Переменные 
* *input* - переменная, в которую сохраняется путь, введенный пользователем.
* *fas* - переменная, в которой хранится путь к папке.

## Методы и комманды
```
@echo off
chcp 1251
setlocal enabledelayedexpansion
set /p input=Введите путь к папке:
set "fas=%input%"
}
```
 * Запускает командной оболочки в режиме "отключить вывод команд на экран" с помощью команды ```@echo off```.
 * Устанавливка кодировки ```chcp 1251```.
 * Включение режима отложенного разрешения переменных ```setlocal enabledelayedexpansion ```.
 * Ввести путь к папке ```set /p input=Введите путь к папке:```.
 * Введенное значение сохраняется в переменной ```%input%```.
 * С помощью команды ```set "fas=%input%"``` значение переменной ```%input%``` присваивается переменной ```%fas%```.


    
```
IF not EXIST "%fas%" (
  echo Данной папки нет
  exit /b
)
```

* Цикл ```IF not EXIST "%fas%"``` проверяет, существует ли папка, указанная в переменной ```%fas%```.

    
```
(for /r "%fas%" %%F in (*.txt) do (
    for /f "tokens=*" %%A in ('findstr /i "\<[vV][a-zA-Z]*[^ ]*" "%%F"') do (
        for %%W in (%%A) do (
            set "word=%%W"
            set "word=!word:~0,1!"
            if /i "!word!"=="v" (
                set "found="
                echo %%W>>result.txt
            )
        )
    )
))
```
 * Обходит все файлы с расширением ```.txt``` в указанной папке и её подпапках с помощью цикла ```for /r "%fas%" %%F in (*.txt) do```.
 * В каждом файле ищет строки, содержащие слова, начинающиеся на ```"v"``` или ```"V"```, с помощью команды ```findstr /i "\<[vV][a-zA-Z]*[^ ]*" "%%F"```.
 * Цикл for %%W in (%%A) перебирает значения переменной %%A. Каждое значение сохраняется в переменную %%W.
 * Внутри цикла происходят следующие действия:
   >- Команда ```set "word=%%W"``` сохраняет текущее значение переменной ```%%W``` в переменную ```word```.
   >- Команда ```set "word=!word:~0,1!"``` сохраняет первый символ значения переменной ```word``` в переменную ```word```.
   >- Команда ```if /i "!word!"=="v"``` проверяет, является ли значение переменной word равным ```"v"``` (без учета регистра).
    > - Если условие выполняется, то команда ```set "found="``` очищает значение переменной found.
     >- Команда ```echo %%W>>result.txt``` записывает значение переменной ```%%W``` в файл ```"result.txt"```.

      
## Пример запуска
Запускаем командную строку ```(Win + R)```. Для открытия папки с .bat файлом вводим     
```cd путь_к_файлу```.  

   
![image](https://github.com/iis-32170x/RPIIS/assets/144939580/dfd0e4e2-5457-435f-b657-15a708374b8c)

   Чтобы запустить наш .bat файл используем    
   ```start название_файла.bat```.


   ![image](https://github.com/iis-32170x/RPIIS/assets/144939580/50e9d300-9a28-4dc0-bab2-0f51ed4be315)   

  Файл запущен.    


  ## Пример работы программы:

  Создадим папку с подпапками и текстовыми файлами. Запишем в них различные слова.  

  
  ![image](https://github.com/iis-32170x/RPIIS/assets/144939580/efac49cc-2e7b-4877-bee4-bd9a20773757)


  Во входной программе, соответствующей условию, задается путь.

  ![image](https://github.com/iis-32170x/RPIIS/assets/144939580/4468f9f0-cdee-43c4-ae66-4e793457a871)


  Запускаем. 


  ![image](https://github.com/iis-32170x/RPIIS/assets/144939580/1aa96c77-9fc8-42fc-b52a-9d4368a1548c)



  Программа успешно завершает работу. Появился новый файл *result.txt*, откроем его.

  ![image](https://github.com/iis-32170x/RPIIS/assets/144939580/c63b9804-de3b-41dd-b398-de5a45f71ee4)



  В результате программы было записано несколько слов, начинающихся с большой или маленькой V. На этом побробное описание работы *.bat* файла заканчивается. Приступим к рассмотрению файла *.sh*. 



## Описание алгоритма и переменных. Пример запуска и выполнения программы.([_.sh_]() файл)
> Для создания файла с расширением .sh не обязательно устанавливать ос Linux. Достаточно использовать ([_Gitbush_](https://git-scm.com/downloads).)

![image](https://github.com/iis-32170x/RPIIS/assets/144939580/fa204baf-8099-4ad8-b32c-0c0d4bdb3aa0)


## Последовательность действий алгоритма:
* ***Ввод относительного или абсолютного пути к папке.***
* ***Проверка существования папки.***
* ***Папка существует:***
  >* Начинаем осуществлять поиск по папке и её подкаталогах.
  >* Находим все файлы с расширением *.txt.
  >* В каждом файлов находим слова, которые начинаются с буквы v или V.
  >* Записываем все эти слова в файл result.txt.

* ***Папка не существует:***
  > Информируем о том, что данной папки нет. Заершаем программу.

### Переменные (она одна):
* *path_to* - хранит путь к директории, введенный пользователем.


### Команды:
- ```echo```: выводит текст на экран.
- ```read```: считывает ввод пользователя и сохраняет его в переменную.
- ```if```: условный оператор, выполняет определенные действия в зависимости от результата условия.
- ```[ -e $path_to ]```: проверяет, существует ли директория, указанная в переменной "path_to".
- ```find```: команда для поиска файлов и директорий в файловой системе.
- ```cat```: команда для вывода содержимого файла.
- ```grep```: команда для поиска текста с использованием регулярных выражений.
- ```sleep```: команда для задержки выполнения скрипта на определенное время.


## Ступенчатый процесс работы скрипта:
* Пользователь вводит путь к директории, который сохраняется в переменной ```path_to```.
  
* Проверка: существует ли директория, указанная в ```path_to```, с помощью опции ```-e``` (условного оператора).
  
* Если директория существует, переходим к следующему шагу. В противном случае отображается сообщение об ошибке о том, что директория не существует.
        
* Следующий шаг:      
* > Если директория существует, используем команду ```find``` для поиска всех файлов с расширением ```.txt``` в указанной директории и ее поддиректориях.
        
  > Команда ```find``` выполняет команду ```cat``` для каждого найденного файла с помощью опции ```-exec```, которая ***выводит содержимое*** каждого файла.
       
  > Вывод команды ```cat``` затем передается на вход команде ```grep```, которая ищет слова,    
   начинающиеся на ```"v"``` или ```"V"``` с использованием *регулярного выражения* ```\b[vV][a-zA-Z]*\b```.
     
  > Слова, соответствующие шаблону, затем перенаправляются в файл с именем ```"result.txt"``` с помощью оператора ```">"```.
  
  > Сценарий завершает свое выполнение.      



## Пример запуска
Для того, чтобы запустить данный файл, воспользуемся  ([_Gitbush_](https://git-scm.com/downloads).) Запускаем.

![image](https://github.com/iis-32170x/RPIIS/assets/144939580/d7f6cff9-cab7-4065-bb7c-c2e217c612bc)    




По аналогии с cmd строкой, открываем нужную нам директорию с помощью ```cd путь_к_файлу```.        



![image](https://github.com/iis-32170x/RPIIS/assets/144939580/e64002fd-e4a8-4f6b-8b02-27d8e372919c)


Чтобы запустить наш .sh файл используем    
   ```start название_файла.sh```.

   ![image](https://github.com/iis-32170x/RPIIS/assets/144939580/ca8fe4cb-ef6a-4438-8453-49313c1741c7)

   Файл успешно запущен.

## Пример работы программы:

  Создадим папку (testing) с подпапками и текстовыми файлами. Запишем в них различные слова.  

  
  ![image](https://github.com/iis-32170x/RPIIS/assets/144939580/16ac7dbc-6c04-4270-88f2-9c69a0dfd44c)


  Во входной программе, соответствующей условию, задается путь.

  ![image](https://github.com/iis-32170x/RPIIS/assets/144939580/08714467-97c9-4247-8114-088d85ca3520)


  Запускаем. 


  Программа успешно завершает работу. Появился новый файл *result.txt*, откроем его.

  
![image](https://github.com/iis-32170x/RPIIS/assets/144939580/372a743e-bbfd-40e8-96bf-bf5d26b13298)

В результате программы было записано несколько слов, начинающихся с большой или маленькой V. 


Проверим работу скрипта в том случае, когда входной путь к папке указан не верно или сама папка не существует:


![image](https://github.com/iis-32170x/RPIIS/assets/144939580/dcd1e502-c7bf-4ee3-9282-9c05389e631f)

Программа, а значит и я, успешно справились со своей задачей:)

# Итог работы с файлами

Во время Лабораторной работы №1 были применены навыки работы в командной строке **Windows** и **Linux**. А также созданы программы, выполняющие алгоритмы, соответствующие исходным условиям. Спасибо за внимание!!!  


![image](https://github.com/iis-32170x/RPIIS/assets/144939580/2731fcad-f39b-4d04-a695-7e67589cde5c)










  






