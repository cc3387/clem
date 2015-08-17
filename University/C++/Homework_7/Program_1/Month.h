class Month{

private:

	int month;

public:

	Month(); //Default Constructors

	Month(char*); // Constructors

	Month(int); // Constructors

	char* map_char(int);

	void map_int(char*);

	void input_month(int);

	void output_month();

	void output_month_name();

	int NextMonth(const Month &p);

};