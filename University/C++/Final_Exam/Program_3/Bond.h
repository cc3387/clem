class Bond{

private:

     char *name;
     float value;
     Date purchaseDate;
     Date maturityDate;
     Date Today;

public:

     Bond();
     Bond(char*, float, const Date &D1, const Date &D2);
	 
	 //mutators and accessors
     char* get_name() const;
	 float get_price() const;
	 int getDays(const Date &D)const;
     int getMonth(const Date &D)const;
     int getYear(const Date &D)const;
	 
	 //Calculate the summaries
	 void Display(const Date&D)const;
     void setToday(Date &hoy);
	 int getCalcDiff(const Date &D, const Date &D1);
     int daysToMaturity(Date &D);
	 
};