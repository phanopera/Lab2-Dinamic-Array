# Lab2-Dinamic-Array
В ходе выполнения данной лабораторной работы был релизован АТД динамического массива:

template<typename T>
class Array final

АДТ поддерживает следующие операции:
<ul><li>Конструктор <strong>Array(); / Array(int capacity); </strong>
<li>Деструктор  <strong>~Array();</strong>
<li>Вставка элементов (с использованием move-семантики)  <strong>int insert(const T& value); / int insert(int index, const T& value);</strong>
<li> Удаление элемента  <strong>void remove(int index);</strong>
<li>Обращение к элементу по индексу  <strong>const T& operator[](int index) const; / T& operator[](int index);</strong>
<li>Возвращение размера массива  <strong>int size() const;</strong>
<li>Итератор  <strong>Iterator iterator(); / ConstIterator iterator() const;</strong>
<li>Реверсивный итератор  <strong>Iterator reverseIterator(); / ConstIterator reverseIterator() const;</strong>
  </ul>
Итератор реализован, как класс, и ему также доступны следующие операции:<ul>
<li>Получение значения массива в текущей позиции итератора  <strong>const T& get() const;</strong>
<li>Установление значения в текущей позиции итератора  <strong>void set(const T& value);</strong>
<li>Перемещение текущей позиции итератора на следующий элемент  <strong>void next();</strong>
<li>Определение возможности перехода к следующему элементу  <strong>(true/false) bool hasNext() const;</strong></ul>
