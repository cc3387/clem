#include "item_class.h"

template <class T>
set_item <T> :: set_item(){
cout << "This is Default Constructor ... " << endl;
	items = new T[10];
	size = 0;
}

template <class T>
set_item <T> :: set_item(int the_size){
	items = new T[the_size];
	size = the_size;
}

template <class T>
set_item <T> :: set_item(const set_item &s_t){
	size = s_t.get_num_items();
	delete[] items;
	items = new T[size];
}

template <class T>
set_item <T> :: ~set_item(){
cout << "This is Destructor ... " << endl;
delete[] items;
}

template <class T>
void set_item <T> :: add_new_item(T the_item){
items[size] = the_item;
size ++;
}

template <class T>
int set_item <T> :: get_num_items() const{
return size;
}

template <class T>
void set_item <T> :: show_items() const{

	for(int i=0; i<size; i++){
	cout << "The entered items in the set are: " << items[i] << endl;
	}
}

