#include <iostream>


using namespace std;

#include "Shelter.h"
//РАНДОМ ГОЛОДА КОШЕК
Cat::Cat()
{
    Hungry = bool(rand() % 2);
}

bool Cat::GetHungry() const
{
    if(Hungry == 0)
    {
        wcout << "Кажется кошка голодна! \n";
    }
    else
    {
        wcout << "Кажется кошка сыта! \n";
    }
}
string PrintDemonCat( HellObject demon )
{
    switch(demon)
    {
        //инициализирование обьектов перечисления класса
        case HellObject::HellWings : return "демонические крылья";
        case HellObject::Hooves : return "копыта";
        case HellObject::Horns : return "рога";
    }
}


string PrintAngelCat( ParadiseObject angel )
{
    switch(angel)
    {
        case ParadiseObject::ParadiseWings : return "ангельские крылья";
        case ParadiseObject::Halo : return "Нимб";
        case ParadiseObject::Bible : return "Библия";
    }
}

string PrintNormalCat( CatBreed breed )
{
    switch(breed)
    {
        case CatBreed::MainCoon : return "Мейн-Кун";
        case CatBreed::Russian : return "Русская голубая кошка";
        case CatBreed::Sfinks : return "Сфинкс";
        case CatBreed::Savanna : return "Саванна";
        case CatBreed::Persian : return "Персидская кошка";
        case CatBreed::Munchkin : return "Манчкин";
        case CatBreed::Another : return "Другая порода кошки";
    }
}
string PrintCatType( CatType type )
{
    switch(type)
    {
        case CatType::Kitty : return "Котёнок";
        case CatType::Little : return "Миниатюрная кошка";
        case CatType::Average : return "Средняя кошка";
        case CatType::Big : return "Большая кошка";
    }
}
