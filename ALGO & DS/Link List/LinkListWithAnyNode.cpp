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
        cout << head->data << " next is " << head->any->data << "\n";
        head = head->next;
    }
}

Node *createList(Node* temp) {
    Node *head = temp;
    Node * x = NULL;
    Node *HEAD = NULL;
    if(!head) return NULL;
    else{
        HEAD = new Node(head->data);
        mp[head] = HEAD;
        x = HEAD;
    }
    head = head->next;
    while(head) {
        HEAD->next = new Node(head->data);
        mp[HEAD->next] = head;
        head = head->next;
        HEAD= HEAD->next; 
    }
    head = temp;
    HEAD = x;
    while(head) {
        HEAD->any = mp[head->any];
        head = head->next;
        HEAD = HEAD->next;
    }
    
    return x;
    
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