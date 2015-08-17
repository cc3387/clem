#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Studentinfo{

    string name;
    int grade;

    Studentinfo(string the_name, int the_grade) : name(the_name), grade(the_grade){};
};

struct name_ascend{

    bool operator()(const Studentinfo &rhs, const Studentinfo &lhs){
    return (rhs.name < lhs.name);
    };

};

struct name_descend{

    bool operator()(const Studentinfo &rhs, const Studentinfo &lhs){
    return (rhs.name > lhs.name);
    };
};


int max_grade(vector<Studentinfo> &arr, int size){

int max_grade = 0;
int temp_grade; 
int i = 0;

while(i < size){
	
	temp_grade = arr[i].grade;
	
	if(max_grade == 0){
	max_grade = temp_grade;
	}
	else if(temp_grade > max_grade){
	max_grade = temp_grade;
	}
i++;
	
}

return max_grade;
}

int min_grade(vector<Studentinfo> &arr, int size){

int min_grade;
int temp_grade; 
int i = 0;

while(i < size){
	
	temp_grade = arr[i].grade;
	
	if(i == 0){
	min_grade = temp_grade;
	}
	else if(temp_grade < min_grade){
	min_grade = temp_grade;
	}
i++;
	
}

return min_grade;
}


double average_grade(vector<Studentinfo> &arr, int size){

double ave_grade = 0;
int temp_grade; 
int i = 0;

while(i < size){

	temp_grade = arr[i].grade;
	ave_grade += temp_grade;
	i++;

}

return ave_grade / size;
}


int main() {
		
	vector<Studentinfo> StudInf;

	StudInf.push_back(Studentinfo("Clement",80));
	StudInf.push_back(Studentinfo("Portia",100));
	StudInf.push_back(Studentinfo("Mike",60));
	StudInf.push_back(Studentinfo("John",100));
	StudInf.push_back(Studentinfo("Alex",50));
	StudInf.push_back(Studentinfo("Mary",85));	

	sort(StudInf.begin(), StudInf.end(), name_descend());

	int size = StudInf.size();
	cout << "The size of the vector is: " << size << endl;
	cout << "The Maximum Grade of the whole list is: " << max_grade(StudInf, size) << endl;
	cout << "The Minimum Grade of the whole list is: " << min_grade(StudInf, size) << endl;
	cout << "The Average Grade of the whole list is: " << average_grade(StudInf, size) << endl;
	
	
	cout << "The Full List of Grade is: " << endl;
	while(!StudInf.empty()){
	cout<<StudInf.back().name<<" "<< StudInf.back().grade<<endl;
	StudInf.pop_back();
	}

		
	return 0;
}