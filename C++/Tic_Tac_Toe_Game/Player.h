#include <iostream>
#include <stdio.h>
#include <cstring>
#include <termios.h>
#include <unistd.h>
#include "Grid.h"
using namespace std;

class Player{
    
private:
    
    string player_name;
    int coord_x;
    int coord_x_old;
    int coord_y;
    int coord_y_old;
    static int choice;
    
public:
    
    //Default Constructor
    Player();
    
    //Parameterized Constructor
    Player(string,int,int);
    
    //Copy Constructor
    Player(const Player &rhs);
    
    //Assignment Operator
    Player &operator = (const Player &rhs);
    
    //Destructor
    ~Player();
    
    //Setter, getter, functions
    void setx(int);
    void sety(int);
    void setpn(string);
    string getpn() const;
    int getx()const;
    int gety()const;
    int getx_old()const;
    int gety_old()const;
    
    
    //Movers, use i(up), k(down), j(left), l(right)
    void show_grid(Grid &GD);
    void move_up(char, Grid &GD);
    void move_down(char, Grid &GD);
    void move_left(char, Grid &GD);
    void move_right(char, Grid &GD);
    void choose_move(Grid &GD); //This function includes all move up, down, left, right
    int getch(void);
};