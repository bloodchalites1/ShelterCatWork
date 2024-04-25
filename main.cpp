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
        cout << "�������������: " << PrintCatOrigin(cat->GetOrigin())
             << ". ���� �����: " << PrintCatColor(cat->GetColor())
             << ". ���������� �����: " << PrintCatMood(cat->GetMood())
             << ". ������������: " << PrintCatType(cat->GetType()) << endl;
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
    container1.AddCat(&cat1);           //
    container1.AddCat(&cat2);           // �������� ������������ ����� � �������
    container1.AddCat(&cat3);           //
    container1.AddCat(new NormalCats);  //�������� ����� �����


    cout << "\n";
    cout << "������� ��� ����� �1\n\n";
        //����� ������� Iterator1
        //���-�� ����� � �������
    container1.GetCount();
    Iterator1(container1.GetIterator());

    cout << "\n";
    cout << "����-������� ��� ����� �2\n\n";
    MegaCatContainer container2;
    int randomCount = rand()%90;
    for( int i = 0; i < randomCount ; i++)
    {
        container2.AddCat(Cat::Find(RandomCatOrigin()));
    }
    wcout << "� ����-������� " << container2.GetCount() << " �����" << endl;

        //������� ���� ����� �� ����-�������
    Iterator1(container2.GetIterator());

        // ��������� �1 ������� ������ ����� � ������� �����������
    //Iterator<CatPtr> *it = new CatMoodDecorator(container2.GetIterator(), CatMood::Nice);
        //��������� �2 ������� ������ ������� �����
    //Iterator<CatPtr> *it = new CatTypeDecorator(container2.GetIterator(), CatType::Big);
        // ��������� �3 ������� ������ ����� �����
    //Iterator<CatPtr> *it = new CatColorDecorator(container2.GetIterator(), CatColorEnum::Red);
    //Iterator1(it);
    return 0;
}
