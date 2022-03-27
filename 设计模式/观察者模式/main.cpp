/*
观察者模式：定义一种一（被观察类）对多（观察类）的关系，让多个观察对象同时监听一个被观察对象，被观察对象状态发生变化时，会通知所有的观察对象，使他们能够更新自己的状态。

观察者模式中存在两种角色：

观察者：内部包含被观察者对象，当被观察者对象的状态发生变化时，更新自己的状态。（接收通知更新状态）
被观察者：内部包含了所有观察者对象，当状态发生变化时通知所有的观察者更新自己的状态。（发送通知）
应用场景：

当一个对象的改变需要同时改变其他对象，且不知道具体有多少对象有待改变时，应该考虑使用观察者模式；
一个抽象模型有两个方面，其中一方面依赖于另一方面，这时可以用观察者模式将这两者封装在独立的对象中使它们各自独立地改变和复用。
*/

#include<iostream>
#include<list>
using namespace std;

//被观察者基类
class Subject
{
public:
    virtual ~Subject(){};
    string action;  //状态
    virtual void attach(Observer* ob) = 0;
    virtual void detach(Observer* ob) = 0;
    virtual void notify(Observer* ob) = 0;
protected:
    list<Observer*> observers;
};

//观察者基类
class Observer
{
public:
    virtual ~Observer(){};
    virtual void update() = 0;
    Observer(string name, Subject* sub):name(name),sub(sub){};
protected:
    string name;
    Subject* sub;
};

class FirstObserver:public Observer
{
public:
    FirstObserver(string name, Subject* sub):Observer(name,sub){};
    virtual void update()
    {
        cout << "first observer update." + sub->action << endl;
    }
};

class FisrtSubject:public Subject
{
public:
    virtual void attach(Observer* ob)
    {
        observers.push_back(ob);
    }
    virtual void detach(Observer* ob)
    {
        auto it = observers.begin();
        while (it != observers.end())
        {
            if((*it) == ob)
            {
                observers.erase(it);
                return;
            }
            it++;
        }
    }
    virtual void notify()
    {
        for (auto &ob : observers)
        {
            ob->update();
        }
    }
};