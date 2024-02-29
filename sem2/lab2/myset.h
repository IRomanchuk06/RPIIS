#ifndef SEM2_LAB1_PIVO_MYSET_H
#define SEM2_LAB1_PIVO_MYSET_H

#include <iostream>
#include <cmath>


/*
 * для хранения элементов множества, в данной реализации этого типа данных, используется отсортированный массив
 * сортировка происходит автоматически, во время добавление элемента во множество
 * для проверки наличия элемента во множестве используется метод бинарного поиска
 *
 *
 *
 * методы для данной реализации множества:
 *
 * add(<value>)
 * добавление элемента <value> во множество (если элемент присутствует ничего не делает)
 *
 *
 * del(<value>)
 * удаление элемента <value> из множества (если элемент отсутствует ничего не делает)
 *
 *
 * clear()
 * удаление всех элементов множества
 *
 *
 * getSize()
 * возвращает мощность / размер / кол-во элементов множества
 *
 *
 * contain(<value>)
 * проверка наличия элемента <value> во множестве
 * возвращает true если элемент содержится и false если не содержится
 *
 *
 * index(<value>)
 * проверяет наличие элемента <value> во множестве и возвращает его индекс,
 * если элемент отсутствует возвращает -1
 *
 *
 *
 * операторы для данной реализации множества:
 *
 * [<index>]
 * возвращает элемент с заданным индексом (доступ к элементу по индексу)
 * допускается значение <index> в диапазоне от 0 до size - 1 включая
 * при попытке получить значение вне заданного диапазона кидает ошибку std::out_of_range
 * и указывает размер массива, а так же индекс по которому пытались получить элемент
 *
 *
 * при сравнении двух множеств сразу сравниваются их мощности, а потом
 * попарно элементы каждого из множеств
 * на основе этих сравнений и делается вывод при сравнении множеств
 *
 * ПРИМЕР:
 * {1, 2, 3} (< or <= or !=) {1, 2, 3, 4}
 * {1, 2, 4} (== or <= or >=) {1, 2, 4}
 * {1, 2, 3} (< or <= or !=) {1, 2, 4}
 *
 *
 * доступные операции сравнения
 * <this> == <other>
 * <this> != <other>
 * <this> < <other>
 * <this> > <other>
 * <this> <= <other>
 * <this> >= <other>
 * для всех вышеперечисленных операций на вывод подается результат
 * сравнения множеств <this> и <other> по вышеописанным правилам
 *
 *
 * <this> + <value>
 * <this> - <value>
 * возвращает массив с добавленным / удаленным элементом <value>
 *
 * <this> + <other>
 * возвращает объединение двух массивов <this> и <other>
 *
 * <this> += <value>
 * <this> -= <value>
 * добавляет / удаляет элемент <value> из массива <this>
 *
 * <this> += <other>
 * в <this> записывает объединение двух массивов <this> и <other>
 *
 *
 *
 * функции для данной реализации множества:
 *
 *
 * combining(<set1>, <set2>)
 * операция объединение множеств, возвращает множество, которое является
 * объединение двух множеств множеств <set1> и <set2>
 *
 *
 * intersection(<set1>, <set2>)
 * операция пересечение множеств, возвращает множество, которое является
 * пересечением двух множеств множеств <set1> и <set2>
 *
 *
 * boolean(<set>)
 * возвращает множество множеств, которое является булеаном исходного
 * множества <set> (множество всех нестрогих подмножеств)
 *
 *
 * printSet(<set>, <end>='\n')
 * выводит на экран множество set (в том числе если оно состоит из других множеств)
 * в конце выводится символ записанный в переменную end (по умолчанию '\n')
 *
 *
 * std::cout << <set>
 * кроме функции printSet() для вывода множества на экран можно пользоваться
 * стандартным потоком вывода (std::cout)
 *
 */


template <typename T>
class mySet {
public:
    mySet();
        // базовый конструктор

    mySet(const mySet<T>& other);
        // конструктор копирования


    mySet& operator=(const mySet<T>& other);
        // опереатор присваивания копированием


    ~mySet();
        // деструктор

    // по правиду трех (пяти) надо записать все эти конструткоры/операторы/деструткоры
    // иначе ничего не будет работать (проверено)


    void add(T value);
        // добавление элемента во множество (если элемент присутствует ничего не делает)

    void del(T value);
        // удаление элемента из множества (если элемент отсутствует ничего не делает)

    void clear();
        // удаляет все значения записанные во множество

    int getSize() const;
        // получение мощности множества

    bool contain(T value) const;
        // проверки наличия элемента во множестве

    int index(T value) const;
        // возвращает индекс элемента во множестве, если элемент отсутствует возвращает -1

    mySet<T> operator+(mySet<T> other);
        // объединение множеств

    void operator+=(mySet<T> other);
        // объединение множеств сокращенная запись

    mySet<T> operator+(T value);
        // добавление элемента во множество

    void operator+=(T value);
        // добавление элемента во множество сокращенная запись

    mySet<T> operator-(T value);
        // удаление элемента из множества

    void operator-=(T value);
        // удаление элемента из множества сокращенная запись

    T& operator[](int i) const;
        // оператор обращения по индексу к элементу множества
        // в случае выхода за предел множества или обращения по отрицательному индексу кидает std::out_of_range

    bool operator<(const mySet<T>& other);

    bool operator>(const mySet<T>& other);

    bool operator<=(const mySet<T>& other);

    bool operator>=(const mySet<T>& other);

    bool operator==(const mySet<T>& other);

    bool operator!=(const mySet<T>& other);


private:

    int index_to_insert(T value);
        // требуется для работы метода add() (куда вставить элемент)

    int index_to_delete(T value);
        // требуется для работы метода del() (индекс элемента для удаления)

    int size;
        // хранит мощность множества

    T* set;
        // указатель на массив элементов множества

};


template <typename T>
mySet<T> combining(mySet<T> set1, mySet<T> set2);
    // операция объединение множеств
    // возвращает объединение двух исходных множеств

template <typename T>
mySet<T> intersection(mySet<T> set1, mySet<T> set2);
    // операция пересечение множеств
    // возвращает пересечение двух исходных множеств

template <typename T>
mySet<mySet<T>> boolean(mySet<T> set1);
    // функция возвращающая булеан множества
    // возвращает все  все подмножества исходного множества

template <typename T>
void printSet(mySet<T> set, char end = '\n');
    // вывод множества в терминал


#include "mySet.inl"

#endif
