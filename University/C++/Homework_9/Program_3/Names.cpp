#include <iostream>
#include <string>
using namespace std;

int main(){

string LastName, FirstName, MiddleName;
int count = 0;

char CapLetters[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char Letters[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','y','v','w','x','y','z'};

cout << "Please enter Name (First Name, Middle Name, Last Name, enter '-' if no Middle Name): " << endl;
cin >> FirstName >> MiddleName >> LastName;


// Search for MiddleName's first letter
char Mid_Name_Arr[MiddleName.length()];
char Mid_Name;


for(int i = 0; i < MiddleName.length(); i++){
Mid_Name_Arr[i] = MiddleName[i];
}

for(int i = 0; i < 26; i++){
if(Mid_Name_Arr[0] == Letters[i]){
Mid_Name = CapLetters[i];
}else{
Mid_Name = Mid_Name_Arr[0];
}
}

if(Mid_Name != '-'){
cout << LastName << ", " << Mid_Name << ". " << FirstName << endl;
}else if(Mid_Name == '-'){
cout << LastName << ", " << FirstName << endl;
}

return 0; 
}