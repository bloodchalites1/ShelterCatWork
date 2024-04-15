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
        wcout << "Кажеться кошка голодна! \n";
    }
    else
    {
        wcout << "Кажется кошка сыта! \n";
    }
}

void Cat::Feed()
{
    if(Hungry == 0)
    {
        wcout << "Вы покормили кошку мяском" << endl;
        Hungry = 1;
        GetHungry();
    }
}

string PrintDemonCat( HellObject demon )
{
    switch(demon)
    {
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
        case ParadiseObject::Halo : return "нимб";
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
        case CatType::Kitty : return "котёнок";
        case CatType::Little : return "миниатюрная кошка";
        case CatType::Average : return "средняя кошка";
        case CatType::Big : return "большая кошка";
    }
}
string PrintCatMood(CatMood mood )
{
    switch(mood)
    {
    case CatMood::Bad : return "плохо...";
    case CatMood::Nice : return "отлично!";
    case CatMood::Play : return "игривой!";
    case CatMood::Painful : return "довольно болезненно...";
    }
}
string PrintCatColor(CatColorEnum color )
{
    switch(color)
    {
        case CatColorEnum::Red : return "рыжей";
        case CatColorEnum::Black : return "черной";
        case CatColorEnum::White : return "белой";
        case CatColorEnum::Blue : return "голубоватой";
        case CatColorEnum::Chocolate : return "шоколадной";
        case CatColorEnum::Another : return "разноцветной";
    }
}
