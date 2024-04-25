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
        cout << endl;
    }
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    cout << "Странный приют для кошек!\n" << endl;

    NormalCats cat1;
    /*
    cout << "Первая кошка\n";
    cat1.View();
    cat1.GetHungry();
    cat1.Pat();
    cat1.Feed();
    cout << "\n";
    cout << "Вторая кошка\n";
    */
    HellsCats cat2;
    /*
    cat2.View();
    cat2.GetHungry();
    cat2.Pat();
    cat2.Feed();
    cout << "\n";
    cout << "Третья кошка\n";
    */
    ParadiseCats cat3;
    /*
    cat3.View();
    cat3.GetHungry();
    cat3.Pat();
    cat3.Feed();
    cout << "\n";
    */
    cout << "Коробка для кошек\n";
    CatContainer container(5);
    container.AddCat(&cat1);
    container.AddCat(&cat2);
    container.AddCat(&cat3);
    container.AddCat(new NormalCats);
    container.GetCount();
    cout << "\n";
    /*
    MegaCatContainer catBox;

    for(int i=0; i<10; i++)
    {
        catBox.AddCat(new NormalCats);
    }
    for(int i=0; i<20; i++)
    {
        catBox.AddCat(new ParadiseCats);
    }
    for(int i=0; i<20; i++)
    {
        catBox.AddCat(new HellsCats);
    }
    */
    Iterator1(container.GetIterator());
    return 0;
}
