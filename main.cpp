#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

#include "Shelter.h"


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    wcout << "�������� ����� ��� �����!\n" << endl;
    wcout << "������ �����\n";
    NormalCats cat1;
    cat1.View();
    cat1.GetHungry();
    cat1.Pat();
    cat1.Feed();
    cout << "\n";
    wcout << "������ �����\n";
    HellsCats cat2;
    cat2.View();
    cat2.GetHungry();
    cat2.Pat();
    cat2.Feed();
    cout << "\n";
    wcout << "������ �����\n";
    ParadiseCats cat3;
    cat3.View();
    cat3.GetHungry();
    cat3.Pat();
    cat3.Feed();


    return 0;
}
