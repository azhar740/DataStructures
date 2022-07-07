#include <iostream>
using namespace std;

class A {
    public:
    int x; // 4 bytes
    A() {}
    virtual void func() {} // 4 bytes
};
class B: public A {
    public:
    B() {}
    void func() {} // 4 bytes
    int y; // 4 bytes
};

int main() {
	cout<<"GfG!";
	B b;
	cout << sizeof(b); // 16 bytes
	return 0;
}
