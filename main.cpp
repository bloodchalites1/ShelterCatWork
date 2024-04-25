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
    HellsCats cat2;
    ParadiseCats cat3;
    CatContainer container1(5);
    container1.AddCat(&cat1);
    container1.AddCat(&cat2);
    container1.AddCat(&cat3);
    container1.AddCat(new NormalCats);


    cout << "\n";
    cout << "������� ��� ����� �1\n";
    cout << "\n";
        //����� �������
    Iterator1(container1.GetIterator());
        //���-�� ����� � �������
    container1.GetCount();


    cout << "\n";
    cout << "����-������� ��� ����� �2\n\n";
    MegaCatContainer container2;


        //���������� ����� � ������� �2
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
    cout << "� ����-������� "<< container2.GetCount() << " �����" << endl;
        // ��������� �1 ������� ������ ����� � ������� �����������
    //Iterator<CatPtr> *it = new CatMoodDecorator(container2.GetIterator(), CatMood::Nice);
        //��������� �2 ������� ������ ������� �����
    //Iterator<CatPtr> *it = new CatTypeDecorator(container2.GetIterator(), CatType::Big);
        // ��������� �3 ������� ������ ����� �����
    Iterator<CatPtr> *it = new CatColorDecorator(container2.GetIterator(), CatColorEnum::Red);
    Iterator1(it);
    cout << endl;
        //������� ���� ����� �� ����-�������
    //Iterator1(container2.GetIterator());
    return 0;
}
