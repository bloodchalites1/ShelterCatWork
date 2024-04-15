#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "Shelter.h"


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    wcout << "Странный приют для кошек!" << endl;
    NormalCats cat1;
    wcout << "Первая кошка\n";
    cat1.GetHungry();
    HellsCats cat2;
    wcout << "Вторая кошка\n";
    cat2.GetHungry();
    ParadiseCats cat3;
    wcout << "Третья кошка\n";
    cat3.GetHungry();


    return 0;
}
