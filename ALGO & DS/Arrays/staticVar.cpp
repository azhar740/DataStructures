#include <iostream>

using namespace std;

class A{
    private:
        int x;
    public:
        A(){
            cout << "A's constructor called\n";
        }

};

class B{
    static A a;
    static int x;
public:
    B(){
        cout << "B's constructor called\n";
    }

    static A getA(){
        return a;
    }
};

A B::a;

int B::x = 10;

int main()
{
   B b1;
   A a = b1.getA();
   cout << "A's object " << &a << endl;

    return 0;
}