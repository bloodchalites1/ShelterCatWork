#include <iostream>


using namespace std;

#include "Shelter.h"
//��������� ����� �����
Cat::Cat()
{
    Hungry = bool(rand() % 2);
}

bool Cat::GetHungry() const
{
    if(Hungry == 0)
    {
        wcout << "�������� ����� �������! \n";
    }
    else
    {
        wcout << "������� ����� ����! \n";
    }
}

