/*
工厂方法

1.具体工厂
2.抽象工厂
3.抽象产品
4.具体产品

*/


#include <iostream>
using namespace std;


class Shoes
{
public:
virtual ~Shoes(){};
virtual void Show() = 0;
};

class NikeShoes:public Shoes
{
public:
virtual void Show()
{
    cout << "This is nike shoes" << endl;
}
};

class AdidasShoes:public Shoes
{
public:
virtual void Show()
{
    cout << "This is Adidas shoes" << endl;
}
};

class Factory
{
public:
virtual ~Factory(){};
virtual Shoes* CreateShoes() = 0;           /*********工厂方法********/

};

/*********工厂方法********/
class NikeFactory:public Factory
{
public:
virtual Shoes* CreateShoes()
{
    return new NikeShoes();
}
};

/*********工厂方法********/
class AdidasFactory:public Factory
{
public:
virtual Shoes* CreateShoes()
{
    return new AdidasShoes();
}
};