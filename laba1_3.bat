@echo off
chcp 65001 > NUL
:: Просим пользователя ввести абсолютный путь к каталогу
set /p "target_directory=Введите абсолютный путь к каталогу: " 

:: Просим пользователя ввести символ для поиска в названиях файлов
set /p "search_symbol=Введите символ для поиска в названиях файлов: "

:: Просим пользователя ввести атрибуты прав доступа
set /p "file_attribute=Введите атрибуты прав доступа(например, +R): "

:: Переходим в указанный каталог
cd /d "%target_directory%"

:: Перебираем все файлы в текущем каталоге
for %%f in (*%search_symbol%*) do (
  echo Изменения прав доступа для файла: %%f
  :: Устанавливаем указанный атрибут прав доступа для каждого файла
  attrib %file_attribute% %%f
)

echo Все файлы с символом"%search_symbol%" в имени изменены

pause