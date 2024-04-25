#ifndef ITERATOR_H
#define ITERATOR_H

template<class Type>        //шаблон итератора
class Iterator
{
protected:

    //защищенный конструктор
    Iterator() {}

    //открытый интерфейс
public:
    virtual ~Iterator() {}
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual Type GetCurrent() const = 0;
};

    //Щаблон "основного" интерфейса-декоратора
    //Декоратор для итератора с таким же интерфейсом, предназначен для сортировки или фильтрации данных

template<class Type>
class IteratorDecorator : public Iterator<Type>
{
protected:
    Iterator<Type> *It;  // Указатель на базовый итератор

public:
    IteratorDecorator(Iterator<Type> *it)
    {
        It = it;
    }
    // Виртуальный деструктор для освобождения памяти
    virtual ~IteratorDecorator() { delete It; }
    // Метод устанавливает итератор на начало контейнера
    virtual void First() { It->First(); }
    // Метод перемещает итератор к следующему элементу контейнера
    virtual void Next() { It->Next(); }
    virtual bool IsDone() const { return It->IsDone(); }
    // Метод возвращает текущий элемент, на который указывает итератор
    virtual Type GetCurrent() const { return It->GetCurrent(); }
};

#endif // ITERATOR_H
