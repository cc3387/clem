/********************************
[In] : Pounds, Minutes, Activities
[Out] : Total Calories Burnt for each Activity
*********************************/

#include <iostream>
#include <cmath>

using namespace std;

inline float TotalCal(float weight, float time, int METS){
float TotalCalories;
TotalCalories = 0.0175 * weight * time * METS;
return TotalCalories;
}

inline float WKilo(float weightpound){
float weightkil;
weightkil = weightpound/2.2;
return weightkil;
}

int main() {

	float weightpound;
	float weightkilo;
	float minutes;
	
	cout << "Enter your weights in pound: " << endl;
	cin >> weightpound;
	cout << "Enter exercise time in minutes: " << endl;
	cin >> minutes;
	weightkilo = WKilo(weightpound);
	cout << "Total Calories Burned For Running 6 MPH is: " << TotalCal(weightkilo, minutes, 10) << endl;
	cout << "Total Calories Burned For Basketball is: " << TotalCal(weightkilo, minutes, 8) << endl;
	cout << "Total Calories Burned For Sleeping is: " << TotalCal(weightkilo, minutes, 1) << endl;
	cout << "Exiting Program ... " << endl;
	return 0;
}