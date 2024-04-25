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
        cout << "Цвет кошки: " << PrintCatColor(cat->GetColor()) << "."
             << " Настроение кошки: " << PrintCatMood(cat->GetMood())
             << ". Телосложение: " << PrintCatType( cat->GetType()) << endl;
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
    container1.AddCat(&cat1);
    container1.AddCat(&cat2);
    container1.AddCat(&cat3);
    container1.AddCat(new NormalCats);


    cout << "\n";
    cout << "Коробка для кошек №1\n";
    cout << "\n";
        //вызов функции
    Iterator1(container1.GetIterator());
        //кол-во кошек в коробке
    container1.GetCount();


    cout << "\n";
    cout << "Мега-Коробка для кошек №2\n\n";
    MegaCatContainer container2;


        //Добавление кошек в коробку №2
    for(int i=0; i<10; i++)
    {
        container2.AddCat(new NormalCats);
    }
    for(int i=0; i<15; i++)
    {
        container2.AddCat(new ParadiseCats);
    }
    for(int i=0; i<18; i++)
    {
        container2.AddCat(new HellsCats);
    }
    cout << "В мега-коробке "<< container2.GetCount() << " кошек" << endl;
        // декоратор №1 выводит только кошек с отличны настроением
    //Iterator<CatPtr> *it = new CatMoodDecorator(container2.GetIterator(), CatMood::Nice);
        //декоратор №2 выводит только больших кошек
    //Iterator<CatPtr> *it = new CatTypeDecorator(container2.GetIterator(), CatType::Big);
        // декоратор №3 выводит только рыжих кошек
    Iterator<CatPtr> *it = new CatColorDecorator(container2.GetIterator(), CatColorEnum::Red);
    Iterator1(it);
    cout << endl;
        //выводит всех кошек их мега-коробки
    //Iterator1(container2.GetIterator());
    return 0;
}
