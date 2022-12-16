// array.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma once
#include <iostream>


template<typename T>
class TArray final{

    class Iterator {
       // iterator();
       // reverseIterator();
    }
    class ConstIterator:public Iterator {
     //  iterator() const;
      //  reverseIterator() const;
    }
public:
    T *data;
    TArray();
    TArray(int capacity);


    int insert(const T& value);
    int insert(int index, const T& value);
    void remove(int index);
    const T& operator[](int index) const;
    T& operator[](int index);
    int size() const;
    Iterator iterator();
    ConstIterator iterator() const;
    Iterator reverseIterator();
    ConstIterator reverseIterator() const;
    ~TArray();
private:

    const int capacityDefault = 8; //или 16
    const int capacityAdding = 2; //или 16

    T* _data;
    int _size;
    int _capacity;

};
//выделение памяти дефолт
template<typename T>
inline TArray<T>::TArray() {
    _capacity = capacityDefault;
    _size = 0;
    _data = (T*)malloc(sizeof(T*) * _capacity); //выделение памяти под массив, узнав размер массива 
}
//выделение памяти дефолт 
template<typename T>
inline TArray<T>::TArray(int capacity) {
    _capacity = capacity;
    _size = 0;
    _data = (T*)malloc(sizeof(T*) * _capacity); //выделение памяти под массив, согласно указанной вместимости, узнав размер массива
    
}

//деструктор
template<typename T>
inline TArray<T>::~TArray() {
    for (int i = 0; i < _size; ++i) {
        dataT[i].~T();  //удаление элементов
    }
    free(_data); //освобождение памяти
}

//выделение памяти, вставка
template<typename T>
inline int TArray<T>::insert(const T& value) {
    if (_size == _capacity) { 
        _capacity = _capacity * capacityAdding;//увечичение веса ради вместимости
        T* newData = (T*)malloc(sizeof(T*) * _capacity); //выделение памяти под временный массив, узнав размер массива 
        for (int i = 0; i < _size; i++) {
            new (newData + i) T(std::move(_data[i])); //вызывается конструктор, копирующмй элементы
        }
        for (int i = 0; i < _size; i++) {
            dataT[i].~T(); 
        }
        free(_data);
        _data = newData;
        delete(newData);
        newData = nullptr;//"Перед тем как закрывать дверь (присваивать указателю nullptr) не забывайте смывать (использовать delete), во избежание переполнения стока (стека)."
    }
    new (data_ + size_) T(value); //вызывается конструктор по умолчанию
        _size++;
        return _size - 1;
}
//выделение памяти, вставка в место
template<typename T>
inline int TArray<T>::insert(int index, const T& value) {
    if (index >= 0 && index < _size) {
        if (_size == _capacity) {
            _capacity = _capacity * capacityAdding;//увечичение веса ради вместимости
            T* newData = (T*)malloc(sizeof(T*) * _capacity); //выделение памяти под временный массив, узнав размер массива 
            for (int i = 0; i < _size; i++) {
                new (newData + i) T(std::move(_data[i])); //вызывается конструктор, копирующмй элементы
            }
            for (int i = 0; i < _size; i++) {
                dataT[i].~T();
            }
            free(_data);
            _data = newData;
            delete(newData);
            newData = nullptr;//"Перед тем как закрывать дверь (присваивать указателю nullptr) не забывайте смывать (использовать delete), во избежание переполнения стока (стека)."
        }
        _size++;
        for (int i = _size-1; i > index; i--) {//перенос объектов до index
            new (_data + i) T(std::move(_data[i-1])); //вызывается конструктор, копирующмй элементы
            dataT[i-1].~T();
        }
        new(_data + index) T(value);
        return index;
    }
    else return -1;
}

//удаление элемента
template<typename T>
inline void TArray<T>::remove(int index) {
    if (index >= 0 || index < _size) {
        _data[index].~T();

        for (int i = index; i < _size-1; i++) {//перенос объектов от index
            _data[i].~T();
            new (_data + i) T(std::move(_data[i + 1])); //вызывается конструктор, копирующмй элементы   
        }
        _size--;
    }
    else { cout << "wrong index" << endl; }
}

template<typename T>
inline int TArray<T>::size() const {
    /*this->value;
    return sizeof(value);*/
}


int main()
{
    TArray<int> a;
    for (int i = 0; i < 10; ++i)
        a.insert(i + 1);
    for (int i = 0; i < a.size(); ++i)
        a[i] *= 2;
    for (auto it = a.iterator(); it.hasNext(); it.next())
        std::cout << it.get() << std::endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
