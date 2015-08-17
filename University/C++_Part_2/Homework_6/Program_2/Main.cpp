#include "item_class.h"
#include "item_class.cpp"

int main(){

	set_item<int> ST;
	set_item<double> ST_double;
	set_item<string> ST_str;
	set_item<char> ST_char;
	cout<< " " <<endl;

	/********* For Integer ************/
	cout<< "For Integer ... " <<endl;
	ST.add_new_item(3);
	ST.add_new_item(5);
	ST.add_new_item(6);
	ST.add_new_item(15);
	ST.add_new_item(150);
	cout<<"The number of items entered: "<<ST.get_num_items()<<endl;
	ST.show_items();
	cout<< " " <<endl;
	
	/********** For double ************/
	cout<< "For double ... " <<endl;
	ST_double.add_new_item(4.5);
	ST_double.add_new_item(5.111);
	ST_double.add_new_item(2.332);
	ST_double.add_new_item(1.234);
	ST_double.add_new_item(0.5318);
	cout<<"The number of items entered: " << ST_double.get_num_items()<<endl;
	ST_double.show_items();
	cout<< " " <<endl;

	/******** For Strings **********/
	cout<< "For Strings ... " <<endl;
	string a = "hi, how are you?";
	string b = "ok, I am fine";
	string c = "Today is freezing";
	string d = "So hot!";
	ST_str.add_new_item(a);
	ST_str.add_new_item(b);
	ST_str.add_new_item(c);
	ST_str.add_new_item(d);
	cout<<"The number of items entered: " << ST_str.get_num_items()<<endl;
	ST_str.show_items();
	cout<< " " <<endl;

	/******* For char ************/
	cout<< "For char ... " <<endl;
	ST_char.add_new_item('a');
	ST_char.add_new_item('b');
	ST_char.add_new_item('c');
	ST_char.add_new_item('d');
	ST_char.add_new_item('e');
	cout<<"The number of items entered: " << ST_char.get_num_items()<<endl;
	ST_char.show_items();
	cout<< " " <<endl;



	return 0;

}