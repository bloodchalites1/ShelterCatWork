#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>


using namespace std;


#include "Shelter.h"


void Iterator1(Iterator<CatPtr> *it)
{
    for(it->First(); !it->IsDone(); it->Next())
    {
        CatPtr cat = it->GetCurrent();
        cout << "Происхождение: " << PrintCatOrigin(cat->GetOrigin())
             << ". Цвет кошки: " << PrintCatColor(cat->GetColor())
             << ". Настроение кошки: " << PrintCatMood(cat->GetMood())
             << ". Телосложение: " << PrintCatType(cat->GetType()) << endl;
    }
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    cout << "Странный приют для кошек!\n" << endl;

    NormalCats cat1;
    HellsCats cat2;
    ParadiseCats cat3;
    CatContainer container1(5);
    container1.AddCat(&cat1);           //
    container1.AddCat(&cat2);           // ДОБАВИТЬ СУЩЕСТВУЮЩИХ КОШЕК В КОРОБКУ
    container1.AddCat(&cat3);           //
    container1.AddCat(new NormalCats);  //Добавить новую кошку


    cout << "\n";
    cout << "Коробка для кошек №1\n\n";
        //вызов функции Iterator1
        //кол-во кошек в коробке
    container1.GetCount();
    Iterator1(container1.GetIterator());

    cout << "\n";
    cout << "Мега-Коробка для кошек №2\n\n";
    MegaCatContainer container2;
    int randomCount = rand()%90;
    for( int i = 0; i < randomCount ; i++)
    {
        container2.AddCat(Cat::Find(RandomCatOrigin()));
    }
    wcout << "В мега-коробке " << container2.GetCount() << " кошек" << endl;

        //выводит всех кошек их мега-коробки
    Iterator1(container2.GetIterator());

        // декоратор №1 выводит только кошек с отличны настроением
    //Iterator<CatPtr> *it = new CatMoodDecorator(container2.GetIterator(), CatMood::Nice);
        //декоратор №2 выводит только больших кошек
    //Iterator<CatPtr> *it = new CatTypeDecorator(container2.GetIterator(), CatType::Big);
        // декоратор №3 выводит только рыжих кошек
    //Iterator<CatPtr> *it = new CatColorDecorator(container2.GetIterator(), CatColorEnum::Red);
    //Iterator1(it);
    return 0;
}
