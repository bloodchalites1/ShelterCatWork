#ifndef SHELTER_H
#define SHELTER_H
#include <vector>
#include "Iterator.h"


//������ 5 ����������\\
// ������� 1 ������� �����-��������� � 2 ����������� ����������

enum class CatBreed                 //������������ ����� �����
{
    MainCoon,
    Russian,
    Sfinks,
    Savanna,
    Persian,
    Munchkin,
    Another = -1
};
enum class CatColorEnum : int       //������������ ������ �����
{
    Black = 0,
    White = 1,
    Red = 2,
    Blue = 3,
    Chocolate = 4,
    Another = -1
};
enum class CatType                  //������������ ������������ �����
{
    Kitty,
    Little,
    Average,
    Big
};
enum class CatMood                  //������������ ���������� �����
{
    Bad,
    Nice,
    Play,           //�������
    Painful         //�����������
};
enum class ParadiseObject
{
    ParadiseWings,
    Halo,
    Bible
};
enum class HellObject
{
    HellWings,
    Hooves,
    Horns
};


string PrintDemonCat( HellObject demon );
string PrintAngelCat( ParadiseObject angel );
string PrintNormalCat( CatBreed breed );
string PrintCatType( CatType type );
string PrintCatMood(CatMood mood );
string PrintCatColor(CatColorEnum color );


class Cat
{
protected:
    CatColorEnum color;
    CatMood mood;
    CatType type;
    bool Hungry;
    Cat();
public:
    virtual ~Cat() {}
    CatColorEnum GetColor() const {return color; }
    CatMood GetMood() const { return mood; }
    CatType GetType() const {return type; }
    virtual void View() const = 0;          //������� �����
    virtual void Pat() const = 0;           //��������� �����
    bool GetHungry() const;
    void Feed();                            // ��������� �����
    static Cat *Find(CatBreed breed);       //�����(�������) ����� ������������ ������
};

class NormalCats : public Cat
{
private:
    CatBreed Breed;
public:
    CatBreed GetBreed() const {return Breed; }
    NormalCats() : Cat() { type = CatType(rand() % 4);
                           Breed = CatBreed(rand() % 7 - 1);
                           color = CatColorEnum(rand() % 5 - 1);
                           mood = CatMood(rand() % 4);}
    void View() const { cout << "�� �������� ��� ��� ������� ����� � �� ������: "
                        << PrintNormalCat(Breed) << "\n� �����, �� ��������� ��� ��� "
                        << PrintCatType(type) <<  " � ��� ����� �������� " << PrintCatMood(mood) << endl; }
    void Pat() const { cout << "�� ������� ����� �� �� " << PrintCatColor(color) << " �������" << endl; }



};

class HellsCats : public Cat
{

private:
    HellObject demon;
public:
    HellsCats() : Cat() { type = CatType(rand() % 4);
                          demon = HellObject(rand() % 3);
                          color = CatColorEnum::Red;
                          mood = CatMood::Bad;}
    void View() const { cout << "�� �������� ��� ��� ����� ������������ � � ��� ���� �������� ����������: "
                        << PrintDemonCat(demon) << "\n� �����, �� ��������� ��� ��� "
                        << PrintCatType(type) << " � ��� ����� �������� " << PrintCatMood(mood) << endl;}
    void Pat() const { cout << "�� ������� ������ ����� �� �� " << PrintCatColor(color) << " �������, ��� ��� ��������!" << endl; }
};

class ParadiseCats : public Cat
{
private:
    ParadiseObject angel;
public:
    ParadiseCats() : Cat() { type = CatType(rand() % 4);
                             angel = ParadiseObject(rand() % 3);
                             color = CatColorEnum::White;
                             mood = CatMood(rand() % 4);}
    void View() const { cout << "�� �������� ��� ��� ����� ������� � � ��� ���� �������� ����������: "
                        << PrintAngelCat(angel) << "\n� �����, �� ��������� ��� ��� "
                        << PrintCatType(type) << " � ��� ����� �������� " << PrintCatMood(mood) << endl; }
    void Pat() const { cout << "�� ������� ����� �� �� " << PrintCatColor(color) << " �������, �� ������� ��������..." << endl; }

};




//����������
typedef Cat * CatPtr;

//�������� ����� ���������
class BaseContainer                 // ������� ����� ��� ����������
{
protected:
    BaseContainer() {};
public:
    virtual void AddCat(CatPtr newCat) = 0;             // ����������� ����� ��� ���������� ����� � ���������
    virtual int GetCount() const = 0;                   // ����������� ����� ��� ��������� ���������� ����� � ����������
    virtual CatPtr GetByIndex(int index) const = 0;     // ����������� ����� ��� ��������� ����� �� �������
};

//��������
class CatContainerIterator : public Iterator<CatPtr>
{
private:
    const CatPtr *CatBox;           //��������� �� ��������� �� ����� (���.������ ���������� �� �����)
    int Pos;                        //���. �������
    int Quant;                      //����� ���-�� �����

    //��������
public:
    CatContainerIterator(const CatPtr *catBox, int count)
    {
        CatBox = catBox;
        Quant = count;
        Pos = 0;

    }
    void First() { Pos = 0; }
    void Next() { Pos++; }
    bool IsDone() const { return Pos >= Quant; }
    CatPtr GetCurrent() const { return CatBox[Pos]; }
};

//�����-��������� ��� ���������� �����
class CatContainer :  BaseContainer             //��������� � �������
{
private:
    CatPtr *CatBox;                //��������� �� ��������� �� ����� (���.������ ���������� �� �����)
    int CatCount;                  //���������� �����
    int MaxSize;                   //���� ������ ����������
public:
    virtual ~CatContainer();
    CatContainer(int maxSize);
    void AddCat(CatPtr newCat);                 //�������� ����� � �����
    int GetCount() const {cout << "� ������� " << CatCount << " ���������\n"; return CatCount; }    //�������� ����� �����
    CatPtr GetByIndex(int i) const { return CatBox[i]; }    //������������� ����� �� ����� ;)
    Iterator<CatPtr> *GetIterator()
    {
        return new CatContainerIterator(CatBox, CatCount);
    }
};



class MegaCatContainer : public BaseContainer
{
private:
    std::vector<CatPtr> CatBox;
public:
    void AddCat(CatPtr newCat) {CatBox.push_back(newCat); }
    int GetCount() const { return CatBox.size(); };
    CatPtr GetByIndex(int index) const { return CatBox[index]; }

};


#endif // SHELTER_H
