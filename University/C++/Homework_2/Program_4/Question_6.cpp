#include<iostream>
#include<cmath>
using namespace std;

//Function Declaration
double averagescores(double s1, double s2, double s3, double s4);
double stdscores(double s1, double s2, double s3, double s4, double avescore);


//Functions
double averagescores(double s1, double s2, double s3, double s4){
double avescore;
avescore = (s1 + s2 + s3 + s4) / 4;
return avescore;
}

double stdscores(double s1, double s2, double s3, double s4, double avescore){
double stds;
stds = sqrt(pow((s1-avescore),2.0) + pow((s2-avescore),2.0) + pow((s3-avescore),2.0) + pow((s4-avescore),2.0));
return stds;
}

int main(){

double score_1;
double score_2;
double score_3;
double score_4;
double averagescore;
char ans;

do {
cout << "Please Enter the first score: " << endl;
cin >> score_1 ;
cout << "Please Enter the second score: " << endl;
cin >> score_2 ;
cout << "Please Enter the third score: " << endl;
cin >> score_3 ;
cout << "Please Enter the fourth score: " << endl;
cin >> score_4 ;
averagescore = averagescores(score_1, score_2, score_3, score_4);
cout << "The average score of the 4 scores input is: " << averagescore ;
cout << "\n";
cout << "The standard deviation of the 4 scores input is: " << stdscores(score_1, score_2, score_3, score_4, averagescore);
cout << "\n";
cout << "Repeat program? (y/n)" << endl;
cin >> ans;
} while (ans =='y' || ans == 'Y');

cout<<"Exiting Program..."<<endl;
return 0;

}