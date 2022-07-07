#include <iostream>
using namespace std;
#include <memory>
 
class Rectangle {
    int length;
    int breadth;
 
public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
 
    int area()
    {
        return length * breadth;
    }
};
 
int main()
{
    share_ptr<int> p1; // p1.use_count will be zero
    shared_ptr<int> p2(nullptr); // p2.use_count will be zero
 
    shared_ptr<Rectangle> P1(new Rectangle(10,5));
    // This'll print 50
    cout << P1->area() << endl;
 
    shared_ptr<Rectangle> P2;
    P2 = P1;
 
    // This'll print 50
    cout << P2->area() << endl;
 
    // This'll now not give an error,
    cout << P1->area() << endl;
 
    // This'll also print 50 now
    // This'll print 2 as Reference Counter is 2
    cout << P1.use_count() << endl;
    //P1.get(); P1.reset();
    return 0;
}
