
![](https://komarev.com/ghpvc/?username=Kukrynitza)
# [![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=50&pause=1000&color=48D13C&random=false&width=435&lines=Condition+2+lr+(option+7))](https://git.io/typing-svg)

##
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=50&pause=1000&color=48D13C&random=false&width=435&lines=Task)](https://git.io/typing-svg)

▀▄▀▄▀▄   🎀  7. Реализовать программу, формирующую без повторений всевозможные ориентированные
множества из элементов исходного неориентированного множества, количество
элементов в сформированных множествах должно быть равно исходному натуральному n.  🎀   ▄▀▄▀▄▀*

---

##
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=50&pause=1000&color=48D13C&random=false&width=435&lines=Target)](https://git.io/typing-svg)**

**(っ◔◡◔)っ ♥ Понять принципы комбинаторики и алгоритмов ♥

---

##
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=50&pause=1000&color=48D13C&random=false&width=435&lines=Key+Consept)](https://git.io/typing-svg)

 :=【﻿Декартово дерево　－　это структура данных, которая строится на основе упорядоченного массива и использует приоритетные очереди для хранения элементов.】
 
 :=【Множество - Неупорядоченная коллекция уникальных элементов.】
 
 :=【Ориентированное множество - Множество, в котором порядок следования элементов имеет значение.】
 
 :=【﻿Рекурсия - Метод определения функции, когда функция вызывает саму себя с более простыми аргументами.】
 
 :=【﻿Комбинации - Выборка элементов множества без учета порядка следования.】
 
 :=【﻿Перебор - Алгоритмический метод, заключающийся в последовательном просмотре всех возможных вариантов решения задачи.】

 :=【Неориентированное множество - математическое понятие, обозначающее коллекцию уникальных объектов, в которой порядок следования элементов не имеет значения.】

---

##
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=50&pause=1000&color=48D13C&random=false&width=435&lines=Test)](https://git.io/typing-svg)

**Массив:  [123, 'Gpt', 567, 'Gpt', 78.54]**

---
##
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=50&pause=1000&color=48D13C&random=false&width=435&lines=Code+Parsing)](https://git.io/typing-svg)

###
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=50&pause=1000&color=48D13C&random=false&width=435&lines=Passing+the+array)](https://git.io/typing-svg)

```python
if __name__ == "__main__":
    stroka_in = input("Введите множество ")
```
`stroka_in` - строка, которую задаем через клавиатуру а в последствии передаем

≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋

```python
        new_stroka_in = stroka_in.replace('{', '[')
    itogo_stroka_in = new_stroka_in.replace('}', ']')
    branch = ast.literal_eval(itogo_stroka_in)
```
1.Меняем строку так, чтобы вместо фигурных скобок были квадратный.

2.Записываем в массив строку

≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋

```python
    for i in branch:
        if branch.count(i) > 1:
            branch.remove(i)
    ban = []
    generete_branch(branch, ban)
```

1. Создаем цикл в котором передвигаемся по массиву и проверяем колличество повторений каждого элемента, если элемент встречается дважды и более, удаляем этот элемент ибо это противоречит определению неориентированного множества.
2. Создаем новый, пустой массив `ban[]`
3. Переходим в функцию в которой и будем генерировать массивы

---
###
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=50&pause=1000&color=48D13C&random=false&width=435&lines=Recursive+function)](https://git.io/typing-svg)

```python
def generete_branch(branch, ban):
  if (len(branch) == len(ban)):
        print(ban)
        return
```
Создаем условие для выхода из функции и записи полученного массива. Условием будет одинаковое колличество элементов в изначальном, неориентированном множестве.

≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋


```python
   for el in range(len(branch)):
        ban.append(branch[el])
        generete_branch(branch, ban)
        ban.pop()
```
Создаем цикл в котором будем заполнять массив `ban` элементам из массива `banch` по одному элементу. После рекурсивно переходим и заполняем массов элементами пока колличество элементов не станет равно колличеству элементов в иходнем массиве. После удаляем последний элемент. 

---

---

##
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=50&pause=1000&color=48D13C&random=false&width=435&lines=result)](https://git.io/typing-svg)


![image](https://github.com/iis-32170x/RPIIS/assets/144555463/885f7366-31cd-4701-8ff7-b4efb0d875b6)
![image](https://github.com/iis-32170x/RPIIS/assets/144555463/dbfc57a2-1618-4708-a12a-49f8fff409e6)
![image](https://github.com/iis-32170x/RPIIS/assets/144555463/4698c904-a692-4b3f-845f-bc6c8c07bf0c)
![image](https://github.com/iis-32170x/RPIIS/assets/144555463/a8bc9feb-c7b4-409b-8b5f-e727bedc8a6b)
![image](https://github.com/iis-32170x/RPIIS/assets/144555463/865fa915-a119-4088-b7e9-7b7c72de420c)
![image](https://github.com/iis-32170x/RPIIS/assets/144555463/24251ad9-719a-4f16-b4a4-41066e1e390e)
![image](https://github.com/iis-32170x/RPIIS/assets/144555463/ec19c63a-99dd-4b7f-be0c-e1920a7c9b39)

---
##
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=50&pause=1000&color=48D13C&random=false&width=435&lines=Conclusion)](https://git.io/typing-svg)


Задание по формированию всевозможных ориентированных множеств из элементов неориентированного множества без повторений полезно для развития навыков решения комбинаторных задач, улучшения навыков программирования, генерации всех возможных вариантов решения задачи и их анализа, а также может быть использовано в других областях, требующих генерации всех возможных вариантов.
   
---

## TO ᗷE ᑕOᑎTIᑎᑌEᗪ...
**≋А≋ ≋с≋е≋й≋ч≋а≋с≋ ≋а≋н≋е≋к≋д≋о≋т≋**

---
 <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=Italic&size=35&pause=1000&color=661E1E&center=&vCenter=&multiline=true&repeat=&random=&width=435&lines=%D0%97%D0%B0%D1%81%D0%BB%D1%83%D0%B6%D0%B5%D0%BD%D0%BD%D1%8B%D0%B9+%D0%B0%D0%BD%D0%B5%D0%BA%D0%B4%D0%BE%D1%82)" alt="Typing SVG" /></a>
 
<img src="https://readme-jokes.vercel.app/api" alt="Jokes Card" />
