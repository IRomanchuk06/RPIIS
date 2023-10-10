# BSUIR_cmd-bash
Данная лабораторная работа была предназначена для ознакомления с командной строкой операционных систем Windows и Linux.
В рамках ЛР 1 необходимо создать исполняемый файл .bat и .sh в соответствии с заданным вариантом.
## Условие ЛР 1 (47 вариант)
![image](https://github.com/W1TAS/ere/assets/144806982/5868df23-0922-4d9e-8bdd-1b368907f6e1)
## Описание алгоритма, пример запуска и выполнения программы ([*.bat*](https://github.com/iis-32170x/RPIIS/blob/%D0%9E%D0%BB%D0%B8%D1%85%D0%B2%D0%B5%D1%80_%D0%92/47.bat) файл)
![image](https://github.com/iis-32170x/RPIIS/assets/144806982/9147f7f9-41b1-427e-a442-32b4a71d5e79)

 На вход программе приходит путь к папке.
#### Переменные:
- *path* - хранит путь к файлу
- *path2* - хранит путь к файлу, но изменяя все "\" на "."
- *answer* - хранит ответ пользователя на вовпрос создавать ли папку по заданному пути, если её нет
#### Методы:
- *EXIST* - проверяет наличие директории
- *mkdir* - создаёт директорию 
#### Последовательность действий:
 1. Ввод переменной *path*
 2. Проверка наличия введённой директории
 3. В случае наличия, создаёт в этой директории файл в названии которого дата, а внутри путь, в виде D.Program_Files.file (т.е. заменить символ ‘\’ на символ ‘.’)
 4. В случае если заданной директории нет, предлагается создать её
 5. Если ответ Y, создаётся директория
#### Пример запуска
   Запустим командную строку **cmd** любым удобным способом
   ![image](https://github.com/iis-32170x/RPIIS/assets/144806982/6250ca5b-e6fd-428a-8e08-1a3125cd71f0)


   После запуска нас встречает командная строка. Для выполнения нашего [*.bat*](https://github.com/MaratPereverzev/BSUIR_cmd-bash/blob/main/48.bat) файла, перейдём в соответствующую папку для запуска нашего файла с помощью консольной команды *cd* (change directory)

      cd путь_к_файлу

  ![image](https://github.com/iis-32170x/RPIIS/assets/144806982/e9618de5-c7c1-40c0-9a94-181f2d884a6d)



   Для выполнения любого .bat файла, необходимо прописать консольную команду 
   
     start название_файла.bat

  ![image](https://github.com/iis-32170x/RPIIS/assets/144806982/6c9be21d-b5df-4c6a-baef-e37c6d1fc52e)


   Ваш .bat файл успешно запущен!!!!
   #### Пример выполнения программы
   Введём путь к папке, если этот путь существует, то в папке создаётся текстовый документ, названный текущей датой, в котором записан путь к папке.  
![image](https://github.com/iis-32170x/RPIIS/assets/144806982/9dd6d90b-5e9c-4122-a6fa-31628a3bfb5f)
Если такого пути нет то его предлагают создать заданную директорию. При ответе Y создаётся заданная директория
![image](https://github.com/iis-32170x/RPIIS/assets/144806982/c03a4987-af36-4361-9123-8c90851d4f71)

#### На этом функционал .bat файла заканчивается. Теперь рассмотрим подробнее .sh файл


