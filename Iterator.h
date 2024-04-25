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



#endif // ITERATOR_H
