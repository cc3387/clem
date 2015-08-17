#include "template_array.h"


int main(){

	Array<int> Array_int(3);
	Array<float> Array_float(5);
	Array<char> Array_char(2);

	//Inputting Array for int type
	Array_int.setArray(0,3);
	Array_int.setArray(1,2);
	Array_int.setArray(2,1);

	//Inputting Array for float type
	Array_float.setArray(0,0.5);
	Array_float.setArray(1,1.4);
	Array_float.setArray(2,3.23);
	Array_float.setArray(3,1.22);
	Array_float.setArray(4,4.7);

	
	//Inputting Array for char type
	Array_char.setArray(0,'T');
	Array_char.setArray(1,'F');
	
	//Getting different entries with different typedef
	Array_int.getArray();
	Array_float.getArray();
	Array_char.getArray();

	return 0;

}