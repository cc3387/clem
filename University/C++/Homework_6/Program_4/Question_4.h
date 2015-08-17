#include <iostream>
#include <stdio.h>
#include <stddef.h>
#include <cstring>

class DynamicStringArray{

private:
	int size;
	std::string *dynamicarray;

public:

    DynamicStringArray();
	int return_size();
	void AddEntry(std::string);
	void DeleteEntry(std::string);
	std::string GetEntry(int);
	DynamicStringArray& operator =(const DynamicStringArray &p); 
	~DynamicStringArray();
};