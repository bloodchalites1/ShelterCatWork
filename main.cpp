#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>


using namespace std;


#include "Shelter.h"


int main()
{

    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    wcout << "Странный приют для кошек!\n" << endl;
    wcout << "Первая кошка\n";
    NormalCats cat1;
    cat1.View();
    cat1.GetHungry();
    cat1.Pat();
    cat1.Feed();
    wcout << "\n";

    wcout << "Вторая кошка\n";
    HellsCats cat2;
    cat2.View();
    cat2.GetHungry();
    cat2.Pat();
    cat2.Feed();
    wcout << "\n";

    wcout << "Третья кошка\n";
    ParadiseCats cat3;
    cat3.View();
    cat3.GetHungry();
    cat3.Pat();
    cat3.Feed();
    wcout << "\n";
    wcout << "Коробка для кошек\n";
    CatContainer container(5);
    container.AddCat(&cat1);
    container.AddCat(&cat2);
    container.AddCat(&cat3);
    container.AddCat(new NormalCats);
    container.GetCount();

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
    return 0;
}
