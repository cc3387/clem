#include "Grid.h"

//Constructor
Grid :: Grid(){
    cout<< "This is default constructor"<<endl;
    //Initialize the grid for the tik-tak-to game
    game_grid = new string*[3];
    
    for (int i=0; i<3; i++){
        game_grid[i] = new string[3];
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
        game_grid[i][j] = ".";
        }
    }
    
}

//Constructor
Grid :: ~Grid(){
    cout<< "This is grid destructor ..."<<endl;
    //Initialize the grid for the tik-tak-to game
    delete[] game_grid;
    
}

//Deep Copy Constructor
Grid :: Grid(const Grid &rhs){
    
    delete[] game_grid;
    
    //Initialize the grid for the tik-tak-to game
    game_grid = new string*[3];
    
    for (int i=0; i<3; i++){
        game_grid[i] = new string[3];
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            game_grid[i][j] = ".";
        }
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            game_grid[i][j] = rhs.getinput(i,j);
        }
    }
    
    
    input_grid = rhs.input_grid ;
    
}

//Operator Overloading
Grid &Grid::operator =(const Grid &rhs){
    
    delete[] game_grid;
    
    //Initialize the grid for the tik-tak-to game
    game_grid = new string*[3];
    
    for (int i=0; i<3; i++){
        game_grid[i] = new string[3];
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            game_grid[i][j] = ".";
        }
    }
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            game_grid[i][j] = rhs.getinput(i,j);
        }
    }
    
    return *this;
}


//Input functions
void Grid::set(string a, int b, int c){
    game_grid[c][b] = a;
}

//Output
void Grid::Output(){
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(j!=2){
            cout<<game_grid[i][j]<<" ";
        }
        else if (j==2){
            cout<<game_grid[i][j]<<endl;
        }
      }
   }
}

//Getinput
string Grid :: getinput(int a, int b) const {
    return game_grid[a][b];
}

//Checking the winner of the game and rules
int Grid :: check_winner(string Player_1, string Player_2){
    
    int ans;
    
    //Check for horizontal triple
    for (int i=0; i<3; i++){
        if (game_grid[i][0] == game_grid[i][1] && game_grid[i][0] == game_grid[i][2] && game_grid[i][1] == game_grid[i][2] && game_grid[i][1] == "O"){
            cout << " " << endl;
            cout << Player_1 << " wins!" << endl;
            cout << "Game Over!" << endl;
            exit(0);
        }
        else if (game_grid[i][0] == game_grid[i][1] && game_grid[i][0] == game_grid[i][2] && game_grid[i][1] == game_grid[i][2] && game_grid[i][1] == "X"){
            cout << " " << endl;
            cout << Player_2 << " wins!" << endl;
            cout << "Game Over!" << endl;
            exit(0);
        }
        else{
            ans = 0;
        }
    }
    
    //Check for vertical triple
    for (int i=0; i<3; i++){
    
    if (game_grid[0][i] == game_grid[1][i] && game_grid[0][i] == game_grid[2][i] && game_grid[1][i] == game_grid[2][i] && game_grid[1][i] == "O"){
        cout << " " << endl;
        cout << Player_1 << " wins!" << endl;
        cout << "Game Over!" << endl;
        exit(0);
    }
    else if (game_grid[0][i] == game_grid[1][i] && game_grid[0][i] == game_grid[2][i] && game_grid[1][i] == game_grid[2][i] && game_grid[1][i] == "X"){
        cout << " " << endl;
        cout << Player_2 << " wins!" << endl;
        cout << "Game Over!" << endl;
        exit(0);
    }
    else{
        ans = 0;
        }
    }
    

    //Check for diagonals
    
        if (game_grid[0][0] == game_grid[1][1] && game_grid[0][0] == game_grid[2][2] && game_grid[1][1] == game_grid[2][2] && game_grid[1][1] == "O"){
            cout << " " << endl;
            cout << Player_1 << " wins!" << endl;
            cout << "Game Over!" << endl;
            exit(0);
        }
        else if (game_grid[0][0] == game_grid[1][1] && game_grid[0][0] == game_grid[2][2] && game_grid[1][1] == game_grid[2][2] && game_grid[1][1] == "X"){
            cout << " " << endl;
            cout << Player_2 << " wins!" << endl;
            cout << "Game Over!" << endl;
            exit(0);
        }
        else if (game_grid[2][0] == game_grid[1][1] && game_grid[2][0] == game_grid[0][2] && game_grid[1][1] == game_grid[0][2] && game_grid[1][1] == "O"){
            cout << " " << endl;
            cout << Player_1 << " wins!" << endl;
            cout << "Game Over!" << endl;
            exit(0);
        }
        else if (game_grid[2][0] == game_grid[1][1] && game_grid[2][0] == game_grid[0][2] && game_grid[1][1] == game_grid[0][2] && game_grid[1][1] == "X"){
            cout << " " << endl;
            cout << Player_2 << " wins!" << endl;
            cout << "Game Over!" << endl;
            exit(0);
        }
        else{
            ans = 0;
        }
    
    return ans;
}



bool Grid:: check_entered(int i, int x, int y){
    
    //cout<<coord_entered[i][0]<< "," << coord_entered[i][1] << endl;
    
    if(coord_entered[i][0] == x && coord_entered[i][1] == y){
        return true;
    }
    else{
        return false;
    }
}


void Grid :: setcoord_entered(int i, int x, int y){
    
    coord_entered[i][0] = x;
    coord_entered[i][1] = y;
}




