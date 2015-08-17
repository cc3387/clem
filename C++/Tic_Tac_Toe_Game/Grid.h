#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

class Grid{
    
private:
    
    string **game_grid;
    string input_grid;
    int coord_entered[10][2];
    
public:
    
    Grid(); //Default Constructor
    Grid(const Grid &rhs); // Copy Constructor
    Grid &operator = (const Grid &rhs); //Assignment Operator
    ~Grid();
    
    //Setters and Getters
    void set(string, int, int);
    void Output();
    int check_winner(string, string);
    void Diplay_End_Game();
    string getinput(int,int) const;
    bool check_entered(int, int, int);
    void setcoord_entered(int, int, int);
    
};