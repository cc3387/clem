#include<iostream>
#include<cmath>
using namespace std;

const float R=10;
const double D=20;
const float H=20;
const double PI = 3.14159265359;


//Class that define all the variables and methods
class CylinderCalc{

private:
	float radius;
	float height;
	double diameter;

public:
	float SurfaceArea(float,float);
	float SurfaceArea(double,double);
	float Perimeter_Cylinder(float,float);
	float Perimeter_Cylinder(double,float);
	float Volume_Cylinder(float,float);
	float Volume_Cylinder(double,float);
};


//Class Methods Definitions

float CylinderCalc::SurfaceArea(float r, float h){
radius = r;
height = h;
float Top_Bottom = 2 * PI * radius * radius;
float circumference = 2 * PI * radius;
float cylinderarea = circumference * height;
float Total_Surfacearea = Top_Bottom + cylinderarea;
return Total_Surfacearea;
}

float CylinderCalc::SurfaceArea(double d, double h=10){
diameter = d;
height = h;
float Top_Bottom = 2 * PI * pow(diameter/2,2.0);
float circumference = 2 * PI * (diameter/2);
float cylinderarea = circumference * height;
float Total_Surfacearea = Top_Bottom + cylinderarea;
return Total_Surfacearea;
}

float CylinderCalc::Perimeter_Cylinder(float r, float h){
radius = r;
height = h;
float perimeter_circles = 2*(2*PI*radius);
float perimeter_body = (2*PI*radius + height)*2;
float perimeter_total = perimeter_circles + perimeter_body;
return perimeter_total;
}

float CylinderCalc::Perimeter_Cylinder(double d, float h){
diameter = d;
height = h;
float perimeter_circles = 2*(2*PI*(diameter/2));
float perimeter_body = (2*PI*(diameter/2) + height)*2;
float perimeter_total = perimeter_circles + perimeter_body;
return perimeter_total;
}

float CylinderCalc::Volume_Cylinder(float r, float h){
radius = r;
height = h;
float volume = PI * radius * radius * height;
return volume;
}

float CylinderCalc::Volume_Cylinder(double d, float h){
diameter = d;
height = h;
float volume = PI * pow(diameter/2,2.0) * height;
return volume;
}


int main(){
	CylinderCalc CC;
	cout<<"Surface area with float r and float h is: "<<CC.SurfaceArea(R,H)<<endl;
	cout<<"Surface area with double d and double h=10 is: "<<CC.SurfaceArea(D)<<endl;
	cout<<"Perimeter with float r and float h is: "<<CC.Perimeter_Cylinder(R,H)<<endl;
	cout<<"Perimeter with double d and float h is: "<<CC.Perimeter_Cylinder(D,H)<<endl;
	cout<<"Volume with float r and float h is: "<<CC.Volume_Cylinder(R,H)<<endl;
	cout<<"Perimeter with double d and float h is: "<<CC.Volume_Cylinder(D,H)<<endl;
	cout<<"Exiting Program..."<<endl;
	return 0;
}