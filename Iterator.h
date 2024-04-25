#ifndef ITERATOR_H
#define ITERATOR_H

template<class Type>        //������ ���������
class Iterator
{
protected:

    //���������� �����������
    Iterator() {}

    //�������� ���������
public:
    virtual ~Iterator() {}
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() const = 0;
    virtual Type GetCurrent() const = 0;
};

    //������ "���������" ����������-����������
    //��������� ��� ��������� � ����� �� �����������, ������������ ��� ���������� ��� ���������� ������

template<class Type>
class IteratorDecorator : public Iterator<Type>
{
protected:
    Iterator<Type> *It;  // ��������� �� ������� ��������

public:
    IteratorDecorator(Iterator<Type> *it)
    {
        It = it;
    }
    // ����������� ���������� ��� ������������ ������
    virtual ~IteratorDecorator() { delete It; }
    // ����� ������������� �������� �� ������ ����������
    virtual void First() { It->First(); }
    // ����� ���������� �������� � ���������� �������� ����������
    virtual void Next() { It->Next(); }
    virtual bool IsDone() const { return It->IsDone(); }
    // ����� ���������� ������� �������, �� ������� ��������� ��������
    virtual Type GetCurrent() const { return It->GetCurrent(); }
};

#endif // ITERATOR_H
