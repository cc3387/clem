#include <iostream>
#include <vector>
using namespace std;

const int Max_Size = 10;


int histogram[Max_Size];

void init_hist(){
	for(int i = 0; i < Max_Size ; i++){
	histogram[i] = 0;
	}
}

void Display_Hist_Table(){

int num_of_grades;

for(int i = 0; i < Max_Size ; i++){

	num_of_grades = histogram[i];
    int a = 0;

	if (i == 0){
	cout<<"Score between " << i << " and " << i + 10 << " is|";
	}
	else{
    cout<<"Score between " << i*10 + 1 << " and " << (i+1)*10 << " is|";
	}
	while (a < num_of_grades){
	cout<< "*";
	a++;
	}	
	cout<<" "<<endl;
}

}



int main(){

	int input_grades;
	vector<double> v;
	
	init_hist();

	cout<<"Please Enter the grade of the student from 0 to 100 points, -1 to complete entering: " <<endl;
 	do{
	cin >> input_grades;
	v.push_back(input_grades);
	
	if(input_grades >= 0 && input_grades <= 10){
	histogram[0] += 1;
	}
	else if(input_grades >= 11 && input_grades <= 20){
	histogram[1] += 1;
	}
	else if(input_grades >= 21 && input_grades <= 30){
	histogram[2] += 1;
	}
	else if(input_grades >= 31 && input_grades <= 40){
	histogram[3] += 1;
	}
	else if(input_grades >= 41 && input_grades <= 50){
	histogram[4] += 1;
	}
	else if(input_grades >= 51 && input_grades <= 60){
	histogram[5] += 1;
	}
	else if(input_grades >= 61 && input_grades <= 70){
	histogram[6] += 1;
	}
	else if(input_grades >= 71 && input_grades <= 80){
	histogram[7] += 1;
	}
	else if(input_grades >= 81 && input_grades <= 90){
	histogram[8] += 1;
	}
	else if(input_grades >= 91 && input_grades <= 100){
	histogram[9] += 1;
	}
	else{
	cout<<"Input out of range" << endl;
	cout<<"Exiting input ... " << endl;
	}
	
	}while(input_grades > 0);

	//Displaying the number of students in the class
	cout<<"The size of the class with vector is: " << v.size() - 1 << endl;

	//Displaying the max grade user entered
	cout<<"The max grade entered for the class is: " << *max_element(v.begin(),v.end()) << endl;

	//Displaying the statistics for the grades entered
	for(int i = 0; i < Max_Size; i++){
	if (i == 0){
	cout<<histogram[i]<<" students got between " << i << " and " << i + 10 << endl;
	}
	else{
    cout<<histogram[i]<<" students got between " << i*10 + 1 << " and " << (i+1)*10 << endl;
	}
	}
	cout<< " " << endl;
	
	//Display the histogram
	Display_Hist_Table();

	return 0;

}