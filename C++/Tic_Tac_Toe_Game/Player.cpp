#include "Player.h"

//Default Constructor
Player :: Player() : player_name("No name yet"), coord_x(0), coord_y(0){
    
}

//Parametric Constructor
Player :: Player(string the_name, int the_x, int the_y){
    player_name = the_name;
    coord_x = the_x;
    coord_y = the_y;
}

//Copy Constructor
Player :: Player(const Player &rhs){
    player_name = rhs.getpn();
    coord_x = rhs.getx();
    coord_y = rhs.gety();
}

//Assignment Operator
Player &Player:: operator = (const Player &rhs){
    player_name = rhs.getpn();
    coord_x = rhs.getx();
    coord_y = rhs.gety();
    return *this;
}

Player :: ~Player(){
    cout<<"This is Player destructor ... "<<endl;
}

//Setters
void Player :: setx(int the_x){
    coord_x = the_x;
}

void Player :: sety(int the_y){
    coord_y = the_y;
}

void Player :: setpn(string the_name){
    player_name = the_name;
}

//Getters

string Player :: getpn() const{
    return player_name;
}

int Player :: getx() const{
    return coord_x;
}

int Player :: gety() const{
    return coord_y;
}

int Player :: getx_old() const{
    return coord_x_old;
}

int Player :: gety_old() const{
    return coord_y_old;
}

//Show Grid
void Player :: show_grid(Grid &GD){
    GD.Output();
}

//Movers
//Move up
void Player :: move_up(char input, Grid &GD){
    
    if(input =='i'){
        
        if(coord_y == 0){
            coord_y = 0;
        }
        else{
            coord_y -= 1;
        }
        
        
        if(coord_x == 0 && coord_y == 1){
            coord_x_old = 0;
            coord_y_old = 2;
        }
        
        else if(coord_x == 0 && coord_y == 0){
            coord_x_old = 0;
            coord_y_old = 1;
        }
        
        else if(coord_x == 1 && coord_y == 1){
            coord_x_old = 1;
            coord_y_old = 2;
        }
        else if(coord_x == 1 && coord_y == 0){
            coord_x_old = 1;
            coord_y_old = 1;
        }
        
        else if(coord_x == 2 && coord_y == 1){
            coord_x_old = 2;
            coord_y_old = 2;
        }
        else if(coord_x == 2 && coord_y == 0){
            coord_x_old = 2;
            coord_y_old = 1;
        }
        
        int k = 0;
        int k1 = 0;
        int k2 = 0;
        int k3 = 0;
        int kfinal = 0;
        int kfinal2 = 0;
        int kfinal3 = 0;
        int i = 1;
        
        if(choice > 0){
            do{
                k = GD.check_entered(i, getx(), gety());
                k1 = GD.check_entered(i,getx(), gety()+1);
                k2 = GD.check_entered(i,getx(), gety()-1);
                i++;
                
                if(k==1){
                    kfinal = 1;
                }
                else if(k1 == 1){
                    kfinal2 = 1;
                }
                else if(k2 == 1){
                    kfinal3 = 3;
                }
                
                if(k == 1 && k2 == 1){
                    kfinal = 3;
                    kfinal3 = 3;
                }
                
            }while(i <= choice);
        }
        
        //cout << "k is: " << k << "," << "k1 is: " << k1 << "," << " k2 is: " << k2 << endl;
        //cout << "kfinal is: " << kfinal << "," << "kfinal2 is: " << kfinal2 <<  "," << " kfinal3 is: " << kfinal3 << endl;
        
        if(choice%2 ==0 & k == 0 && k1 == 0 && k2 == 1 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 3 && gety() - 1 == 0){
            GD.set("O", getx(), gety() + 1);
            coord_y = gety() + 1;
            coord_y_old = coord_y;
        }
        else if(k == 0 && k1 == 0 && k2 == 1 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 3 && gety() - 1 == 0){
            GD.set("X", getx(), gety() + 1);
            coord_y = gety() + 1;
            coord_y_old = coord_y;
        }
        else if(choice%2 ==0 & k == 1 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 0 && gety()== 0){
            GD.set("O", getx(), gety() + 1);
            coord_y = gety() + 1;
            coord_y_old = coord_y;
        }
        else if(k == 1 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 0 && gety()== 0){
            GD.set("X", getx(), gety() + 1);
            coord_y = gety() + 1;
            coord_y_old = coord_y;
        }
        else if(choice%2 ==0 & k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 0 && gety()== 0){
            GD.set("O", getx(), gety() + 1);
            coord_y = gety() + 1;
            coord_y_old = coord_y;
        }
        else if(k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 0 && gety()== 0){
            GD.set("X", getx(), gety() + 1);
            coord_y = gety() + 1;
            coord_y_old = coord_y;
        }
        else if(choice%2 ==0 & k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 1 && kfinal3 == 0 && gety() - 1 == 0){
            GD.set("O", getx(), gety() + 1);
            coord_y = gety() + 1;
            coord_y_old = coord_y;
        }
        else if(k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 1 && kfinal3 == 0 && gety() - 1 == 0){
            GD.set("X", getx(), gety() + 1);
            coord_y = gety() + 1;
            coord_y_old = coord_y;
        }
        else if(choice%2 ==0 & k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 3 && gety() - 1 == 0){
            GD.set("O", getx(), gety() + 1);
            coord_y = gety() + 1;
            coord_y_old = coord_y;
        }
        else if(k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 3 && gety() - 1 == 0){
            GD.set("X", getx(), gety() + 1);
            coord_y = gety() + 1;
            coord_y_old = coord_y;
        }
        else if(choice%2 ==0 & k == 1 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 3 && gety() - 1 == 0){
            GD.set("O", getx(), gety() + 1);
            coord_y = gety() + 1;
            coord_y_old = coord_y;
        }
        else if(k == 1 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 3 && gety() - 1 == 0){
            GD.set("X", getx(), gety() + 1);
            coord_y = gety() + 1;
            coord_y_old = coord_y;
        }
        else if(choice % 2 == 0 && kfinal == 0){
            //cout << "Coord_X is " << getx() << ", " << "Coord_Y is " << gety() << " The Grid point is: " << GD.getinput(getx(), gety()) << endl;
            GD.set("O", getx(), gety());
            GD.set(".", getx_old(), gety_old());
        }
        else if(choice % 2 == 0 && kfinal == 1){
            GD.set("O", getx(), gety() - 1);
            GD.set(".", getx_old(), gety_old());
            coord_y -= 1;
            coord_y_old = coord_y;
        }
        else if (kfinal == 0){
            //cout << "Coord_X is " << getx() << ", " << "Coord_Y is " << gety() << " The Grid point is: " << GD.getinput(getx(), gety()) << endl;
            GD.set("X", getx(), gety());
            GD.set(".", getx_old(), gety_old());
        }
        else if (kfinal == 1){
            //cout << "Coord_X is " << getx() << ", " << "Coord_Y is " << gety() << " The Grid point is: " << GD.getinput(getx(), gety()) << endl;
            GD.set("X", getx(), gety() - 1);
            GD.set(".", getx_old(), gety_old());
            coord_y -= 1;
            coord_y_old = coord_y;
        }
    
        if(choice > 0){
            do{
                k = GD.check_entered(i, getx(), gety());
                
                if (k == 1 && choice % 2 == 0){
                GD.set("O", 0, 0);
                }
                else if(k == 1){
                GD.set("X", 0, 0);
                }
                
            }while(i <= choice);
        }
    }
}

//Move down
void Player :: move_down(char input, Grid &GD){

    if(input =='k'){
      
        coord_y += 1;
    
        if(coord_x == 0 && coord_y == 1){
           coord_x_old = 0;
           coord_y_old = 0;
        }
        
        else if(coord_x == 0 && coord_y == 2){
          coord_x_old = 0;
          coord_y_old = 1;
        }
    
        else if(coord_x == 1 && coord_y == 1){
            coord_x_old = 1;
            coord_y_old = 0;
        }
        else if(coord_x == 1 && coord_y == 2){
            coord_x_old = 1;
            coord_y_old = 1;
        }
        else if(coord_x == 2 && coord_y == 1){
            coord_x_old = 2;
            coord_y_old = 0;
        }
        else if(coord_x == 2 && coord_y == 2){
            coord_x_old = 2;
            coord_y_old = 1;
        }
        
        int k = 0;
        int k1 = 0;
        int k2 = 0;
        int kfinal = 0;
        int kfinal2 = 0;
        int kfinal3 = 0;
        int i = 1;
        
        if(choice > 0){
            
            do{
                k = GD.check_entered(i, getx(), gety());
                k1 = GD.check_entered(i,getx(), gety()+1);
                k2 = GD.check_entered(i,getx(), gety()-1);
                i++;
                
                if(k==1){
                    kfinal = 1;
                }
                else if(k1==1){
                    kfinal2 = 1;
                }
                else if(k2==1){
                    kfinal3 = 1;
                }
                
                if(k == 1 && k1 == 1){
                    kfinal  = 3;
                    kfinal2 = 3;
                }
                
            }while(i <= choice);
        }
        
        //cout << "k is: " << k << "," << "k1 is: " << k1 << "," << " k2 is: " << k2 << endl;
        //cout << "kfinal is: " << kfinal << "," << "kfinal2 is: " << kfinal2 <<  "," << " kfinal3 is: " << kfinal3 << endl;
        
        if(choice % 2 == 0 && k == 0 && k1 == 1 && k2 == 0 && kfinal == 1 && kfinal2 == 1 && kfinal3 == 0 && (gety()+1) == 2){
            GD.set("O", getx(), gety()-1);
            coord_y = gety() - 1;
            coord_y_old = coord_y;
        }
        else if(k == 0 && k1 == 1 && k2 == 0 && kfinal == 1 && kfinal2 == 1 && kfinal3 == 0 && (gety()+1) == 2){
            GD.set("X", getx(), gety()-1);
            coord_y = gety() - 1;
            coord_y_old = coord_y;
        }
        else if(choice % 2 == 0 && k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 1 && kfinal3 == 0 && (gety()+1) == 2){
            GD.set("O", getx(), gety()-1);
            coord_y = gety() - 1;
            coord_y_old = coord_y;
        }
        else if(k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 1 && kfinal3 == 0 && (gety()+1) == 2){
            GD.set("X", getx(), gety()-1);
            coord_y = gety() - 1;
            coord_y_old = coord_y;
        }
        else if(choice % 2 == 0 && k == 1 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 0 && (gety()) == 2){
            GD.set("O", getx(), gety()-1);
            coord_y = gety() - 1;
            coord_y_old = coord_y;
        }
        else if(k == 1 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 0 && (gety()) == 2){
            GD.set("X", getx(), gety()-1);
            coord_y = gety() - 1;
            coord_y_old = coord_y;
        }
        else if(choice % 2 == 0 && k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 0 && (gety()) == 2){
            GD.set("O", getx(), gety()-1);
            coord_y = gety() - 1;
            coord_y_old = coord_y;
        }
        else if(k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 0 && (gety()) == 2){
            GD.set("X", getx(), gety()-1);
            coord_y = gety() - 1;
            coord_y_old = coord_y;
        }
        else if(choice % 2 == 0 && k == 1 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 1 && kfinal3 == 0 && (gety()) == 2){
            GD.set("O", getx(), gety()-1);
            coord_y = gety() - 1;
            coord_y_old = coord_y;
        }
        else if(k == 1 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 1 && kfinal3 == 0 && (gety()) == 2){
            GD.set("X", getx(), gety()-1);
            coord_y = gety() - 1;
            coord_y_old = coord_y;
        }
        else if(choice % 2 == 0 && kfinal == 0){
            //cout << "Coord_X is " << getx() << ", " << "Coord_Y is " << gety() << " The Grid point is: " << GD.getinput(getx(), gety()) << endl;
            GD.set("O", getx(), gety());
            GD.set(".", getx_old(), gety_old());
        }
        else if(choice % 2 == 0 && kfinal == 1){
            GD.set("O", getx(), gety() + 1);
            GD.set(".", getx_old(), gety_old());
            coord_y += 1;
            coord_y_old = coord_y;
        }
        else if (kfinal == 0){
            //cout << "Coord_X is " << getx() << ", " << "Coord_Y is " << gety() << " The Grid point is: " << GD.getinput(getx(), gety()) << endl;
            GD.set("X", getx(), gety());
            GD.set(".", getx_old(), gety_old());
        }
        else if (kfinal == 1){
            //cout << "Coord_X is " << getx() << ", " << "Coord_Y is " << gety() << " The Grid point is: " << GD.getinput(getx(), gety()) << endl;
            GD.set("X", getx(), gety() + 1);
            GD.set(".", getx_old(), gety_old());
            coord_y += 1;
            coord_y_old = coord_y;
        }
        
        if(choice > 0){
            do{
                k = GD.check_entered(i, getx(), gety());
                
                if (k == 1 && choice % 2 == 0){
                    GD.set("O", 0, 0);
                }
                else if(k == 1){
                    GD.set("X", 0, 0);
                }
                
            }while(i <= choice);
        }
    }
}

//Move left
void Player :: move_left(char input, Grid &GD){

    if (input == 'j')
    {
        if(coord_x == 0){
        coord_x = 0;
        }
        else{
        coord_x -= 1;
        }
            
            
        if(coord_x == 0 && coord_y == 0){
            coord_x_old = 1;
            coord_y_old = 0;
        }
        else if(coord_x == 1 && coord_y == 0){
            coord_x_old = 2;
            coord_y_old = 0;
        }
        else if (coord_x == 0 && coord_y == 1){
            coord_x_old = 1;
            coord_y_old = 1;
        }
        else if(coord_x == 1 && coord_y == 1){
            coord_x_old = 2;
            coord_y_old = 1;
        }
        else if(coord_x == 0 && coord_y == 2){
            coord_x_old = 1;
            coord_y_old = 2;
        }
        else if(coord_x == 1 && coord_y ==2){
            coord_x_old = 2;
            coord_y_old = 2;
        }
        
        int k = 0;
        int k1 = 0;
        int k2 = 0;
        int kfinal = 0;
        int kfinal2 = 0;
        int kfinal3 = 0;
        int i = 1;
        
        if(choice > 0){
            do{
                k = GD.check_entered(i, getx(), gety());
                k1 = GD.check_entered(i,getx()+1, gety());
                k2 = GD.check_entered(i,getx()-1, gety());
                i++;
                
                //cout<<getx()-1<<endl;
                //cout<<gety()<<endl;
                
                if(k==1){
                    kfinal = 1;
                }
                else if(k1==1){
                    kfinal = 3;
                    kfinal2 = 1;
                }
                else if(k2==1){
                    kfinal3 = 1;
                }
                
            }while(i <= choice);
        }
        
        //cout << "k is: " << k << "," << "k1 is: " << k1 << "," << " k2 is: " << k2 << endl;
        //cout << "kfinal is: " << kfinal << "," << "kfinal2 is: " << kfinal2 <<  "," << " kfinal3 is: " << kfinal3 << endl;
    
        if (choice % 2 == 0 && k == 1 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 1 && (getx()-1) == 0){
            GD.set("O", getx() + 1, gety());
            coord_x = getx() + 1;
            coord_x_old = coord_x;
        }
        else if (choice % 2 == 0 && k == 0 && k1 == 0 && k2 == 1 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 1 && (getx()-1) == 0){
            GD.set("O", getx() + 1, gety());
            coord_x = getx() + 1;
            coord_x_old = coord_x;
        }
        else if (choice % 2 == 0 && k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 1 && (getx()-1) == 0){
            GD.set("O", getx() + 1, gety());
            coord_x = getx() + 1;
            coord_x_old = coord_x;
        }
        else if (k == 1 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 1 && (getx()-1) == 0){
            GD.set("X", getx() + 1, gety());
            coord_x = getx() + 1;
            coord_x_old = coord_x;
        }
        else if (k == 0 && k1 == 1 && k2 == 0 && kfinal == 3 && kfinal2 == 1 && kfinal3 == 0 && (getx()-1) == 0){
            GD.set("X", getx() + 1, gety());
            coord_x = getx() + 1;
            coord_x_old = coord_x;
        }
        else if (k == 0 && k1 == 0 && k2 == 1 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 1 && (getx()-1) == 0){
            GD.set("X", getx() + 1, gety());
            coord_x = getx() + 1;
            coord_x_old = coord_x;
        }
        else if (choice % 2 == 0 && k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 0 && (getx()) == 0){
            GD.set("O", getx() + 1, gety());
            coord_x = getx() + 1;
            coord_x_old = coord_x;
        }
        else if (k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 1 && (getx()-1) == 0){
            GD.set("X", getx() + 1, gety());
            coord_x = getx() + 1;
            coord_x_old = coord_x;
        }
        else if (k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 0 && (getx()) == 0){
            GD.set("X", getx() + 1, gety());
            coord_x = getx() + 1;
            coord_x_old = coord_x;
        }
        else if (choice % 2 == 0 && k == 1 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 0 && (getx()) == 0){
            GD.set("O", getx() + 1, gety());
            coord_x = getx() + 1;
            coord_x_old = coord_x;
        }
        else if (k == 1 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 0 && (getx()) == 0){
            GD.set("X", getx() + 1, gety());
            coord_x = getx() + 1;
            coord_x_old = coord_x;
        }
        else if(choice % 2 == 0 && kfinal == 0){
            //cout << "Coord_X is " << getx() << ", " << "Coord_Y is " << gety() << " The Grid point is: " << GD.getinput(getx(), gety()) << endl;
            GD.set("O", getx(), gety());
            GD.set(".", getx_old(), gety_old());
        }
        else if(choice % 2 == 0 && kfinal == 1){
            GD.set("O", getx() - 1, gety());
            GD.set(".", getx_old(), gety_old());
            coord_x -= 1;
            coord_x_old = coord_x;
        }
        else if (kfinal == 0){
            //cout << "Coord_X is " << getx() << ", " << "Coord_Y is " << gety() << " The Grid point is: " << GD.getinput(getx(), gety()) << endl;
            GD.set("X", getx(), gety());
            GD.set(".", getx_old(), gety_old());
        }
        else if (kfinal == 1){
            //cout << "Coord_X is " << getx() << ", " << "Coord_Y is " << gety() << " The Grid point is: " << GD.getinput(getx(), gety()) << endl;
            GD.set("X", getx() - 1, gety());
            GD.set(".", getx_old(), gety_old());
            coord_x -= 1;
            coord_x_old = coord_x;
        }
        
        if(choice > 0){
            do{
                k = GD.check_entered(i, getx(), gety());
                
                if (k == 1 && choice % 2 == 0){
                    GD.set("O", 0, 0);
                }
                else if(k == 1){
                    GD.set("X", 0, 0);
                }
                
            }while(i <= choice);
        }
    }
}

//Move Right
void Player :: move_right(char input, Grid &GD){
    if (input == 'l')
    {
        coord_x += 1;
        
        if(coord_x == 1 && coord_y == 0){
            coord_x_old = 0;
            coord_y_old = 0;
        }
        else if(coord_x == 1 && coord_y == 1){
            coord_x_old = 0;
            coord_y_old = 1;
        }
        else if(coord_x == 1 && coord_y == 2){
            coord_x_old = 0;
            coord_y_old = 2;
        }
        else if(coord_x == 2 && coord_y == 0){
           coord_x_old = 1;
           coord_y_old = 0;
        }
        else if(coord_x == 2 && coord_y == 1){
            coord_x_old = 1;
            coord_y_old = 1;
        }
        else if(coord_x == 2 && coord_y == 2){
            coord_x_old = 1;
            coord_y_old = 2;
        }
        
        int k = 0;
        int k1 = 0;
        int k2 = 0;
        int k3 = 0;
        int kfinal = 0;
        int kfinal2 = 0;
        int kfinal3 = 0;
        int i = 1;
        
        if(choice > 0){
            do{
                k = GD.check_entered(i, getx(), gety());
                k1 = GD.check_entered(i,getx()+1, gety());
                k2 = GD.check_entered(i,getx()-1, gety());
                i++;
                
                if(k==1){
                kfinal = 1;
                }
                else if(k1 == 1){
                kfinal2 = 1;
                }
                else if(k2 == 1){
                kfinal3 = 1;
                }
                
                if (k==1 && k1 ==1){
                    kfinal = 3;
                    kfinal2 = 3;
                }
            

            }while(i <= choice);
        }
        
        //cout << "k is: " << k << "," << "k1 is: " << k1 << "," << " k2 is: " << k2 << endl;
        //cout << "kfinal is: " << kfinal << "," << "kfinal2 is: " << kfinal2 <<  "," << " kfinal3 is: " << kfinal3 << endl;
        
        
        if (choice % 2 == 0 && k == 0 && k1 == 1 && k2 == 0 && kfinal == 1 && kfinal2 == 1 && kfinal3 == 0 && getx()+1 == 2){
            GD.set("O", getx() - 1, gety());
            coord_x = getx() - 1;
            coord_x_old = coord_x;
        }
        else if(k == 0 && k1 == 1 && k2 == 0 && kfinal == 1 && kfinal2 == 1 && kfinal3 == 0 && getx()+1 == 2){
            GD.set("X", getx() - 1, gety());
            coord_x = getx() - 1;
            coord_x_old = coord_x;
        }
        else if (choice % 2 == 0 && k == 1 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 0 && getx() == 2){
            GD.set("O", getx() - 1, gety());
            coord_x = getx() - 1;
            coord_x_old = coord_x;
        }
        else if(k == 1 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 0 && getx() == 2){
            GD.set("X", getx() - 1, gety());
            coord_x = getx() - 1;
            coord_x_old = coord_x;
        }
        else if (choice % 2 == 0 && k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 1 && kfinal3 == 0 && getx()+1 == 2){
            GD.set("O", getx() - 1, gety());
            coord_x = getx() - 1;
            coord_x_old = coord_x;
        }
        else if(k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 1 && kfinal3 == 0 && getx()+1 == 2){
            GD.set("X", getx() - 1, gety());
            coord_x = getx() - 1;
            coord_x_old = coord_x;
        }
        else if (choice % 2 == 0 && k == 1 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 1 && kfinal3 == 0 && getx()+1 == 2){
            GD.set("O", getx() - 1, gety());
            coord_x = getx() - 1;
            coord_x_old = coord_x;
        }
        else if(k == 1 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 1 && kfinal3 == 0 && getx()+1 == 2){
            GD.set("X", getx() - 1, gety());
            coord_x = getx() - 1;
            coord_x_old = coord_x;
        }
        else if (choice % 2 == 0 && k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 0 && getx() == 2){
            GD.set("O", getx() - 1, gety());
            coord_x = getx() - 1;
            coord_x_old = coord_x;
        }
        else if(k == 0 && k1 == 0 && k2 == 0 && kfinal == 1 && kfinal2 == 0 && kfinal3 == 0 && getx() == 2){
            GD.set("X", getx() - 1, gety());
            coord_x = getx() - 1;
            coord_x_old = coord_x;
        }
        else if(choice % 2 == 0 && kfinal == 0){
            //cout << "Coord_X is " << getx() << ", " << "Coord_Y is " << gety() << " The Grid point is: " << GD.getinput(getx(), gety()) << endl;
            GD.set("O", getx(), gety());
            GD.set(".", getx_old(), gety_old());
        }
        else if(choice % 2 == 0 && kfinal == 1){
            GD.set("O", getx() + 1, gety());
            GD.set(".", getx_old(), gety_old());
            coord_x += 1;
            coord_x_old = coord_x;
        }
        else if(choice % 2 == 0 && kfinal2 == 1){
            GD.set("O", getx() - 1, gety());
            coord_x -= 1;
            coord_x_old = coord_x;
        }
        else if (kfinal == 0){
            //cout << "Coord_X is " << getx() << ", " << "Coord_Y is " << gety() << " The Grid point is: " << GD.getinput(getx(), gety()) << endl;
            GD.set("X", getx(), gety());
            GD.set(".", getx_old(), gety_old());
        }
        else if (kfinal == 1){
            //cout << "Coord_X is " << getx() << ", " << "Coord_Y is " << gety() << " The Grid point is: " << GD.getinput(getx(), gety()) << endl;
            GD.set("X", getx() + 1, gety());
            GD.set(".", getx_old(), gety_old());
            coord_x += 1;
            coord_x_old = coord_x;
        }
        else if (kfinal2 == 1){
            //cout << "Coord_X is " << getx() << ", " << "Coord_Y is " << gety() << " The Grid point is: " << GD.getinput(getx(), gety()) << endl;
            GD.set("X", getx() - 1, gety());
            coord_x -= 1;
            coord_x_old = coord_x;
        }
        
        if(choice > 0){
            do{
                k = GD.check_entered(i, getx(), gety());
                
                if (k == 1 && choice % 2 == 0){
                    GD.set("O", 0, 0);
                }
                else if(k == 1){
                    GD.set("X", 0, 0);
                }
                
            }while(i <= choice);
        }
    }
}

//Choose the move!
void Player :: choose_move(Grid &GD){
    
    coord_x = 0;
    coord_y = 0;
    
    int input;
    
    do{
    
    input = getch();
    
    input = (char)input;
        
    if(input == 'i'){
        move_up(input,GD);
    }
    else if(input == 'k'){
        move_down(input,GD);
    }
    else if(input == 'l'){
        move_right(input,GD);
    }
    else if(input == 'j'){
        move_left(input,GD);
    }
       
    cout << "Coordinate now is: " << "(" << coord_x << "," << coord_y << ")" << endl;
    cout << "Coordinate old is: " << "(" << coord_x_old << "," << coord_y_old << ")" << endl;
    //Show Grid everytime after move
    show_grid(GD);
    }while(input != 'm');
    choice += 1;
    
    int k;
    int i = 1;
    
    do{
        k = GD.check_entered(i, getx(), gety());
        i++;
    }while(i <= choice);
    
    if(k == 0){
    GD.setcoord_entered(choice,coord_x,coord_y);
    }
    cout << "Entered Coordinate is: " << "(" << coord_x << "," << coord_y << ")" << endl;
}


//The following function allows interaction with grid without entering "Enter" for the terminal game
int Player :: getch(void){

    struct termios oldt, newt;
    int ch;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    
    return ch;
}



