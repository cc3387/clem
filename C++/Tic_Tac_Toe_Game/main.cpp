#include "Player.h"

int Player :: choice = 0;

int main(){
    
    int game_end;
    
    cout<< " " <<endl;
    cout<< " " <<endl;
    cout<< " " <<endl;
    cout<< " " <<endl;
    cout<<"**********************************"<<endl;
    cout<<"* Welcome to the Tic-Tac-To Game!*"<<endl;
    cout<<"**********************************"<<endl;
    cout<< " " <<endl;
    cout<< " " <<endl;
    cout<< " " <<endl;
    cout<< " " <<endl;
    
    string Player_1 = "Clem";
    string Player_2 = "Portia";
    
    Grid gg;
    Player Player1(Player_1,0,0), Player2(Player_2,0,0);
    gg.Output();
    cout << " " <<endl;
    do{
    cout << "Player 1 moves ..." << endl;
    Player1.choose_move(gg);
    game_end = gg.check_winner(Player_1, Player_2);
    cout << "Player 2 moves ..." << endl;
    Player2.choose_move(gg);
    game_end = gg.check_winner(Player_1, Player_2);
    }while(game_end == 0);
    
    return 0;
}