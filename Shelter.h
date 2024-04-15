#ifndef SHELTER_H
#define SHELTER_H

//КОММИТ 4 Общие действия\\
// с помощью команды view выводиться сразу 3 атрибута
//было добавлено действие погладить Pat() а также метод погормить кошку Feed()

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
    //CatMood GetMood() const { return Mood; }
    virtual void View() const = 0;
    virtual void Pat() const = 0; //погладить кошку
    bool GetHungry() const;
    void Feed();
};

class NormalCats : public Cat
{
private:
    CatBreed Breed;
public:
    //CatBreed GetBreed() const {return Breed; }
    NormalCats() : Cat() { type = CatType(rand() % 4);
                           Breed = CatBreed(rand() % 7 - 1);
                           color = CatColorEnum(rand() % 5 - 1);
                           mood = CatMood(rand() % 4);}
    void View() const { cout << "Вы заметили что эта обычная кошка и ее порода: " //изучение кошки
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
    void View() const { cout << "Вы заметили что эта кошка демоническая и у нее есть странные конечности: " //изучение кошки
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
    void View() const { cout << "Вы заметили что эта кошка райская и у нее есть странные конечности: " //изучение кошки
                        << PrintAngelCat(angel) << "\nА также, вы замечаете что это "
                        << PrintCatType(type) << " и это кошка выглядит " << PrintCatMood(mood) << endl; }
    void Pat() const { cout << "Вы гладите кошку по ее " << PrintCatColor(color) << " шерстке, ее шерстка идеальна..." << endl; }

};

#endif // SHELTER_H
