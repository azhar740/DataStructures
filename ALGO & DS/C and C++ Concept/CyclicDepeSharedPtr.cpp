#include <iostream>
#include <memory>
using namespace std;


class Node {
    public:
    int data;
    weak_ptr<Node> next;
    Node(int x) {
        data = x;
        //next = NULL;
    }
    ~Node(){
        cout << "Destructor called\n";   
    }
};

int main() {
	cout<<"GfG!";
	shared_ptr<Node> p1(new Node(5));
	shared_ptr<Node> p2(new Node(10));
	//p1->next = p2;
	//p2->next = p1;
	
	return 0;
}