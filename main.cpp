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
    cat1.View();
    cat1.GetHungry();
    HellsCats cat2;
    cat2.View();
    cat2.GetHungry();
    ParadiseCats cat3;
    cat3.View();
    cat3.GetHungry();


    return 0;
}
