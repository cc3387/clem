#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;

int main(){

   char *head;
   char *tail;
   
   string str;

   cout << "Please enter the input that you want to inverse: "<<endl;
   cin >> str;   

   int length = str.length()-1;
   
   char word_array[length + 1];

   for (int i = 0; i <= length; i++){
   word_array[i] = str[i];
   }
   
   for (int i = 0; i <= length-i; i++){
   *head = word_array[i];
   *tail = word_array[length-i];
   
   word_array[i] = *tail;
   word_array[length-i] = *head;
   }

   cout << "The word entered inverse is: ";

   for (int i = 0; i <= length; i++){
   cout << word_array[i];
   }
}