#include <iostream>
#include <vector>
#include <map>
using namespace std;

void add_count(map<int,int> &the_map, int loc){

	char flag = 'c';

	if(loc >= 0 && loc < 100){
	the_map[loc] += 1;
	}
	else if(loc > 100){
	the_map[101] +=1;
	}
	else if(loc < 0 && loc != -1){
	the_map[102] +=1;
	}
}

void Histogram(int arr[], int size){

    for(int i=0; i<size; i++){
	int count = arr[i];
	if(i < 10){
	cout<< 10*i << " to " << 10*(i+1) << " |";
	}
	else if (i == 10){
	cout << "Greater than 100 " << " | ";
	}
	else if (i == 11){
	cout << "     Less than 0 " << " | ";
	}
	
	for(int j=0; j < count; j++){
	cout << "*";
	}
	cout << " " << endl;
	}
}




int main(){

	//Create the final bucket array
	int stat_table[12]; 
	int gradetable[102];
	int enter_grade;

	vector<int> classgrade;
	map<int, int> grades;
	
	for(int i=0; i<12; i++){
	stat_table[i] = 0;
	}

	for(int i=0; i<102; i++){
	gradetable[i] = i;
	}


	//Map grades to count
	for(int i=0; i < 102; i++){
	grades[i] = 0;
	}
	
	while(enter_grade != -1){
	cout << "Please enter the grade of student ... " << endl;
	cin >> enter_grade;
	classgrade.push_back(enter_grade);
	add_count(grades, enter_grade);
	
	if(enter_grade != -1 && enter_grade >=0 && enter_grade < 100){
	gradetable[enter_grade] = 1; 
	}
	else if(enter_grade > 100){
	gradetable[101] = 1;
	}else if(enter_grade < 0 && enter_grade != -1){
	gradetable[102] = 1;
	}

	}

	cout<<"The size is: "<<classgrade.size()<<endl;
	cout<<" "<<endl;

	cout<<"The list for initial entered grade is : " << endl;
	for(int i=0; i < classgrade.size(); i++){
	if(classgrade[i]>=0 && classgrade[i] < 100){
	cout << "Count of " << classgrade[i] << " is: " << grades[classgrade[i]] << endl; //Map all the grades entered in the vector into buckets
	}
	else if(classgrade[i] > 100){
	cout << "Count of > 100 is : " << grades[101] <<endl; 
	}
	else if(classgrade[i] < 0){
	cout << "Count of < 0 is : " << grades[102] <<endl; 
	}

	}


	for(int i=0; i < classgrade.size(); i++){

	if(classgrade[i] >= 0 && classgrade[i] < 10 && gradetable[classgrade[i]] == 1){
	stat_table[0] += grades[classgrade[i]];
	gradetable[classgrade[i]] -= 1;
	}
	else if(classgrade[i] >= 10 && classgrade[i] < 20 && gradetable[classgrade[i]] == 1){
	stat_table[1] += grades[classgrade[i]];
	gradetable[classgrade[i]] -= 1;
	}
	else if(classgrade[i] >= 20 && classgrade[i] < 30 && gradetable[classgrade[i]] == 1){
	stat_table[2] += grades[classgrade[i]];
	gradetable[classgrade[i]] -= 1;
	}
	else if(classgrade[i] >= 30 && classgrade[i] <40 && gradetable[classgrade[i]] == 1){
	stat_table[3] += grades[classgrade[i]];
	gradetable[classgrade[i]] -= 1;
	}
    else if(classgrade[i] >= 40 && classgrade[i] <50 && gradetable[classgrade[i]] == 1){
	stat_table[4] += grades[classgrade[i]];
	gradetable[classgrade[i]] -= 1;
	}
	else if(classgrade[i] >= 50 && classgrade[i] <60 && gradetable[classgrade[i]] == 1){
	stat_table[5] += grades[classgrade[i]];
	gradetable[classgrade[i]] -= 1;
	}
	else if(classgrade[i] >= 60 && classgrade[i] <70 && gradetable[classgrade[i]] == 1){
	stat_table[6] += grades[classgrade[i]];
	gradetable[classgrade[i]] -= 1;
	}
	else if(classgrade[i] >= 70 && classgrade[i] <80 && gradetable[classgrade[i]] == 1){
	stat_table[7] += grades[classgrade[i]];
	gradetable[classgrade[i]] -= 1;
	}
	else if(classgrade[i] >= 80 && classgrade[i] <90 && gradetable[classgrade[i]] == 1){
	stat_table[8] += grades[classgrade[i]];
	gradetable[classgrade[i]] -= 1;
	}
	else if(classgrade[i] >= 90 && classgrade[i] <100 && gradetable[classgrade[i]] == 1){
	stat_table[9] += grades[classgrade[i]];
	gradetable[classgrade[i]] -= 1;
	}
	else if(classgrade[i] > 100 && gradetable[101] == 1){
	stat_table[10] += grades[101];
	gradetable[101] -= 1;
	}
	else if(classgrade[i] < 0 && classgrade[i] !=1 && gradetable[102] == 1){
	stat_table[11] += grades[102];
	gradetable[102] -= 1;
	}

	}
	
	cout<<" " << endl;
	cout<<"The bucketed list is as follow : " << endl;
	for(int i=0; i < 12; i++){
	if(i >= 0 && i <10){
	cout << "Count of bucket " << 10*(i) << " to " << 10*(i+1) << " is: " << stat_table[i] << endl; //Map all the grades entered in the vector into buckets
	}
	else if (i == 10){
	cout << "Count of bucket " << " > 100 is: " << stat_table[10] << endl;
	}
	else if (i == 11){
	cout << "Count of bucket " << " < 0 is: " << stat_table[11] << endl;
	}
	}
	
	cout<<" " << endl;
	cout<<"The graphical representation is as follow : " << endl;
	//Print the information with graphical features
	Histogram(stat_table,12);
		
	cout<<"Deleting the vector ..." << endl;
	while(!classgrade.empty()){
	classgrade.pop_back();
	}

	return 0;

}
