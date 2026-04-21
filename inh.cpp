#include <bits/stdc++.h>
using namespace std;
class A
{
public:
    void cook(){ cout<<"Cooking";}
    void play(){cout<<"play";}
};
class B : public A
{
    public:
void cook(){ cout<<"NOT COOKING";}
};
class C:public B{ };
 int main()
{
    // B b; b.cook();
    C c;
    //  c.cook(); c.play();
    c.A::cook();
}