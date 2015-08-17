#include <cstddef>
//Define the structure class

struct node{
	int data;
	node *next;
};

node *Head = NULL;

//Define the class that uses data structures
class PushPop{
public:
	void push(int element);
	int pop();
};

void PushPop::push(int element){
	 node *temp = new node();
	 temp -> data = element;
	 temp -> next = Head;
	 Head = temp;
}

int PushPop::pop(){
	int result;
	node *temp = new node();
	result = Head -> data;
	temp = Head -> next;
	delete Head;
	Head = temp;
	return result;
}
