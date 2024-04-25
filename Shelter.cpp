#include <iostream>

using namespace std;


#include "Shelter.h"

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
    case CatMood::Bad : return "плохое";
    case CatMood::Nice : return "отличное";
    case CatMood::Play : return "игривое";
    case CatMood::Painful : return "довольно болезненное";
    }
}

string PrintCatColor(CatColorEnum color )
{
    switch(color)
    {
        case CatColorEnum::Red : return "рыжый";
        case CatColorEnum::Black : return "черный";
        case CatColorEnum::White : return "белый";
        case CatColorEnum::Blue : return "голубоватый";
        case CatColorEnum::Chocolate : return "шоколадный";
        case CatColorEnum::Another : return "разноцветный";
    }
}
string PrintCatOrigin(OriginCats origin)
{
    switch(origin)
    {
        case OriginCats::HellsCats : return "Адская кошка";
        case OriginCats::NormalCats : return "Обычная кошка";
        case OriginCats::ParadiseCats : return "Райская кошка";
    }
}

Cat *Cat::Find(OriginCats origin) //Происхождение кошки
{
    switch(origin)
    {
        case OriginCats::NormalCats: return new NormalCats;
        case OriginCats::HellsCats: return new HellsCats;
        case OriginCats::ParadiseCats: return new ParadiseCats;
        default: return nullptr;
    }
}

OriginCats RandomCatOrigin()
{
    return OriginCats(rand() % 3);
}
   //РАНДОМ ГОЛОДА КОШЕК

Cat::Cat()
{
    Hungry = bool(rand() % 2);
}

    //голод кошек

bool Cat::GetHungry() const
{
    if(Hungry == 0){ cout << "Кажется кошка голодна! \n"; }
    else { cout << "Кажется кошка сыта! \n"; }
}

    //покормить кошку

void Cat::Feed()
{
    if(Hungry == 0)
    {
        cout << "Вы покормили кошку мяском" << endl;
        Hungry = 1;
        GetHungry();
    }
}

    //конструктор класса CatContainer и спользует максимальный размер контейнера

CatContainer::CatContainer(int maxSize)
{
    CatBox = new CatPtr[maxSize];   //дин. массив размера максайз

    for(int i=0; i<maxSize; i++)
    {
        CatBox[i] = NULL;           //изначально в контейнере нет никого
    }

    CatCount = 0;                   //кол-во кошек в коштейнере
    MaxSize = maxSize;              //макс размер равен максимальному размеру контейнера
}

    //Уничтожение кошек, назовем освобождение из коробки((

CatContainer::~CatContainer()
{
    for(int i=0; i< MaxSize; i++)
    {
        if(CatBox[i] != NULL)       //если в контейнере не нуль кошек
        {
            delete CatBox[i];       //то удаляется контейнер
            CatBox[i] = NULL;       // и контейнер снова пуст
        }
    }

    delete [] CatBox;
}

    //Добавление кошки в коробку

void CatContainer::AddCat(CatPtr newCat)
{
    if(CatCount != MaxSize)
    {
        CatBox[CatCount++] = newCat;
        static int n = 1;
        cout << "Посадили в коробку " << n++ << " кошек"<< endl;
    }
    else
    {
        cout << "Коробка переполнена кошками" << endl;
    }
}


