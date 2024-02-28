
![](https://komarev.com/ghpvc/?username=Kukrynitza)
# [![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=55&pause=1000&color=85127B&random=false&width=435&lines=Condition+lr+1+(option+8))](https://git.io/typing-svg)

##
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=55&pause=1000&color=85127B&random=false&width=435&lines=Task)](https://git.io/typing-svg)

▀▄▀▄▀▄   🎀  𝟪. Декартово дерево. Вставка. Поиск. Удаление. Построение дерева из
массива значений. Объединение двух деревьев. Пересечение двух
деревьев.  🎀   ▄▀▄▀▄▀*

---

##
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=55&pause=1000&color=85127B&random=false&width=435&lines=Target)](https://git.io/typing-svg)**

**(っ◔◡◔)っ ♥ Изучить декартово дерево. Выявить его положительные стороны. ♥
Запускаем sh-файл и проверяем, есть ли проверка на наличие папки &#128564;**

---

##
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=55&pause=1000&color=85127B&random=false&width=435&lines=Key+Concepts)](https://git.io/typing-svg)

 :=【﻿Декартово дерево　－　это структура данных, которая строится на основе упорядоченного массива и использует приоритетные очереди для хранения элементов.】
 
 :=【﻿Узел　－　это　структура　данных，　которая　хранит　значение　элемента，　приоритет　и　указатели　на　левое　и　правое　поддерево．】
 
 :=【﻿Ключ　－　это　значение　элемента，　которое　используется　для　упорядочивания　элементов　в　дереве．】
 
 :=【﻿Приоритет　－　это　значение，　которое　используется　для　определения　относительного　порядка　элементов　в　дереве．　Приоритет　может　быть　любым　числом，　и　элемент　с　меньшим　приоритетом　будет　находиться　выше　в　дереве，　чем　элемент　с　большим　приоритетом．】
 
 :=【﻿Корень　－　это　верхний　узел　дерева，　который　не　имеет　родителя．】
 
 :=【﻿Левое поддерево - это поддерево, которое находится слева от узла и содержит элементы, которые меньше ключа узла.】
 
 :=【﻿Правое поддерево - это поддерево, которое находится справа от узла и содержит элементы, которые больше ключа узла.】
 
 :=【﻿Родитель - это узел, который содержит указатель на текущий узел.】
 
 :=【﻿Потомок - это узел, который находится ниже текущего узла в дереве.】
 
 :=【﻿Высота дерева - это максимальное количество узлов в пути от корня до листа.】
 
 :=【﻿Объединение деревьев - это операция, которая объединяет два дерева в одно дерево. 】
 
 :=【﻿Разбиение дерева - это операция, которая делит одно дерево на два или более поддеревьев.】
 
 :=【﻿Лист - это конечная вершина дерева, которая не содержит дочерних узлов.】
 
---

##
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=55&pause=1000&color=85127B&random=false&width=435&lines=Test+tree)](https://git.io/typing-svg)

**Ключи: 𝟙 - 𝟚𝟞, 𝟚 - 𝟛𝟙, 𝟛 - 𝟚𝟜, 𝟜 - 𝟚𝟝, 𝟝 - 𝟚𝟟, 𝟞 - 𝟚𝟛, 𝟟 - 𝟝𝟞**

**Значения:  𝟙 "𝔾𝕠𝕘𝕖𝕟", 𝟚 "𝕄𝕠𝕠𝕣𝕖", 𝟛 "𝕆𝕃𝔼𝔾", 𝟜 "𝔼𝕕𝕨𝕒𝕣𝕕𝕤", 𝟝 "𝕊𝕦", 𝟞 "𝕄𝕒𝕣𝕚𝕒", 𝟟 "𝕍𝕖𝕣𝕠𝕟𝕚𝕜𝕒"**

---
##
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=55&pause=1000&color=85127B&random=false&width=435&lines=Code+parsing)](https://git.io/typing-svg)
```cpp
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
```

(¯`·.¸¸.·´¯`·.¸¸.->   🎀  **Используемые библиотеки**  🎀   >-.¸¸.·`¯´·.¸¸.·`¯(
###
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=55&pause=1000&color=85127B&random=false&width=435&lines=Class+Diramida)](https://git.io/typing-svg)
####
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=55&pause=1000&color=85127B&random=false&width=435&lines=private+part)](https://git.io/typing-svg)
```cpp
private:
    struct Node {
        int key, priority;
        string name;
        Node* l = nullptr;
        Node* r = nullptr;

        Node(string name, int key = 0) : key(key), priority(rand()) {}
    } *root = nullptr;
```
`struct Node` - поле представляющее собой узел/лист дерева, где:

`int key` - ключ;

`int priority` - приоритет;

`string name` - значение;

`Node* l = nullptr`, `Node* r = nullptr` - Левый и правый потомки;

`Node(string name, int key = 0) : key(key), priority(rand())` - по умолчанию ключ принимает значение 0, приоритет - случайное число

---
####
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=55&pause=1000&color=85127B&random=false&width=435&lines=public+part)](https://git.io/typing-svg) 

🌷☠  **разбиение**  🐧♘
```cpp
    void Split(Node* n, int key, Node*& a, Node*& b) {
    if (!n) {
        a = b = nullptr;
        return;
    }

    if (n->key < key) {
        Split(n->r, key, n->r, b);
        a = n;
    }
    else {
        Split(n->l, key, a, n->l);
        b = n;
    }
}
```
Передаем корень дерева, которое будем разбивать, ключ, по которому будем разбивать, левое и правое деревья, на которые разобъеться дерево.
```cpp
    void Split(Node* n, int key, Node*& a, Node*& b) {
```
Если дойдем по конца начального дерева, сработает базовый случай
```cpp
    if (!n) {
        a = b = nullptr;
        return;
    }
```
Суть метода разбивает дерево на дерево чей ключ меньше заданного и дерево чей ключ равен или больше заданного.

Принцип работы: Если корень меньше ключа, переходим в левую, если нет, переходим в правую, когда дойдем до конца начинаем записывать в нужное дерево узлы/листы.

≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋

**о♥б♥ъ♥е♥д♥и♥н♥е♥н♥и♥е**
```cpp
   Node* Merge(Node* a, Node* b) {
    if (!a || !b)
        return a ? a : b;

    if (a->priority > b->priority) {
        a->r = Merge(a->r, b);
        return a;
    }
    else {
        b->l = Merge(a, b->l);
        return b;
    }
}
```
Суть метода создать дерево из двух деревьев, где все ключи левого дерева меньше всех ключей правого дерева.

Принцип работы: Если приоритет одного из деревьев больше другого, то его корень и его правая или левая часть(зависит от того приоритет какого дерева выше) записываеться первым(в зависимости от дерева либо в лево либо в право)

≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋

🐷  🎀  добавление  🎀  🐷

```cpp
   void Insert(string name, int key) {
    Node* Ferst, *Second;
    Split(root, key, Ferst, Second);
    root = Merge(Ferst, new Node(name, key));
    root = Merge(root, Second);
}
```
Суть метода добавить новый узел/лист в дерево.

Принцип работы: 1.Разбиваем дерево, в которое будем записывать новый узел, по ключу;

2.Объединяем левую часть с новым узлом;

3.Объединяем новое дерево с правой частью;

≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋

🐊🐨  удаление  🍓♡

```cpp
   Node* Erase(int key) {
    Node* Ferst, * Second, * Third;
    Split(root, key, Ferst, Third);
    Split(Third, key + 1, Second, Third);
    root = nullptr;
    root = Merge(Ferst, Third);
    return root;
}
```
Суть метода удалить узел/лист из дерева.

Принцип работы: 1.Разбиваем дерево, в которое будем записывать новый узел, по ключу;

2.Разбиваем правую часть по ключу+1, получаться средняя часть и правая, где средняя и будет искомым узлом;

3.Объединяем левую часть с правой;

4. Возвращаем значение корня;

≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋-≋

🐼ൠ  поиск  🐜💣

```cpp
   void Find(int key) {
    Node* Ferst, * Second, * Third;
    Split(root, key + 1, Ferst, Second);
    Split(Ferst, key, Ferst, Third);
    if (!Third)
        cout << "Такого узла/листа нет" << endl;
    else cout << "Такого узел/лист есть и вот его приоритет " << Third->priority << endl;
    root = Merge(Ferst, Third);
    root = Merge(root, Third);
}
}
```
Суть метода найти узел/лист из дерева.

Принцип работы: 1.Разбиваем дерево, в которое будем записывать новый узел, по ключу + 1;

2.Разбиваем левую часть по ключу, получаеться левая часть и средняя, где средняя и будет искомым узлом;

3.Объединяем левую часть с средней;

4.Объединяем получившееся дерево с правой частью;

---

---

##
[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=55&pause=1000&color=85127B&random=false&width=435&lines=result)](https://git.io/typing-svg)
```cpp
int main() {
    system("chcp 1251");
    vector<string> name{ "Gogen", "Moore", "OLEG", "Edwards", "Su", "Maria", "Veronika" };
    vector<int> nums{ 26,31,24,25,27,23,56 };
    Diramida d;
    for (int i = 0; i < name.size(); i++)
        d.Insert(name[i], nums[i]);
     auto root = d.Root();
     d.printTree(root, 0);
     cout << endl;
     root = d.Erase(23);
     d.printTree(root, 0);
     d.Find(56);
     d.Find(57);
    return 0;
}
```
![image](https://github.com/iis-32170x/RPIIS/assets/144555463/507ef554-a243-4ac2-aabb-005fc9eac4e1)

---

[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Micro+5&size=55&pause=1000&color=85127B&random=false&width=435&lines=conclusion)](https://git.io/typing-svg)

Декартово дерево имеет следующие положительные стороны:
1. Быстрое и простое создание дерева;
2. Целостность дерева;
3. Возможность разделить и объединить дерево;
4. Простота удаления элемента;
   
---

## TO ᗷE ᑕOᑎTIᑎᑌEᗪ...
**≋А≋ ≋с≋е≋й≋ч≋а≋с≋ ≋а≋н≋е≋к≋д≋о≋т≋**

---
 <a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.herokuapp.com?font=Italic&size=35&pause=1000&color=661E1E&center=&vCenter=&multiline=true&repeat=&random=&width=435&lines=%D0%97%D0%B0%D1%81%D0%BB%D1%83%D0%B6%D0%B5%D0%BD%D0%BD%D1%8B%D0%B9+%D0%B0%D0%BD%D0%B5%D0%BA%D0%B4%D0%BE%D1%82)" alt="Typing SVG" /></a>
 
<img src="https://readme-jokes.vercel.app/api" alt="Jokes Card" />
