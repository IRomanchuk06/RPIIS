![](https://komarev.com/ghpvc/?username=Kukrynitza)
## [![Typing SVG](https://readme-typing-svg.herokuapp.com?font=italic&size=24&pause=1000&color=FF10D1&center=%D0%9B%D0%9E%D0%96%D0%AC&vCenter=%D0%9B%D0%9E%D0%96%D0%AC&multiline=true&repeat=%D0%B8%D1%81%D1%82%D0%B8%D0%BD%D0%BD%D1%8B%D0%B9&random=%D0%9B%D0%9E%D0%96%D0%AC&width=435&lines=%D0%A3%D0%A1%D0%9B%D0%9E%D0%92%D0%98%D0%95+%D0%9B%D0%A01(%D0%92%D0%B0%D1%80%D0%B8%D0%B0%D0%BD%D1%82+17))](https://git.io/typing-svg)
*Создать файл sh и bat, который выполняет следующее: 
На вход пакетному файлу приходит относительный путь к папке (как параметр пакетного файла). Если такой папки нет, то писать “Данной папки нет” и завершить выполнение программы. Если такая папка есть, то найти в ней и в ее подкаталогах файлы, в названии которых есть подстрока “temp”. Вывести первые пять строк найденных файлов в файл result.txt.*
---
## <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=italic&pause=1000&color=641C6F&center=%D0%9B%D0%9E%D0%96%D0%AC&vCenter=%D0%9B%D0%9E%D0%96%D0%AC&multiline=true&repeat=%D0%B8%D1%81%D1%82%D0%B8%D0%BD%D0%BD%D1%8B%D0%B9&random=%D0%9B%D0%9E%D0%96%D0%AC&width=435&lines=%D0%A0%D0%95%D0%90%D0%9B%D0%98%D0%97%D0%90%D0%A6%D0%98%D0%AF+SH-%D0%A4%D0%90%D0%99%D0%9B%D0%90" alt="Typing SVG" /></a>
Код	&#128526;
```sh
#!/bin/bash
 folder_path="$1"

if [ ! -d "$folder_path" ]; then  echo "Данной папки нет" cd
  exit 1 
fi
echo $folder_path
find "$folder_path" -type f -name "*temp*" -exec head -n 5 {} \; > /home/ilja/.myskript/result
```
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=italic&size=24&pause=1000&color=733789&center=%D0%9B%D0%9E%D0%96%D0%AC&vCenter=%D0%9B%D0%9E%D0%96%D0%AC&multiline=true&repeat=%D0%B8%D1%81%D1%82%D0%B8%D0%BD%D0%BD%D1%8B%D0%B9&random=%D0%9B%D0%9E%D0%96%D0%AC&width=435&lines=%D0%9F%D0%B5%D1%80%D0%B5%D0%BC%D0%B5%D0%BD%D0%BD%D1%8B%D0%B5%3A)](https://git.io/typing-svg)

folder_pass - путь к папке, в которой будет происходить поиск всех текстовых файлов в названии которых есть подстрока “temp”

Получается одна переменная 	&#129325;<br>
<br>

**<a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=italic&size=24&pause=1000&color=733789&center=%D0%9B%D0%9E%D0%96%D0%AC&vCenter=%D0%9B%D0%9E%D0%96%D0%AC&multiline=true&repeat=%D0%B8%D1%81%D1%82%D0%B8%D0%BD%D0%BD%D1%8B%D0%B9&random=%D0%9B%D0%9E%D0%96%D0%AC&width=435&lines=%D0%A0%D0%B0%D0%B1%D0%BE%D1%82%D0%B0+%D1%81+sh-%D1%84%D0%B0%D0%B9%D0%BB%D0%BE%D0%BC%3A" alt="Typing SVG" /></a>**

Запускаем sh-файл и проверяем, есть ли проверка на наличие папки &#128564;
 
![image](https://github.com/iis-32170x/RPIIS/assets/144555463/972d9653-b743-48eb-8e52-af0f27f24f39)

Видим что записалось в result 	&#128527;

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/485f0748-5013-470f-a2ef-d7368a73fa5f)

Что мы имели изначально(чтобы можно было бы убедиться что всё работает) &#128554;

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/fa9f386c-7a08-462f-a926-e999931139d2)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/869d2a80-855c-4c7b-9a16-430c30de1afe)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/55c9a87a-1249-4405-aeaa-535483c62d59)


![image](https://github.com/iis-32170x/RPIIS/assets/144555463/b99841ce-905b-4f9c-8f8f-74b70349e9ab)


![image](https://github.com/iis-32170x/RPIIS/assets/144555463/2d44f3e8-6916-4f8e-bfdd-644da8189616)
![image](https://github.com/iis-32170x/RPIIS/assets/144555463/39be641f-032c-4cb0-957d-367ddff94777)
---
## <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=italic&pause=1000&color=65164B&center=%D0%9B%D0%9E%D0%96%D0%AC&vCenter=%D0%9B%D0%9E%D0%96%D0%AC&multiline=true&repeat=%D0%B8%D1%81%D1%82%D0%B8%D0%BD%D0%BD%D1%8B%D0%B9&random=%D0%9B%D0%9E%D0%96%D0%AC&width=435&lines=%D0%A0%D0%95%D0%90%D0%9B%D0%98%D0%97%D0%90%D0%A6%D0%98%D0%AF+BAT-%D0%A4%D0%90%D0%99%D0%9B%D0%90" alt="Typing SVG" /></a>

Код	&#128525;
```bat
@echo off
setlocal EnableDelayedExpansion
chcp 65001
if "%1"=="" (echo Параметр не задан)
echo. >D:/labaPi1/result.txt
if not exist D:/labaPi1/%1 (echo Данной папки нет)
echo. >D:/labaPi1/result.txt
for /R D:/labaPi1/%1 %%t in (*temp*) do (
set fileName= %%t
set /A counter=0
for /F %%s in (!fileName!) do (
if !counter! lss 5 (
echo %%s >>D:/labaPi1/result.txt
set /A counter+=1
)
)
echo. >>D:/labaPi1/result.txt
)
endlocal
```
## <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=italic&size=24&pause=1000&color=65164B&center=%D0%9B%D0%9E%D0%96%D0%AC&vCenter=%D0%9B%D0%9E%D0%96%D0%AC&multiline=true&repeat=%D0%B8%D1%81%D1%82%D0%B8%D0%BD%D0%BD%D1%8B%D0%B9&random=%D0%9B%D0%9E%D0%96%D0%AC&width=435&lines=%D0%9F%D0%B5%D1%80%D0%B5%D0%BC%D0%B5%D0%BD%D0%BD%D1%8B%D0%B5%3A" alt="Typing SVG" /></a>

fileName - переменная, в которой хранится расположение обрабатываеммого файла;

counter - переменная-счетчик, которая отсчитывает колличество строк;

<a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=italic&size=24&pause=1000&color=65164B&center=%D0%9B%D0%9E%D0%96%D0%AC&vCenter=%D0%9B%D0%9E%D0%96%D0%AC&multiline=true&repeat=%D0%B8%D1%81%D1%82%D0%B8%D0%BD%D0%BD%D1%8B%D0%B9&random=%D0%9B%D0%9E%D0%96%D0%AC&width=435&lines=%D0%A0%D0%B0%D0%B1%D0%BE%D1%82%D0%B0+%D1%81+bat-%D1%84%D0%B0%D0%B9%D0%BB%D0%BE%D0%BC%3A" alt="Typing SVG" /></a>

Запускаем bat-файл и проверяем, есть ли проверка на наличие папки &#128529;

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/82d66767-8856-42c7-a101-4b691036e92b)

Видим что записалось в result 	&#128527;

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/47c99b0b-4ca2-45c6-a3b2-3ae6542f3504)

Что мы имели изначально(чтобы можно было бы убедиться что всё работает) &#128554;

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/49f4d770-0105-453e-a2b7-e2204b2a4364)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/8b29d31f-1c5f-44dd-8d23-6e38076a947a)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/fca92d79-e1fd-4e9a-a0eb-9e70ca644336)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/03c86686-a3c1-426d-9bfa-b2bdcc55bc94)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/12a7e76d-56ae-438a-8073-f4cf7051faff)

![image](https://github.com/iis-32170x/RPIIS/assets/144555463/45a6e5c4-71ab-49a5-a4ea-b7427325fd5b)
---

# <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=Cambria&size=24&pause=1000&color=06615A&center=&vCenter=&multiline=true&repeat=&random=&width=435&lines=SORT" alt="Typing SVG" /></a>

**Описание:	&#128105;&#8205;&#129456;**

Считывает входные данные, сортирует данные и записывает результаты на экран, в файл или на другое устройство.

**Синтаксис:	&#127940;&#8205;&#9794;&#65039;**

```sort [/r] [/+<N>] [/m <kilobytes>] [/l <locale>] [/rec <characters>] [[<drive1>:][<path1>]<filename1>] [/t [<drive2>:][<path2>]] [/o [<drive3>:][<path3>]<filename3>] ```

**Параметры:	&#129299;**

/r	Изменяет порядок сортировки (т. е. сортирует от Z до A и от 9 до 0).

/+ ```<N>```	Указывает номер позиции символа, в котором сортировка начнется каждое сравнение. N может быть любым допустимым целым числом.

/М ```<kilobytes>```	Указывает объем основной памяти, используемой для сортировки в килобайтах (КБ).

Языковой стандарт /l <>	Переопределяет порядок сортировки символов, определенных языковым стандартом по умолчанию системы (т. е. языком и страной или регионом, выбранным во время установки).

/Rec ```<characters>```	Указывает максимальное количество символов в записи или строке входного файла (значение по умолчанию равно 4096, а максимальное — 65 535).

```[<drive1>:][<path1>]<filename1>```	Указывает файл для сортировки. Если имя файла не указано, то стандартные входные данные отсортированы. Указание входного файла быстрее перенаправления того же файла, что и стандартные входные данные.

/T ```[<drive2>:][<path2>]```	Указывает путь к каталогу для хранения рабочего хранилища команды сортировки , если данные не помещаются в основную память. По умолчанию используется временный каталог системы.

/O ```[<drive3>:][<path3>]<filename3>```	Указывает файл, в котором должны храниться отсортированные входные данные. Если данные не указаны, данные записываются в стандартные выходные данные. Указание выходного файла выполняется быстрее, чем перенаправление стандартных выходных данных в тот же файл.

/unique	Возвращает только уникальные результаты.

/?	Отображение справки в командной строке.

---

# <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=Cambria&size=24&pause=1000&color=066142&center=&vCenter=&multiline=true&repeat=&random=&width=435&lines=TYPE" alt="Typing SVG" /></a>

**Описание:	&#128105;&#8205;&#129456;**

Используется команда для просмотра текстового файла, не изменяя его.

**Синтаксис:	&#127940;&#8205;&#9794;&#65039;**

```type [<drive>:][<path>]<filename> ```

**Параметры:	&#129299;**

```[<drive>:][<path>]<filename>```	Указывает расположение и имя файла или файлов, которые требуется просмотреть. <filename> Если содержит пробелы, его необходимо заключить в кавычки (например, "Имя файла, содержащее пробелы.txt"). Можно также добавить несколько имен файлов, добавив пробелы между ними.

/?	Отображение справки в командной строке.

---

# <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=Cambria&size=24&pause=1000&color=075420&center=&vCenter=&multiline=true&repeat=&random=&width=435&lines=TASKLIST" alt="Typing SVG" /></a>

**Описание:	&#128105;&#8205;&#129456;**

Отображает список запущенных в настоящее время процессов на локальном компьютере или на удаленном компьютере.

**Синтаксис:	&#127940;&#8205;&#9794;&#65039;**

```tasklist [/s <computer> [/u [<domain>\]<username> [/p <password>]]] [{/m <module> | /svc | /v}] [/fo {table | list | csv}] [/nh] [/fi <filter> [/fi <filter> [ ... ]]] ```

**Параметры:	&#129299;**

/s ```<computer>```	Указывает имя или IP-адрес удаленного компьютера (не используйте обратные очки). По умолчанию используется локальный компьютер.

/U ```<domain>\<username>```	Выполняет команду с разрешениями учетной записи пользователя, указанного <username> или указанным пользователем <domain>\<username>. Параметр /u можно указать только в том случае, если также указан /s . Значение по умолчанию — это разрешения пользователя, вошедшего в систему на компьютере, который выдает команду.

/P ```<password>```	Указывает пароль учетной записи пользователя, указанной в параметре /u .

/М ```<module>```	Выводит список всех задач с модулями DLL, загруженными в соответствии с заданным именем шаблона. Если имя модуля не указано, этот параметр отображает все модули, загруженные каждой задачей.

svc	Выводит все сведения о службе для каждого процесса без усечения. Допустимо, если для параметра /fo задано значение таблицы.

/v	Отображает подробные сведения о задаче в выходных данных. Для полного подробного вывода без усечения используйте /v и /svc вместе.

/Fo ```{table | list | csv}``` Указывает формат, используемый для выходных данных. Допустимые значения: таблица, список и csv. Формат выходных данных по умолчанию — таблица.

/Nh	Подавляет заголовки столбцов в выходных данных. Допустимо, если для параметра /fo задано значение table или csv.

/Fi ```<filter>```	Указывает типы процессов, которые необходимо включить или исключить из запроса. Можно использовать несколько фильтров или использовать дикий символ карта (\) для указания всех задач или имен изображений. Допустимые фильтры перечислены в разделе "Имена фильтров", "Операторы" и "Значения " этой статьи.

/?

---

# <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=Cambria&size=24&pause=1000&color=074D0F&center=&vCenter=&multiline=true&repeat=&random=&width=435&lines=PING" alt="Typing SVG" /></a>

**Описание:	&#128105;&#8205;&#129456;**

Проверяет подключение на уровне IP к другому компьютеру TCP/IP, отправляя сообщения об эхо-запросе протокола ICMP. Отображается получение соответствующих сообщений эхо-ответа, а также время кругового пути. ping — это основная команда TCP/IP, используемая для устранения неполадок с подключением, доступностью и разрешением имен. Используется без параметров, эта команда отображает содержимое справки.

Эту команду можно также использовать для проверки имени компьютера и IP-адреса компьютера. Если проверка подключения к IP-адресу выполнена успешно, но проверка pinging имя компьютера не является, у вас может возникнуть проблема с разрешением имен. В этом случае убедитесь, что указанное имя компьютера можно разрешить через файл локальных узлов, используя запросы системы доменных имен (DNS) или методы разрешения имен NetBIOS.

**Синтаксис:	&#127940;&#8205;&#9794;&#65039;**

```ping [/t] [/a] [/n <count>] [/l <size>] [/f] [/I <TTL>] [/v <TOS>] [/r <count>] [/s <count>] [{/j <hostlist> | /k <hostlist>}] [/w <timeout>] [/R] [/S <Srcaddr>] [/4] [/6] <targetname> ```

**Параметры:	&#129299;**

/T	Указывает, что связь продолжает отправлять сообщения эхо-запроса в место назначения до прерывания. Чтобы прервать и отобразить статистику, нажмите клавиши CTRL+ВВОД. Чтобы прервать и выйти из этой команды, нажмите клавиши CTRL+C.

/a	Указывает разрешение обратного имени на целевом IP-адресе. Если эта операция выполнена успешно, отображается соответствующее имя узла.

/N ```<count>```	Указывает количество отправленных сообщений эхо-запроса. Значение по умолчанию — 4.

/L ```<size>```	Указывает длину в байтах поля данных в сообщениях эхо-запроса. Значение по умолчанию — 32. Максимальный размер — 65 500.


/f	Указывает, что сообщения эхо-запроса отправляются с флагом "Не фрагментировать " в заголовке IP-адреса с значением 1 (доступно только для IPv4). Сообщение эхо-запроса не может быть фрагментировано маршрутизаторами в пути к месту назначения. Этот параметр полезен для устранения неполадок с максимальной единицей передачи (PMTU).

/i ```<TTL>```	Указывает значение поля Time To Live (TTL) в заголовке IP-адреса для отправленных сообщений эхо-запроса. Значение по умолчанию — значение TTL по умолчанию для узла. Максимальное значение TTL — 255.

/V ```<TOS>```	Указывает значение поля типа службы (TOS) в заголовке IP-адреса для отправленных сообщений эхо-запроса (доступно только для IPv4). По умолчанию установлено значение 0. TOS указывается как десятичное значение от 0 до 255.

/R ```<count>```	Указывает параметр "Маршрут записи" в заголовке IP-адреса для записи пути, принятого сообщением запроса эхо и соответствующим сообщением ответа на эхо (доступно только в IPv4). Каждый прыжк в пути использует запись в параметре "Маршрут записи". Если это возможно, укажите число , равное или больше количества прыжков между источником и назначением. Число должно быть не менее 1 и не более 9.

/s ```<count>```	Указывает, что параметр метки времени Интернета в заголовке IP-адреса используется для записи времени прибытия сообщения эхо-запроса и соответствующего сообщения эхо-ответа для каждого прыжка. Число должно быть не менее 1 и не более 4. Этот параметр необходим для адресов назначения канала.

/J ```<hostlist>```	Указывает сообщения эхо-запроса, используя параметр "Свободный исходный маршрут " в заголовке IP с набором промежуточных назначений, указанных в списке узлов (доступно только для IPv4). При слабой маршрутизации источника последовательные промежуточные назначения могут быть разделены одним или несколькими маршрутизаторами. Максимальное число адресов или имен в списке узлов — 9. Список узлов представляет собой ряд IP-адресов (в точечной десятичной нотации), разделенных пробелами.

/K ```<hostlist>```	Указывает сообщения эхо-запроса, используя параметр "Строгий исходный маршрут " в заголовке IP с набором промежуточных назначений, указанных в списке узлов (доступно только для IPv4). При строгой маршрутизации источника следующий промежуточный целевой объект должен быть напрямую доступен (он должен быть соседом в интерфейсе маршрутизатора). Максимальное число адресов или имен в списке узлов — 9. Список узлов представляет собой ряд IP-адресов (в точечной десятичной нотации), разделенных пробелами.

/W ```<timeout>```	Указывает время ожидания сообщения эхо-ответа в миллисекундах, соответствующего заданному сообщению эхо-запроса. Если сообщение эхо-ответа не получено в течение времени ожидания, отображается сообщение об ошибке "Время ожидания запроса". Время ожидания по умолчанию — 4000 (4 секунды).

/R	Указывает трассировку пути кругового пути (доступно только для IPv6).

/S ```<Srcaddr>```	Указывает исходный адрес, используемый (доступен только в IPv6).

/4	Указывает протокол IPv4, используемый для проверки связи. Этот параметр не требуется для идентификации целевого узла с IPv4-адресом. Это необходимо только для идентификации целевого узла по имени.

/6	Указывает протокол IPv6, используемый для проверки связи. Этот параметр не требуется для идентификации целевого узла с IPv6-адресом. Это необходимо только для идентификации целевого узла по имени.
```<targetname>```	Указывает имя узла или IP-адрес назначения.

/?	Отображение справки в командной строке.

---

# <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=Cambria&size=24&pause=1000&color=114D07&center=&vCenter=&multiline=true&repeat=&random=&width=435&lines=TREE" alt="Typing SVG" /></a>

**Описание:	&#128105;&#8205;&#129456;**

Отображает структуру каталогов пути или диска в графическом режиме диска. Структура, отображаемая этой командой, зависит от параметров, указанных в командной строке. Если вы не указываете диск или путь, эта команда отображает структуру дерева, начиная с текущего каталога текущего диска.

**Синтаксис:	&#127940;&#8205;&#9794;&#65039;**

```tree [<drive>:][<path>] [/f] [/a] ```

**Параметры:	&#129299;**

```<drive>:```	Указывает диск, содержащий диск, для которого требуется отобразить структуру каталогов.

```<path>```	Указывает каталог, для которого требуется отобразить структуру каталогов.

/f	Отображает имена файлов в каждом каталоге.

/a	Указывает использовать текстовые символы вместо графических символов для отображения строк, которые связывают подкаталогы.

/?	Отображение справки в командной строке.

---

# <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=cambria&size=35&pause=1000&color=072903&center=&vCenter=&multiline=true&repeat=&random=&width=435&lines=CHCP" alt="Typing SVG" /></a>

**Описание:	&#128105;&#8205;&#129456;**

Изменяет страницу кода активной консоли. При использовании без параметров chcp отображает номер активной кодовой страницы консоли.

**Синтаксис:	&#127940;&#8205;&#9794;&#65039;**

```chcp [<nnn>] ```

**Параметры:	&#129299;**

```<nnn>```	Указывает кодовую страницу.
/?	Отображение справки в командной строке.

---
 # <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=Cambria&size=24&pause=1000&color=112E00&center=&vCenter=&multiline=true&repeat=&random=&width=435&lines=%D0%A1%D0%9F%D0%9E%D0%A1%D0%9E%D0%91%D0%AB+%D0%92%D0%AB%D0%99%D0%A2%D0%98+%D0%98%D0%97+%D0%90%D0%9A%D0%A2%D0%98%D0%92%D0%9D%D0%9E%D0%93%D0%9E+%D0%9F%D0%A0%D0%9E%D0%A6%D0%95%D0%A1%D0%A1%D0%90" alt="Typing SVG" /></a>

 1.Комбинация клавиш Ctrl+C.
 
 2.Команда "exit".
 
 3. Команда "taskkill".
    
 ---

 <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=Italic&size=35&pause=1000&color=F529F1&center=&vCenter=&multiline=true&repeat=&random=&width=435&lines=%D0%A1%D0%9F%D0%90%D0%A1%D0%98%D0%91%D0%9E+%D0%97%D0%90+%D0%92%D0%9D%D0%98%D0%9C%D0%90%D0%9D%D0%98%D0%95" alt="Typing SVG" /></a>

 <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=Italic&size=35&pause=1000&color=661E1E&center=&vCenter=&multiline=true&repeat=&random=&width=435&lines=%D0%97%D0%B0%D1%81%D0%BB%D1%83%D0%B6%D0%B5%D0%BD%D0%BD%D1%8B%D0%B9+%D0%B0%D0%BD%D0%B5%D0%BA%D0%B4%D0%BE%D1%82)" alt="Typing SVG" /></a>
<img src="https://readme-jokes.vercel.app/api" alt="Jokes Card" />
