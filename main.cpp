#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "Shelter.h"


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    wcout << "�������� ����� ��� �����!" << endl;
    NormalCats cat1;
    wcout << "������ �����\n";
    cat1.GetHungry();
    HellsCats cat2;
    wcout << "������ �����\n";
    cat2.GetHungry();
    ParadiseCats cat3;
    wcout << "������ �����\n";
    cat3.GetHungry();


    return 0;
}
