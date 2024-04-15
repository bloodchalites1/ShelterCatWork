#ifndef SHELTER_H
#define SHELTER_H

//КОММИТ 1 Созданы Классы и Перечисления\\
//

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
enum class ParadiseObject //ангельские перечисления частей тел для кошки
{
    ParadiseWings,
    Halo,
    Bible
};
enum class HellObject //адские перечисления частей тел для кошки
{
    HellWings,
    Hooves,
    Horns
};

class Cat
{
protected:
    CatColorEnum Color;
    CatMood Mood;
    bool Hungry;
    Cat();
public:
    virtual ~Cat() {}
    CatColorEnum GetColor() const {return Color; }; //узнать цвет
    CatMood GetMood() const { return Mood; }
    bool GetHungry() const;
    //другие методы будут во 2-м коммите

};

class NormalCats : public Cat //нормальные кошки
{
private:
    CatBreed Breed;
public:
    CatBreed GetBreed() const {return Breed; }
    NormalCats() : Cat() { Breed = CatBreed(rand() % 7 - 1);
                           Color = CatColorEnum(rand() % 7 - 1);
                           Mood = CatMood(rand() % 4);}
    //CatMood GetMood() const { return Mood; }

};

class HellsCats : public Cat //демонические кошки
{
private:

public:
    HellsCats() : Cat() { Color = CatColorEnum::Red;
                          Mood = CatMood::Bad;}
};

class ParadiseCats : public Cat //райские кошки
{
private:

public:
    ParadiseCats() : Cat() { Color = CatColorEnum::White;
                             Mood = CatMood(rand() % 4);}
};

#endif // SHELTER_H
