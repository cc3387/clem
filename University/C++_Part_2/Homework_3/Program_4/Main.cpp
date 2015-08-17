#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double average(int arr[], int size){

	double ave = 0;

	for(int i=0; i<size; i++){
	ave += arr[i];
	}

	ave /= size;
	return ave;
}

int main(){

	char a,b,c;
	string temp;
	int number_of_lines;
	int n = 1; //count of lines
	int n1 = 0; //count of space
	int k = 0; //count of names
	int k1 = 0; //count of scores
	int temp1;

    ifstream Instream("Grades.txt"), Instream_1("Grades.txt");
	
	//Check if Grade file is open
    if(Instream.is_open()){
	cout<<"The Stream is Opened..."<<endl;
	}else{
	cout<<"There is no file to open..."<<endl;
	exit(1);
	}
	
	while(!Instream.eof()){ // Counter the number of lines
	getline(Instream, temp);
	n++;
	}
	
	cout<<"The number of lines is: " << n << endl;

	Instream.close();

	char last_name[n][15];
	char first_name[n][15];
	int  score_arr[n][10];
	double ave[n];

	
	//Initializing all the names array
	for(int i=0; i<n; i++){
		for(int j=0; j< 15; j++){
		last_name[i][j] = ' ';
		first_name[i][j] = ' ';
		}
	}

	//Initializing all the scores array
	for(int i=0; i<n; i++){
		for(int j=0; j< 10; j++){
		score_arr[i][j];
		}
	}


	//Check if Grade file is open
    if(Instream_1.is_open()){
	cout<<"The Stream is Opened..."<<endl;
	}else{
	cout<<"There is no file to open..."<<endl;
	exit(1);
	}

	n=0;

	//Intake of words and lines
	while(!Instream_1.eof()){ // Counter the number of lines
	a = Instream_1.get();
	//cout << "a is:" << a << endl;
	
	if(a != ' ' && n1 == 0){
	last_name[n][k] = a;
	k++;
	}
	else if(a != ' ' && n1 == 1){
	first_name[n][k] = a;
	k++;
	}
	else if(a != ' ' && n1 > 1){
	b = Instream_1.get();
	c = Instream_1.get();

	//cout << "b is:" << b << endl;
	//cout << "c is:" << c << endl;

	if(c != ' '){
	temp1 = 100;
	score_arr[n][k1] = temp1;
	k1++;
	n1+=1;
	}
	else{
	temp1 = a - '0';
	temp1 *=10;
	temp1+= (b - '0');
	//cout<<temp1<<endl;
	score_arr[n][k1] = temp1;
	k1++;
	}
	}
	
	if(a == '#'){
	n+=1;
	n1 = 0;
	k1 = 0;
	k = 0;
	}
	else if(a == ' '){
	//Reset all the arrays back to starting point
	n1 += 1;
	k = 0;
	}
	}
	

	//Updating the average scores into the average array
	for(int i = 0; i < n; i++){
	   ave[i] = average(score_arr[i], 10);
	}

	//Output informationa to new file
	ofstream Outfile("Grades_Output.txt");

	for(int i=0; i<n; i++){
	
		for(int j=0; j<15; j++){
		if(last_name[i][j] == ' ' && j !=14){
		Outfile << "";
		}else if(last_name[i][j] == ' ' && j ==14){
        Outfile << " ";
		}
		else{
		Outfile << last_name[i][j];
		}
		}

		for(int j=0; j<15; j++){
		if(first_name[i][j] == ' '){
		Outfile<<"";
		}else if(first_name[i][j] == ' ' && j ==14){
        Outfile << " ";
		}
		else{
		Outfile<< first_name[i][j];
		}
		}

		for(int j=0; j<10; j++){
		Outfile <<" " << score_arr[i][j] << ",";
		}

		Outfile << "Average of the student is: " << ave[i] << "." << endl;
	}

	Instream_1.close();

	return 0;
}