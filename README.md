# BSUIR laba1
Условие программы:
Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит число (как параметр пакетного файла).
В данном числе найти самую максимальную цифру, 
создать ровно столько файлов с расширением txt,
у каждого второго поменять расширение на doc и записать туда сегодняшнюю дату.


# ПРИМЕР РАБОТЫ ФАЙЛА 1.bat
на вход пакетному файлу приходит число.
просим ввести число не превышающее 100,если пользователь вводит данные неверно то мы завершаем программу.
далее мы задаем переменные ending и starting которым присваеваем значения начальной и конечной цифры числа.
в строках 10 11 и 12 мы переходим в нужную нам директорию и создаем там папку test в которой происходит дальнейшее выполнение программы

![изображение](https://github.com/devert007/2laba/assets/144791941/ef8c7b72-b894-47a0-a5b9-701278b8e9f4)

Строка 
![изображение](https://github.com/devert007/2laba/assets/144791941/a6597926-932b-4341-822d-ffa1d4310a9d)

сравнивает конечную цифру и начальную.

далее если конечная цифра больше начальной запускаем цикл создания файлов до цифры равной конечной так, как она наибольшая и пишет сегодняшнюю дату в каждом из них:
следующий цикл меняет расширение каждого второго файла на doc 
и третий цикл удаляет текст файлов txt и пишет туда текст "тут няма ничога"
![изображение](https://github.com/devert007/2laba/assets/144791941/42416687-e328-4013-aa4d-7d174fd94bf0)

если же у нас начальная цифра больше - по начальной цифре выполняя все те же 3 цикла что и ранее   :

![изображение](https://github.com/devert007/2laba/assets/144791941/bd7d3a59-6c03-4d5a-9955-0df5293ff577)


Что имеем на выходе?
при вводе числа 87 программа сначала сравнивает цифры числа между собой,находит наибольшее а далее проводит циклы создания файлов и изменения их расширения



![изображение](https://github.com/iis-32170x/RPIIS/assets/144791941/2a72eafd-75a9-4f3a-8ad8-14c846f86711)



