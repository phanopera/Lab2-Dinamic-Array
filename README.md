# Lab2-Dinamic-Array
В ходе выполнения данной лабораторной работы был релизован АТД динамического массива:

template<typename T>
class Array final

АДТ поддерживает следующие операции:
<ul><li>Конструктор `Array(); Array(int capacity);
<li>Деструктор `~Array();
<li>Вставка элементов (с использованием move-семантики) `int insert(const T& value); / int insert(int index, const T& value);
<li> Удаление элемента void remove(int index);
<li>Обращение к элементу по индексу const T& operator[](int index) const; / T& operator[](int index);
<li>Возвращение размера массива int size() const;
<li>Итератор Iterator iterator(); / ConstIterator iterator() const;
<li>Реверсивный итератор Iterator reverseIterator(); / ConstIterator reverseIterator() const;
  </ul>
Итератор реализован, как класс, и ему также доступны следующие операции:<ul>
<li>Получение значения массива в текущей позиции итератора const T& get() const;
<li>Установление значения в текущей позиции итератора void set(const T& value);
<li>Перемещение текущей позиции итератора на следующий элемент void next();
<li>Определение возможности перехода к следующему элементу (true/false) bool hasNext() const;</ul>
