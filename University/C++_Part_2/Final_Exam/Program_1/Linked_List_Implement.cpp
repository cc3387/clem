#include<iostream>
#include<cstring>

class List;

//Implementing the class node
class Node{

private:
	std::string  data;
	Node *next;

public:
	
	friend class List;
	
	Node():data("No Fruit Yet"),next(0){}; //Default constructor
	
	Node(std::string the_data): data(the_data), next(0){}; //Parameterized constructor
};




//Implementing the class List
class List{

private:
	int N;
	Node *head;

public:
	List() : head(NULL){}; // Constructor
	
	~List(){ //Destructor
	std::cout<<"Initiating List Destructor ... " <<std::endl;
	Node *q = head;
	int count = 0;

	while(q -> next != NULL){
	Node *temp = q;
	q = q -> next;
	delete temp;
	count ++;
	std::cout<<"Deleted " << count << " Node" << std::endl;
	}

	if(q -> next == NULL){
	delete q;
	count ++;
	std::cout<<"Deleted " << count << " Node" << std::endl;
	}

	};

	//Initialize list and write down some fruits name
	void Define_node(int number){
	int i = 0;
	N = number;
    
	while(i<N){
	Node *temp = new Node();
	temp -> next = head;
	head = temp;
	i++;
	}
	}


	void write_data(std::string thefruit, int pos){
	int i=0;
	Node *p = head;
	while(i < pos){
	p = p -> next;
	i++;
	}
	p -> data = thefruit;
	}


	/***************Inserting and erasing********************/
	//Insert From Front
	void insert_front(std::string fruit){
	if(head == NULL){
	Node *temp = new Node(fruit);
	head = temp;
	}
	else{
	Node *temp = new Node(fruit);
	temp -> next = head;
	head = temp;
	}
	}

	//Insert From Back
	void insert_back(std::string fruit){
	Node *q = head;
	
	while(q -> next != NULL){
	q = q-> next; // Move towards the last node and point towards next
	}
	
	Node *temp = new Node(fruit);
	q -> next = temp;
	}

	//Insert at location x
	void insert_loc(std::string fruit, int pos){
	Node *q = head;
	int count = 0;
	char flag = 'g';

	while(q -> next != NULL && count < pos){
	q = q-> next; // Move towards the last node and point towards next
	count++;
	}
	
	if(q->next == NULL && count < pos){
	throw flag ;
	}
	else{
    Node *temp = new Node(fruit);
	temp -> next = q -> next;
	q -> next = temp;
	}
	}

	//Erase the Node
	void remove_loc(int pos){
	Node *q = head;
	int count = 0;
	char flag = 'g';

	while(q -> next != NULL && count < pos-2){
	q = q-> next; // Move towards the last node and point towards next
	count++;
	}
	
	if(q->next == NULL && count < pos-2){
	throw flag ;
	}
	else{
    Node *temp = new Node(q->next->data);
	temp ->next = q -> next -> next;
	q -> next = temp -> next;
	delete temp;
	}
	}
	

	//Search Function
	int search(std::string fruit){
	Node *q = head;
	int count = 1;
	char flag = 'g';

	while(q -> next != NULL){
	if(q->data != fruit){
	   q = q-> next;
	   count ++;
	}
	else if (q -> data == fruit){
	return count;
	}
	}

	if(q->next == NULL){
	throw flag;
	}

	}


	//Displaying List
	void DisplayList(){
	std::cout<< "The List of Fruit is -- " << std::endl;
	Node *q = head;
	std::cout<< q->data << std::endl;
	while(q -> next != NULL){
	q = q -> next;
	std::cout<<q->data<<std::endl;
	}
	std::cout<< " " << std::endl;
	}


};


int main(){

	List List_fruit;
	List_fruit.Define_node(5);
	List_fruit.write_data("Pineapple",0);
	List_fruit.write_data("Blueberry",1);
	List_fruit.write_data("Pinkberry",2);
	List_fruit.write_data("Laichi",3);
	List_fruit.write_data("Sukini",4);

	//Displaying initial list
	List_fruit.DisplayList();

	
	List_fruit.insert_front("apple");
	List_fruit.insert_front("banana");
	List_fruit.insert_front("grapes");
	List_fruit.insert_back("pears");
	List_fruit.insert_back("mango");
	List_fruit.insert_back("watermelon");

	//Inserting between node location
	try{
	List_fruit.insert_loc("strawberry",3);
	}
	catch(char a){
	std::cout << "Position of entry exceeds List Size" << std::endl;
	std::cout << " " << std::endl;
	}
	
	//Displaying extended list
	List_fruit.DisplayList();

	//Inserting a position that is not possible to test try and catch
	try{
	List_fruit.insert_loc("Orange",10);
	}
	catch(char a){
	std::cout << "Position of entry exceeds List Size" << std::endl;
	std::cout << " " << std::endl;
	}

	//Use the search function defined
	try{
	std::cout<<"Searching for Apple ... " << std::endl;
	std::cout<<"The position for apple is: " << List_fruit.search("apple") << std::endl;
	std::cout << " " << std::endl;
	}
	catch(char a){
	std::cout << "No such fruit -- try again" << std::endl;
	std::cout << " " << std::endl;
	}
	
	//try a position that is impossible
	try{
	std::cout<<"Searching for Kiwi ... " << std::endl;
	std::cout<<List_fruit.search("Kiwi")<<std::endl;
	std::cout << " " << std::endl;
	}
	catch(char a){
	std::cout << "No such fruit -- try again" << std::endl;
	std::cout << " " << std::endl;
	}


	//Erasing between node location
	try{
	List_fruit.remove_loc(2);
	}
	catch(char a){
	std::cout << "Position of entry exceeds List Size" << std::endl;
	std::cout << " " << std::endl;
	}
	
	//Displaying Erased list
	List_fruit.DisplayList();
	
	return 0;
}