#include <iostream>
#include <cmath>
using namespace std;

//Global Variables;

static const int daysMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};
static const int monthsYear = 12;

class Date{

private:

    int day;
    int month;
    int year;
    int *date;


public:
    
    //Constructors and Destructors

    Date(); //Default Constructors
    Date(int, int, int); //Parametric Constructors
    Date(const Date &D); //Copy Constructor
    ~Date(); //Destructors  

    //mutators & accessors
    int getDays() const;
    int getMonth() const;
    int getYear() const;
    void DisplayDate() const; //Show Days, Months and Years
    int calcDiff(const Date &Today);
    
    //Operator overload
    Date& operator = (const Date &D);
};