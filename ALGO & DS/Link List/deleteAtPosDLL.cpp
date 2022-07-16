#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};



void deleteNode(Node **head, Node *del) {
    if(*head == NULL || del == NULL) return;
    
    if(*head == del) *head = del->next;
    if(del->prev != NULL) del->prev->next = del->next;
    if(del->next != NULL) del->next->prev = del->prev;
    
    free(del);
    return;
    
}

void deleteAtPos(Node **head, int pos) {
    if(*head == NULL || pos <= 0) return;
    Node *curr = *head;
    for(int i = 1; curr != NULL && i < pos; i++) {
        curr = curr->next;
    }
    
    if(curr == NULL){
        cout << "Pos is not exist\n";
        return;
    }
    
    deleteNode(head, curr);
}

void push(Node **head, int x) {
    
    Node *temp = new Node(x);
    temp->next = *head;
    if((*head) != NULL) {
        (*head)->prev = temp;
    }
    (*head) = temp;
}

void display(Node *temp) {
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
	Node *head = NULL;
	int pos = 3;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);
	push(&head, 5);
	display(head);
	deleteAtPos(&head, pos);
	display(head);
	return 0;
}
