#ifndef ITEM_SET_H
#define ITEM_SET_H

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <cstring>

using namespace std;


template <class T>
class set_item{

private:

	T *items;
	int size;

public:

	set_item();
	set_item(int the_size);
	set_item(const set_item &st);
	~set_item();

	//Setters and getters
	void add_new_item(T the_item);
	int get_num_items() const;
	void show_items() const;
};

#endif