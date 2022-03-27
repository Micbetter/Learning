/*
简单工厂

1.具体工厂
2.抽象产品
3.具体产品

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
Shoes* createShoes(int number)
{
    switch (number)
    {
    case 1:
        return new NikeShoes();
    case 2:
        return new AdidasShoes();
    
    default:
        return NULL;
        break;
    }
}

};