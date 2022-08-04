#include <iostream>
#include <map>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
    Node *any;
    Node(int x = 0) {
        next = NULL;
        any = NULL;
        data = x;
    }
};
map<Node*, Node*> mp;

void display(Node *head) {
    while(head) {
        cout << "node " << head->data << /*" any node " << head->any->data <<*/ "\n";
        head = head->next;
    }
}

Node *createList(Node* temp) {
    Node *head = temp;
    Node * x = NULL;
    Node *HEAD = NULL;
    if(head == NULL) return NULL;
    else{
        HEAD = new Node(head->data);
        mp[head] = HEAD;
        x = HEAD;
    }
    
    while(head->next) {
        x->next = new Node(head->next->data);
        mp[head->next] = x->next; // this wasted my 1 hour of time
        head = head->next;
        x = x->next; 
    }
    head = temp;
    x = HEAD;
    
    while(head) {
        x->any = mp[head->any];
        head = head->next;
        x = x->next;
    }
    
    return HEAD;
    
}

int main() {
	cout<<"GfG!";
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->any = head->next->next;
	head->next->any = head;
	head->next->next->any = head->next;
	
	display(createList(head));
	return 0;
}
