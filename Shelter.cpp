#include <iostream>

using namespace std;


#include "Shelter.h"


    //������ ������ �����

Cat::Cat()
{
    Hungry = bool(rand() % 2);
}

    //����� �����

bool Cat::GetHungry() const
{
    if(Hungry == 0){ cout << "������� ����� �������! \n"; }
    else { cout << "������� ����� ����! \n"; }
}

    //��������� �����

void Cat::Feed()
{
    if(Hungry == 0)
    {
        cout << "�� ��������� ����� ������" << endl;
        Hungry = 1;
        GetHungry();
    }
}

    //����������� ������ CatContainer � ��������� ������������ ������ ����������

CatContainer::CatContainer(int maxSize)
{
    CatBox = new CatPtr[maxSize];   //���. ������ ������� �������

    for(int i=0; i<maxSize; i++)
    {
        CatBox[i] = NULL;           //���������� � ���������� ��� ������
    }

    CatCount = 0;                   //���-�� ����� � ����������
    MaxSize = maxSize;              //���� ������ ����� ������������� ������� ����������
}

    //����������� �����, ������� ������������ �� �������((

CatContainer::~CatContainer()
{
    for(int i=0; i< MaxSize; i++)
    {
        if(CatBox[i] != NULL)       //���� � ���������� �� ���� �����
        {
            delete CatBox[i];       //�� ��������� ���������
            CatBox[i] = NULL;       // � ��������� ����� ����
        }
    }

    delete [] CatBox;
}

    //���������� ����� � �������

void CatContainer::AddCat(CatPtr newCat)
{
    if(CatCount != MaxSize)
    {
        CatBox[CatCount++] = newCat;
        static int n = 1;
        cout << "�������� � ������� " << n++ << " �����"<< endl;
    }
    else
    {
        cout << "������� ����������� �������" << endl;
    }
}

CatBreed RandomCatBreed()
{
    return CatBreed(rand() % 4);
}


Cat *Cat::Find(CatBreed breed)
{
    return Find(breed);
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
        //default: return nullptr;
    }
}

string PrintCatMood(CatMood mood )
{
    switch(mood)
    {
    case CatMood::Bad : return "������";
    case CatMood::Nice : return "��������";
    case CatMood::Play : return "�������";
    case CatMood::Painful : return "�������� �����������";
    }
}

string PrintCatColor(CatColorEnum color )
{
    switch(color)
    {
        case CatColorEnum::Red : return "�����";
        case CatColorEnum::Black : return "������";
        case CatColorEnum::White : return "�����";
        case CatColorEnum::Blue : return "�����������";
        case CatColorEnum::Chocolate : return "����������";
        case CatColorEnum::Another : return "������������";
    }
}


