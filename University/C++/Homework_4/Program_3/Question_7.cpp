#include "Stacks_Class.h"
#include <iostream>
#include <stdio.h>
using namespace std;

//Define global variablses and Arrays
int count_scores[] = {0,0,0,0,0,0};
int count_students = 0;


void EnterScores(int &scs);
void InsertBucket(int &scs);
void Output(int a[]);


int main(){

char ans;
int scores;

//Calling the stack class
PushPop PP;

do{
EnterScores(scores);
PP.push(scores);
InsertBucket(scores);
cout<<"Is this the whole list ? (y/n)" << endl;
cin >> ans;
} while(ans == 'n' || ans == 'N');

//Displaying inputed scores

int student_s[count_students];

for(int i = (count_students -1) ; i >= 0 ; i--){
student_s[i] = PP.pop();
}

for (int i = 0; i < count_students ; i++){
cout << "Student " << i + 1 << " score is " << student_s[i] << endl;
}

//Displaying count statistics
Output(count_scores);
}

void EnterScores(int &scs){
cout << "Please enter the student's score (0-5): " << endl;
cin >> scs;

if(scs > 5 || scs < 0){
printf("Please Re-enter");
exit(0);
}
count_students++;
}

void InsertBucket(int &scs){
count_scores[scs] += 1;
}

void Output(int a[]){

for (int i = 0; i < 6 ; i++){
cout << a[i] << " grade(s) of " << i << endl;
}


}