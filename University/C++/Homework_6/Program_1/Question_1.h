//Set up dynamic memories for the two dimensional arrays
typedef double *DoubleArrayPtr;

//Set up the TwoD class with functions and methods

class TwoD{

private:
	
	unsigned int MaxRows, MaxCols;

	int row, col;

	double sum;

	double **table; //Define a two dimensional pointer array.

public:
    
	double result;

	TwoD(); //Default constructor
	
	TwoD(int, int); //Parameterized constructor
	
	TwoD(int, int, int, int, double); // Class with size and entry included (use for addition)

	TwoD(const TwoD &p); //Copy Constructor

	int getMaxRow() const; //getting row entered

	int getMaxCol() const; //getting row entered

	int getRow() const; //getting row entered

	int getCol() const; // getting col entered

	void entry(int,int, double); //Enter the number elements into specific row and column

	double return_number() const; //Display the specific row and column's result
	
	~TwoD();//Destructor

	//Operator Functions
	friend const TwoD operator +(const TwoD& TD_1, const TwoD& TD_2);
	TwoD& operator=(const TwoD &p);
};
