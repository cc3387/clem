#include <iostream>
#include <fstream>
#include <list>
#include <cstring>
using namespace std;

void print_choices(){
cout<<" " <<endl;
cout<< "Please select the following keys for editing ... " <<endl;
cout<< " 'I' for Insert. 'A' For Append. 'M' to move line. 'D' to Delete. 'F' to find lines with specific word. " <<endl;
}

//Print function that will be used
void print_list(list<string> &the_list){

cout<<" " <<endl;
cout<<"Here are the lines that are inputted into the system : " << endl;
	
    int linecount = 1;
	
	for(list<string>::iterator iter=the_list.begin(); iter != the_list.end(); iter ++){
	cout<< *iter << "----- line " << linecount << endl;
	linecount++;
	}
	cout<<" " <<endl;
	cout<<" " <<endl;
}

//Print function that will be used
void print_list_ga(list<string> &the_gettysburg_address){
 int linecount = 1;
 string temp1;
 cout<< " " <<endl;
 cout<< "Here are the lines that contains 'dead' word in the Gettysburg Address : " << endl;
 cout<< " " <<endl;
 list<string>::iterator iter; 
	 for(iter = the_gettysburg_address.begin(); iter != the_gettysburg_address.end(); iter++){
	 temp1 = *iter;
	 if(temp1.find("dead") != string::npos){
	 cout << "Line " << linecount << " " << *iter << endl; 
	 cout<< " " <<endl;
	 }
	 linecount++;
	 }
}



//Insert function to be used for the list
void insert_list(list<string> &the_list){
	string temp;
	int position;
	cout<<"Enter the position you want to insert the new text line : "<<endl;
	cin >> position;
	cout<<"Enter textline that you want to insert at the position : "<<endl;
	cin >> temp;
	getline(cin,temp);
	
	list<string>::iterator iter1 = the_list.begin();
	for(int i=0; i<position; i++){
	++iter1;
	}
	the_list.insert(iter1, temp); //insert into the iterated position
}

//Append function to be used for the list
void append_list(list<string> &the_list){
string temp2;
cout<<" " <<endl;
cout<<"Please enter the sentence that you want to append to the last of the list. " <<endl;
cin >> temp2;
getline(cin, temp2);

	list<string>::iterator iter;
	for(list<string>::iterator iter2 = the_list.begin(); iter2 != the_list.end(); ++iter2){
	iter = iter2;
	}

	the_list.insert(iter, temp2);
}

//Move function to be used for the list
void Move_list(list<string> &the_list){
int position;
int final_position;
cout<<" " <<endl;
cout<<"Enter the sentence's position that you want move from: " <<endl;
cin >> position;
cout<<"Enter the final position that you want to move to: " <<endl;
cin >>final_position;

    
	list<string>::iterator iter = the_list.begin();
	list<string>::iterator iter2 = the_list.begin();
	
	for(int i=0; i<position; i++){
	iter++;
	}

	for(int i=0; i<final_position-1; i++){
	iter2++;
	}

	if(position > the_list.size() || final_position > the_list.size()){
	throw 'c';
	}else{
	the_list.insert(iter2, *iter);
	the_list.erase(iter);
	}
}

//Delete the line at a specific position
void Delete_list(list<string> &the_list){
int position;
int final_position;
cout<<" " <<endl;
cout<<"Enter the sentence's position that you want delete from: " <<endl;
cin >> position;
    
	list<string>::iterator iter = the_list.begin();
	
	for(int i=0; i<position; i++){
	iter++;
	}

	if(position > the_list.size()){
	throw 'c';
	}else{
	the_list.erase(iter);
	}
}


//Find lines containing target word dead
void Find_list(list<string> &the_gettysburg_address){
	 string temp, temp1, term;
	 int linecount = 1;
	 ifstream address("Gettysburg_Address.txt");
	 while(address.good()){
	 getline(address, temp);
	 the_gettysburg_address.push_back(temp);
	 }
	 address.close();
	 
	 list<string>::iterator iter; 
	 print_list_ga(the_gettysburg_address);

}

//Define compare case so that the sort does not have Case differences
bool compare(const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

int main(){

	list<string> txteditor;
	list<string> gettysburg_address;
	string temp, end("#");
	char ans, ans1;

	cout<<" " <<endl;
	cout << "Please enter the lines you want to input in : " << endl;
	while(txteditor.size() < 40 && temp.find(end)){
	getline(cin,temp);
	txteditor.push_back(temp);
	}


	/*Start performing edits*/
		
	do{
	print_list(txteditor);	
	print_choices();
	cin >> ans;

	switch (ans)
	{
	
	{case 'I':
     insert_list(txteditor);
     break;
 	}
	
	{case 'A':
	append_list(txteditor);
	break;
	}

	{case 'M':
	try{
	Move_list(txteditor);
	}
	catch(char c){
	cout << "The position exceeds list length.. " <<endl;
	}
	break;
	}
	
	{case 'D':
	try{
	Delete_list(txteditor);
	}
	catch(char c){
	cout << "The position exceeds list length.. " <<endl;
	}
	break;
	}
	
	{case 'F':
	Find_list(gettysburg_address);
	break;
	}

	}
	
	cout<<"Quit ? (Press Q to quit, Any Key to continue)" << endl;
	cin >> ans1;

	}while(ans1 != 'Q' || ans1 != 'q');
	

	//Print out the list of final edited text
	print_list(txteditor);
	print_list_ga(gettysburg_address);

	txteditor.sort(compare);
	print_list(txteditor);

	return 0;
}
