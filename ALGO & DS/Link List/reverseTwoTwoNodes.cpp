#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
    public:
        Node(int x = 0){
            data = x;
            next = NULL;
        }
};

void reverse(Node * head) {
    if(!head) return;
    while(head && head->next) {
        int d = head->data;
        head->data = head->next->data;
        head->next->data = d;
        head = head->next->next;
        if(head == NULL) return;
        
    }
}
void display(Node *head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
	cout<<"GfG!";
	Node * head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	reverse(head);
	display(head);
	return 0;
}