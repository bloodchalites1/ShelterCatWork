#ifndef SHELTER_H
#define SHELTER_H
#include <vector>
#include "Iterator.h"


//КОММИТ 7 Готовые итераторы\\
// Созданы итераторы
enum class CatBreed                 //перечисление пород кошки
{
    MainCoon,
    Russian,
    Sfinks,
    Savanna,
    Persian,
    Munchkin,
    Another = -1
};
enum class CatColorEnum : int       //перечисление окраса кошки
{
    Black = 0,
    White = 1,
    Red = 2,
    Blue = 3,
    Chocolate = 4,
    Another = -1
};
enum class CatType                  //перечисление телосложение кошки
{
    Kitty,
    Little,
    Average,
    Big
};
enum class CatMood                  //перечисление настроения кошки
{
    Bad,
    Nice,
    Play,           //игривая
    Painful         //болезненное
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
    virtual void View() const = 0;          //изучить кошку
    virtual void Pat() const = 0;           //погладить кошку
    bool GetHungry() const;
    void Feed();                            // покормить кошку
    static Cat *Find(CatBreed breed);       //найти(создать) кошку определенной породы
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
    void View() const { cout << "Вы заметили что эта обычная кошка и ее порода: "
                        << PrintNormalCat(Breed) << "\nА также, вы замечаете что это "
                        << PrintCatType(type) <<  " и это кошка выглядит " << PrintCatMood(mood) << endl; }
    void Pat() const { cout << "Вы гладите кошку по ее " << PrintCatColor(color) << " шерстке" << endl; }



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
    void View() const { cout << "Вы заметили что эта кошка демоническая и у нее есть странные конечности: "
                        << PrintDemonCat(demon) << "\nА также, вы замечаете что это "
                        << PrintCatType(type) << " и это кошка выглядит " << PrintCatMood(mood) << endl;}
    void Pat() const { cout << "Вы гладите адскую кошку по ее " << PrintCatColor(color) << " шерстке, она вас обжигает!" << endl; }
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
    void View() const { cout << "Вы заметили что эта кошка райская и у нее есть странные конечности: "
                        << PrintAngelCat(angel) << "\nА также, вы замечаете что это "
                        << PrintCatType(type) << " и это кошка выглядит " << PrintCatMood(mood) << endl; }
    void Pat() const { cout << "Вы гладите кошку по ее " << PrintCatColor(color) << " шерстке, ее шерстка идеальна..." << endl; }

};




    //КОНТЕЙНЕР №1
typedef Cat * CatPtr;
//Основной класс контейнер
class BaseContainer                 // Базовый класс для контейнера
{
protected:
    BaseContainer() {};
public:
    virtual void AddCat(CatPtr newCat) = 0;             // Абстрактный метод для добавления кошки в контейнер
    virtual int GetCount() const = 0;                   // Абстрактный метод для получения количества кошек в контейнере
    virtual CatPtr GetByIndex(int index) const = 0;     // Абстрактный метод для получения кошки по индексу
};

            //ИТЕРАТОР №1
class CatContainerIterator : public Iterator<CatPtr>
{
private:
    const CatPtr *CatBox;   // Указатель на указатель на кошку (динамический массив указателей на кошек)
    int Pos;                // Текущая позиция в контейнере
    int Quant;              // Общее количество кошек в контейнере

public:
    // Конструктор, принимающий указатель на массив указателей на кошек и общее количество кошек
    CatContainerIterator(const CatPtr *catBox, int count)
    {
        CatBox = catBox;
        Quant = count;
        Pos = 0;
    }
    // Метод устанавливает итератор на начало контейнера кошек
    void First() { Pos = 0; }
    // Метод перемещает итератор к следующему элементу контейнера кошек
    void Next() { Pos++; }
    // Метод проверяет, достиг ли итератор конца контейнера кошек
    bool IsDone() const { return Pos >= Quant; }
    // Метод возвращает указатель на текущий объект кошки, на который указывает итератор
    CatPtr GetCurrent() const { return CatBox[Pos]; }
};

            //№1 класс-контейнер для нормальных кошек
class CatContainer :  BaseContainer             //контейнер с кошками
{
private:
    CatPtr *CatBox;                             //указатель на указатель на кошку (дин.массив указателей на кошек)
    int CatCount;                               //количество кошек
    int MaxSize;                                //макс размер контейнера
public:
    virtual ~CatContainer();
    CatContainer(int maxSize);
    void AddCat(CatPtr newCat);                 //добавить кошку в приют
    int GetCount() const {cout << "В коробке " << CatCount << " хвостатых\n"; return CatCount; }    //получить число кошек
    CatPtr GetByIndex(int i) const { return CatBox[i]; }           //пронумеровать кошек их можно ;)
    Iterator<CatPtr> *GetIterator()
    {
        return new CatContainerIterator(CatBox, CatCount);
    }
};

    //ИТЕРАТОР ДЛЯ 2-го КОНТЕЙНЕРА (ВЕКТОР)
class CatContainerIterator2 : public Iterator<CatPtr>
{
protected:
    // Указатель на константный вектор указателей на объекты кошек
    const std::vector<CatPtr> *CatBox;
    std::vector<CatPtr>::const_iterator it;

public:
    CatContainerIterator2(const std::vector<CatPtr> *catBox)
    {
        CatBox = catBox;
        it = catBox->begin();
    }
    // Метод устанавливает итератор на начало контейнера кошек
    void First() { it = CatBox->begin(); }
    // Метод перемещает итератор к следующему элементу контейнера
    void Next() { ++it; }
    // Метод возвращает true, если итератор достиг конца контейнера
    bool IsDone() const { return it == CatBox->end(); }
    // Метод возвращает указатель на текущий объект кошки, на который указывает итератор
    CatPtr GetCurrent() const { return *it; }
};

    // КЛАСС-КОНТЕЙНЕР №2
class MegaCatContainer : public BaseContainer
{
private:
    // Вектор указателей на объекты кошек
    std::vector<CatPtr> CatBox;

public:
    // Метод для добавления кошки в контейнер
    void AddCat(CatPtr newCat) { CatBox.push_back(newCat); }
    // Метод для получения количества кошек в контейнере
    int GetCount() const { return CatBox.size();}
    // Метод для получения кошки по индексу в контейнере
    CatPtr GetByIndex(int index) const { return CatBox[index]; }
    // Метод, возвращающий итератор для контейнера
    Iterator<CatPtr> *GetIterator() { return new CatContainerIterator2(&CatBox);}
};


#endif // SHELTER_H
