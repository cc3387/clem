//Define the Hot Dog Stand Class for definition uses

class HotdogSt{

private:
	
	int ID;
	
	int num_hd_sold;

public:
	
	static int total_hd_sold;
	
	HotdogSt(int,int);
	
	void JustSold();
	
	void getStandSold();
	
	int getID();
	
	static int display_total();
};

//Initializing the public static int

int HotdogSt::total_hd_sold = 0;