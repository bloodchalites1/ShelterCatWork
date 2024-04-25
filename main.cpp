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
        cout << "���� �����: " << PrintCatColor(cat->GetColor()) << "."
             << " ���������� �����: " << PrintCatMood(cat->GetMood())
             << ". ������������: " << PrintCatType( cat->GetType()) << endl;
    }
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    cout << "�������� ����� ��� �����!\n" << endl;

    NormalCats cat1;
    /*
    cout << "������ �����\n";
    cat1.View();
    cat1.GetHungry();
    cat1.Pat();
    cat1.Feed();
    cout << "\n";
    cout << "������ �����\n";
    */
    HellsCats cat2;
    /*
    cat2.View();
    cat2.GetHungry();
    cat2.Pat();
    cat2.Feed();
    cout << "\n";
    cout << "������ �����\n";
    */
    ParadiseCats cat3;
    /*
    cat3.View();
    cat3.GetHungry();
    cat3.Pat();
    cat3.Feed();
    cout << "\n";
    */
    CatContainer container1(5);
    container1.AddCat(&cat1);
    container1.AddCat(&cat2);
    container1.AddCat(&cat3);
    container1.AddCat(new NormalCats);
    container1.GetCount();
    cout << "\n";
    cout << "������� ��� ����� �1\n";
    cout << "\n";
    Iterator1(container1.GetIterator());
    cout << "\n";
    cout << "����-������� ��� ����� �2\n\n";
    MegaCatContainer container2;
        //���������� ����� � ������� �2
    MegaCatContainer ccontainer2;

    for(int i=0; i<3; i++)
    {
        container2.AddCat(new NormalCats);
    }
    for(int i=0; i<5; i++)
    {
        container2.AddCat(new ParadiseCats);
    }
    for(int i=0; i<2; i++)
    {
        container2.AddCat(new HellsCats);
    }
    //����� ������ iterator1
    Iterator1(container2.GetIterator());
    return 0;
}
