#include <iostream>
#include <list>
using namespace std;

int main() {

list<int> List;
list<int>::iterator iter;

for(int i=0; i < 33; i++){
   List.push_back(i-3);
}

cout << "This is the original list: " << endl;
for(list<int>::iterator iter = List.begin(); iter != List.end(); ++iter){
cout << *iter << endl;	
}

iter = List.begin();

while(iter != List.end()){

if(*iter % 3 == 0){
iter = List.erase(iter);
}
++iter;
}

cout << " " << endl;
cout << "This is the modified list: " << endl;
for(list<int>::iterator iter = List.begin(); iter != List.end(); ++iter){
cout << *iter << endl;	
}

	return 0;
}