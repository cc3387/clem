//Define the class that includes all the actions for counters

//Define the maximum constant that will be used for counting for the rest of the program
const int MAX_COUNT = 9999;

class Counter{

private:

	int count;
	bool value;
	int a;
	int s;
	int d;
	int f;

public:
	
	Counter();
	void reset();
	void incr1();
	void incr10();
	void incr100();
	void incr1000();
	
	//Define overflow actions
	bool overflow();

	//These functions limit the numbers between 1-9
	void in_cents();
	void in_dimes();
	void in_dollars();
	void in_10_dollars();

	//Display values
	void Display();
	void request_overflow();
	void enter(char);

};