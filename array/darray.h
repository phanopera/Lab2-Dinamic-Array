#pragma once
#include <iostream>

template<typename T>
class TArray final{

    class Iterator {
    protected:
        T* _start;
        T* _current;
        TArray<T>* _mas;
        bool isReverces;
    public:
        Iterator(TArray<T>* mas, T* start, bool isReverces) {
            _current = start;
            _start = start;
            _mas = mas;
            this->isReverces= isReverces;
        }

        T& operator++ (int) { return *_current++; }
        T& operator-- (int) { return *_current--; }
        T& operator++ () { return *++_current; }
        T& operator-- () { return *--_current; }
        T& operator* () { return *_current; }

        const T& get() const;
        void set(const T& value);
        void next();
        bool hasNext() const;
       

    };
    class ConstIterator {
    protected:
        T* _start;
        T* _current;
        TArray<T>* _mas;
        bool isReverces;
    public:
        ConstIterator(TArray<T>* mas, T* start, bool isReverces) {        
            _current = start;
            _start = start;
            _mas = mas;
            this->isReverces= isReverces;
        }
        void set(const T& value) = delete;
        
        T& operator++ (int) { return *_current++; }
        T& operator-- (int) { return *_current--; }
        T& operator++ () { return *++_current; }
        T& operator-- () { return *--_current; }
        T& operator* () { return *_current; }
        void next();
        bool hasNext() const;
    };
public:

    TArray(int capacity);
    TArray();
   
    int insert(const T& value);
    int insert(int index, const T& value);
    void remove(int index);
    const T& operator[](int index) const;
    T& operator[](int index);
    int size() const;
    ~TArray();
    Iterator iterator() {
        return Iterator(this, _data, false);
    };
    Iterator reverseIterator() {
        return Iterator( this, _data + _size - 1, true);
    };
    ConstIterator cIterator() const{
        return ConstIterator(this, _data, false);
    };
    ConstIterator cReverseIterator() const {
        return ConstIterator(this,_data + _size - 1, true);
    };
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
//выделение памяти дефолт под размер
template<typename T>
inline TArray<T>::TArray(int capacity) {
    _capacity = capacity;
    _size = 0;
    _data = (T*)malloc(sizeof(T*) * _capacity); //выделение памяти под массив, согласно указанной вместимости, узнав размер массива
    
}

//деструктор
template<typename T>
inline TArray<T>::~TArray() {
    for (int i = 0; i < _size; i++) {
        _data[i].~T();  //удаление элементов
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
            _data[i].~T();
        }
        free(_data);
        _data = newData;
    }
    new (_data + _size) T(value); //вызывается конструктор по умолчанию
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
                _data[i].~T();
            }
            free(_data);
            _data = newData;
        }
        _size++;
        for (int i = _size-1; i > index; i--) {//перенос объектов до index
            new (_data + i) T(std::move(_data[i-1])); //вызывается конструктор, копирующмй элементы
            _data[i-1].~T();
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
    else { std::cout << "wrong index" << std::endl; }
}

//обращение к элементу массива
template<typename T>
inline const T& TArray<T>::operator[](int index) const {
    if (index >= 0 || index < _size) {
        return *(_data + index);
    }
    else { std::cout << "wrong index" << std::endl; }

}
template<typename T>
inline T& TArray<T>::operator[](int index) {
    if (index >= 0 || index < _size) {
        return *(_data + index);
    }
    else { std::cout << "wrong index" << std::endl; }
}

//количество элементов
template<typename T>
inline int TArray<T>::size() const {
    return _size;
}


//получение в текущей позиции
template<typename T>
inline const T& TArray<T>::Iterator::get() const {
    return *_current;
}
//вставка в текущей позиции
template<typename T>
inline void TArray<T>::Iterator::set(const T& value) {
    *_current = value;
}
//++ к текущей позиции
template<typename T>
inline void TArray<T>::Iterator::next() {
    if (isReverces) {
        _current--;
    }
    else {
        _current++;
    }
}

//проверка наличия еще одного элемента дальше
template<typename T>
inline bool TArray<T>::Iterator::hasNext() const {
    if (isReverces)//
    {
        if (_current == _start - _mas->_size) {
            return false;
        }
        else {
            return true;
        }
    }
    else
    {
        if (_current == _mas->_size+_start) {
            return false;
        }
        else {
            return true;
        }
    }
}
