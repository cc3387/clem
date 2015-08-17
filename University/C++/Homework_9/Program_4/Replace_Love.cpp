#include <iostream>
#include <string>
using namespace std;

int main(){

//Define string for the input
string Line;
//Define char array for the changes
char Line1[Line.length()];
cout << "Please enter the line that you want to evaluate: " <<endl;
getline(cin, Line);

//Inputting string values into the character array
for(int i = 0; i < Line.length(); i++){
Line1[i] = Line[i];
}

for(int i = 0; i < Line.length(); i++){

int finaloutput = (i + 5);

//Replace at the sentence's beginning
if(Line[0] != ' ' && Line[1] != ' ' && Line[2] != ' ' && Line[3] != ' ' && Line[4] == ' '){
Line1[0] = 'L';
Line1[1] = 'o';
Line1[2] = 'v';
Line1[3] = 'e';
}

//Replace at the middle sentence
if((Line[i] == ' ' || Line[i] == '.' || Line[i] == '\n') && Line[i+1] != ' ' && Line[i+2] != ' ' && Line[i+3] != ' ' && Line[i+4] != ' ' && Line[i+5] == ' '){
if(Line[i] == '.' || Line[i] == '\n'){
Line1[i+1] = 'L';
Line1[i+2] = 'o';
Line1[i+3] = 'v';
Line1[i+4] = 'e';
}else{
Line1[i+1] = 'l';
Line1[i+2] = 'o';
Line1[i+3] = 'v';
Line1[i+4] = 'e';
}
}

if((Line[i] == ' ' || Line[i] == '.' || Line[i] == '\n') && Line[i+1] != ' ' && Line[i+2] != ' ' && Line[i+3] != ' ' && Line[i+4] != ' ' && finaloutput == Line.length()){
Line1[i+1] = 'l';
Line1[i+2] = 'o';
Line1[i+3] = 'v';
Line1[i+4] = 'e';
}
}

//Displaying the original Line below
cout<<"The input line is: ";
for(int i = 0 ; i < Line.length(); i++){
cout << Line[i];
}

cout<< " " << endl;

cout<<"The replaced line is: ";
//Displaying the replaced line below
for(int i = 0; i < Line.length(); i++){
cout << Line1[i];
}


return 0;

}