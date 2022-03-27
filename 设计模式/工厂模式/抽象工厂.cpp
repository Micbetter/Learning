/*
抽象工厂

1.具体工厂
2.抽象工厂
3.抽象产品
4.具体产品

一个工厂可以干更多的事情

*/


#include <iostream>
using namespace std;


class Shoes
{
public:
virtual ~Shoes(){};
virtual void Show() = 0;
};

/*********抽象工厂********/
class Clothe
{
public:
virtual ~Clothe(){};
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

/*********抽象工厂********/
class NikeClothe:public Clothe
{
public:
virtual void Show()
{
    cout << "This is nike Clothe" << endl;
}
};

/*********抽象工厂********/
class AdidasClothe:public Clothe
{
public:
virtual void Show()
{
    cout << "This is Adidas Clothe" << endl;
}
};

class Factory
{
public:
virtual ~Factory(){};
virtual Shoes* CreateShoes() = 0;
virtual Clothe* CreateClothe() = 0;/*********抽象工厂********/

};

class NikeFactory:public Factory
{
public:
virtual Shoes* CreateShoes()
{
    return new NikeShoes();
}
/*********抽象工厂********/
virtual Clothe* CreateClothe()
{
    return new NikeClothe();
}
};

class AdidasFactory:public Factory
{
public:
virtual Shoes* CreateShoes()
{
    return new AdidasShoes();
}
/*********抽象工厂********/
virtual Clothe* CreateClothe()
{
    return new AdidasClothe();
}
};