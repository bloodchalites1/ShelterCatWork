#ifndef SHELTER_H
#define SHELTER_H

//КОММИТ 2 АТРИБУТЫ обьектов класса\\
//создан оператор switch с вытекющим case
// они будут необходимы для общих действий над обьектами


enum class CatBreed //перечисление пород кошки
{
    MainCoon,
    Russian,
    Sfinks,
    Savanna,
    Persian,
    Munchkin,
    Another = -1
};
enum class CatColorEnum : int //перечисление окраса кошки
{
    Black = 0,
    White = 1,
    Red = 2,
    Blue = 3,
    Chocolate = 4,
    Another = -1
};
enum class CatType //перечисление телосложение кошки
{
    Kitty,
    Little,
    Average,
    Big
};
enum class CatMood //перечисление настроения кошки
{
    Bad,
    Nice,
    Play, //игривая
    Painful //болезненное
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
//печатающая функция
string PrintDemonCat( HellObject demon );
string PrintAngelCat( ParadiseObject angel );
string PrintNormalCat( CatBreed breed );

string PrintCatType( CatType type );

class Cat
{
protected:
    CatColorEnum Color;
    CatMood Mood;
    CatType type;
    bool Hungry;
    Cat();
public:
    virtual ~Cat() {}
    CatColorEnum GetColor() const {return Color; }; //узнать цвет
    CatMood GetMood() const { return Mood; } //узнать настроение кошки
    bool GetHungry() const;
};

class NormalCats : public Cat
{
private:
    CatBreed Breed;
public:
    CatBreed GetBreed() const {return Breed; }
    NormalCats() : Cat() { Color = CatColorEnum(rand() % 7 - 1);
                           Mood = CatMood(rand() % 4);}
    //CatMood GetMood() const { return Mood; }

};

class HellsCats : public Cat
{
private:
    HellObject demon;
public:
    HellsCats() : Cat() { Color = CatColorEnum::Red;
                          Mood = CatMood::Bad;}

};

class ParadiseCats : public Cat
{
private:
    ParadiseObject angel;
public:
    ParadiseCats() : Cat() { Color = CatColorEnum::White;
                             Mood = CatMood(rand() % 4);}
};

#endif // SHELTER_H
