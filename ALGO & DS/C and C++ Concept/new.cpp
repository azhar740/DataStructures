

class A {
public:
	virtual void show () {
		cout << "I am in show\n";
	}

	void print () {
		cout << "I am in print\n";
	}
	 ~A(){}

};

class B : public A {
public:
	void show() {
		cout << "B's show\n";
	}
	void print() {
		cout << "B's print\n";
	} 
	~B() {}
};


int main() {
	try {

	

	shared_ptr<A> bp1 = make_shared<B>();
	unique_ptr<A> bp2 = make_unique<B>();
	bp2 = bp1;

	bp3;

	bp3 = bp2
	A *bp = new B();

	delete bp;
	//bp->show();// found some exception

	shared_ptr<A> bp3 = make_shared<B>();
	unique_ptr<A> bp4 = make_unique<B>();
	catch {

	}
	delete bp;
}



vector<int> vec = {1, 2, 3, 4, 5} ;
for_each(vec.begin(), vec.end(), [&](int a){
	a = a*5;
}
); 


[](vector<int> vec) {
	for(int i = 0; i < vec.size(); i++) {
		vec[i] *= 5;
	}
	return vec;
}



1->2 ->3 ->4 -> 5
2 -> 1 -> 4->3 ->5

void swap(Node **ptr1, Node **ptr2) {
	Node *temp = *ptr1->data;
	*ptr1->data = *ptr2->data;
}

Node* reverse(Node *head, int cnt) {
	Node *curr = head;
	
	while(curr->next) {
		next = curr->next;
		swap(&curr, &next);
	}

	
} 

t1--tn

abc() {
	
}