#include <iostream>

using namespace std;

#include "Shelter.h"

//������ ������ �����

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
string PrintDemonCat( HellObject demon )
{
    switch(demon)
    {
        case HellObject::HellWings : return "������������ ������";
        case HellObject::Hooves : return "������";
        case HellObject::Horns : return "����";
    }
}


string PrintAngelCat( ParadiseObject angel )
{
    switch(angel)
    {
        case ParadiseObject::ParadiseWings : return "���������� ������";
        case ParadiseObject::Halo : return "����";
        case ParadiseObject::Bible : return "������";
    }
}

string PrintNormalCat( CatBreed breed )
{
    switch(breed)
    {
        case CatBreed::MainCoon : return "����-���";
        case CatBreed::Russian : return "������� ������� �����";
        case CatBreed::Sfinks : return "������";
        case CatBreed::Savanna : return "�������";
        case CatBreed::Persian : return "���������� �����";
        case CatBreed::Munchkin : return "�������";
        case CatBreed::Another : return "������ ������ �����";
    }
}
string PrintCatType( CatType type )
{
    switch(type)
    {
        case CatType::Kitty : return "������";
        case CatType::Little : return "����������� �����";
        case CatType::Average : return "������� �����";
        case CatType::Big : return "������� �����";
    }
}
string PrintCatMood(CatMood mood )
{
    switch(mood)
    {
    case CatMood::Bad : return "�����...";
    case CatMood::Nice : return "�������!";
    case CatMood::Play : return "�������!";
    case CatMood::Painful : return "�������� ����������...";
    }
}
