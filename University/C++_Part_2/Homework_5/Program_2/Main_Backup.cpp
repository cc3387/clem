#include <iostream>
using namespace std;


class HanoiPost{

private:

	int post_1[64];
	int post_2[64];
	int post_3[64];

public:
  
    void initialize_post();
	void Display_post();
	void Move_Top_1_to_2();
	void Move_123(int);
	void Move_31(int);
	void Move_12(int);
};

//Function to create the three posts with all the stones located in one post (post 1)
void HanoiPost::initialize_post(){

	for(int i=0; i<64; i++){
	post_1[i] = (64-i);
	post_2[i] = 0;
	post_3[i] = 0;
	}
}

void HanoiPost::Move_Top_1_to_2(){
	post_2[0] = post_1[0];
	post_1[0] = 0;
}



//Function to display all the stones in each post
void HanoiPost::Display_post(){
	
	for(int i=0; i<64; i++){
	cout<<post_1[i]<<","<<post_2[i]<<","<<post_3[i]<<endl;
	}

}

//Move all the stones below to the third pole
void HanoiPost::Move_123(int i){
	 
	 if(i > 0){
	 int a; 
	 a = post_1[i-1];
	 post_2[i-1] = a;
	 post_3[i-1] = a;
	 post_2[i-1] = 0;
	 post_1[i-1] = 0;
	 cout<<post_1[i-1]<<","<<post_2[i-1]<<","<<post_3[i-1]<<endl;
	 }
	 
	 if(i == 0){
	 cout<<post_1[0]<<","<<post_2[0]<<","<<post_3[0]<<endl;
	 i++;
	 }
	 
	 if(i < 64 && i > 0){
	 Move_123(i+1);
	 }
}


//Move all the stones below to the third pole
void HanoiPost::Move_31(int i){
	 
	 if(i > 0){
	 int a; 
	 a = post_3[i-1];
	 post_1[i-1] = a;
	 post_3[i-1] = 0;
	 cout<<post_1[i-1]<<","<<post_2[i-1]<<","<<post_3[i-1]<<endl;
	 }
	 
	 if(i == 0){
	 cout<<post_1[0]<<","<<post_2[0]<<","<<post_3[0]<<endl;
	 i++;
	 }
	 
	 if(i < 64 && i > 0){
	 Move_31(i+1);
	 }
}

void HanoiPost::Move_12(int i){
	 
	 if(i > 0){
	 int a; 
	 a = post_1[i-1];
	 post_2[i-1] = a;
	 post_1[i-1] = 0;
	 cout<<post_1[i-1]<<","<<post_2[i-1]<<","<<post_3[i-1]<<endl;
	 }
	 
	 if(i == 0){
	 cout<<post_1[0]<<","<<post_2[0]<<","<<post_3[0]<<endl;
	 i++;
	 }
	 
	 if(i < 64 && i > 0){
	 Move_12(i+1);
	 }
}



int main(){

	HanoiPost HP;

	HP.initialize_post();
	cout<<"The original stones are put in the corresponding posts: (Left-Post_1, Middle-Post_2, Right-Post_3)" << endl;
	HP.Display_post();
	cout<<" "<< endl;
	cout<<"The moving all the stones one by one to post_3 except the top: " << endl;
	HP.Move_123(0);
	cout<<" "<< endl;
	cout<<"Move the top from post_1 to post_2 ... " << endl;
	HP.Move_Top_1_to_2();
	cout<<" "<< endl;
	cout<<"The New Set looks like below " << endl;
	HP.Display_post();
	cout<<" "<< endl;
	cout<<"Now we move all the stones to Post_1 from Post_3  " << endl;
	HP.Move_31(0);
	cout<<" "<< endl;
	cout<<"Now we move all the stones to Post_2 from Post_1 to complete the moves " << endl;
	HP.Move_12(0);

	cout<<"The process ended and we completed the Hanoi Tower by moving 64 stones recursively..." << endl;

	return 0;
}