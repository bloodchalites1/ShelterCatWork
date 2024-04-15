#include <iostream>


using namespace std;

#include "Shelter.h"
//РАНДОМНЫЙ ГОЛОД КОШЕК
Cat::Cat()
{
    Hungry = bool(rand() % 2);
}

bool Cat::GetHungry() const
{
    if(Hungry == 0)
    {
        wcout << "Кажеться кошка голодна! \n";
    }
    else
    {
        wcout << "Кажется кошка сыта! \n";
    }
}

