# Лабораторная работа №1
## Расчётная работа 🔢


- `Цель` - создать библиотеку для работы с очередями с приоритетом
- `Задача` - реализовать класс `очеередь с приоритетом` и функции для работы с очередями с приоритетом
- `Вариант` - $\textcolor{grey}{\textit{25}}$

## Список ключевых понятий (определения) ❓
- `Очередь с приоритетом` — абстрактный тип данных в программировании, поддерживающий две обязательные операции — добавить элемент и извлечь максимум (минимум). Предполагается, что для каждого элемента можно вычислить его приоритет — действительное число или в общем случае элемент линейно упорядоченного множества.

## Алгоритм
 Очередь с приоритетом реализована как вектор, содержащий пары элементов, где первый элемент пары это элемент очереди, а второй это значение его приоритета. Элементы выходят из очереди в порядки уменьшения приоритета
 
 Допустим, наш исходный массив будет: [<7, 3>, <2, 4>, <5, 6>, <1, 0>]

Тогда элементы будут выводиться в порядке [5, 2, 7, 1] 
 


### Нерекурсивная реализация

#### Объявление

``` c++
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <fstream>

template<typename T>
class PriorityQueue {
public:
    void push(T item, int priority);
    T pop();
    bool empty();
    void readFromFile(const std::string& filename);

private:
    std::vector<std::pair<T, int>> queue;
    static bool compare(const std::pair<T, int>& a, const std::pair<T, int>& b);
};
```

#### Реализация


``` c++
template<typename T>
void PriorityQueue<T>::push(T item, int priority) {
    queue.push_back(std::make_pair(item, priority));
    std::sort(queue.begin(), queue.end(), compare);
}


template<typename T>
T PriorityQueue<T>::pop() {
    if (!queue.empty()) {
        T item = queue.back().first;
        queue.pop_back();
        return item;
    }
    throw std::runtime_error("Queue is empty");
}

template<typename T>
bool PriorityQueue<T>::empty() {
    return queue.empty();
}

template<typename T>
bool PriorityQueue<T>::compare(const std::pair<T, int>& a, const std::pair<T, int>& b) {
    return a.second < b.second;
}

template<typename T>
void PriorityQueue<T>::readFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        throw std::runtime_error("Не удалось открыть файл");
    }

    T item;
    int priority;
    while (file >> item >> priority) {
        push(item, priority);
    }
}
```

## Вывод
 Реализовал структуру данных `дерево отрезков`, а в частности `дерево максимумов`