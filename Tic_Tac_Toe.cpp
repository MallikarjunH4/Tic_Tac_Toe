#include<iostream>


using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

char current_marker;

int current_player;

void playboard(){

    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<board[0][0]<<"  | "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"\t\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<board[1][0]<<"  | "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"\t\t\t\t_____|_____|_____\n";
    cout<<"\t\t\t\t     |     |     \n";
    cout<<"\t\t\t\t  "<<board[2][0]<<"  | "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"\t\t\t\t     |     |     \n";
}
bool placemarker(int slot)
{
    int row=slot/3;
    int col;

    if (slot % 3==0)
    {
        row=row-1;
         col=2;
    }
    else col=(slot %3 )-1;

   if(board[row][col]!='x' && board[row][col]!='o'){

   board[row][col]=current_marker;

   return true;
   }
   else

    return false;

}
int  winner()
{
    for(int i=0;i<3 ;i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
            return current_player;

        if(board[i][0]==board[1][i] && board[1][i]==board[2][i])
            return current_player;

    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
        return current_player;

    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
        return current_player;


    return 0;


}
void    swap_player_and_marker()
{
    if(current_marker=='x') current_marker='o';

    else current_marker='x';

    if(current_player==1) current_player=2;

    else current_player=1;

}
void game(){


cout<<"\nPlayer One,Choose Your Marker ['X'] or ['O'] :";

char marker_p1;

cin>>marker_p1;


current_player=1;

current_marker=marker_p1;

playboard();

int player_won;

for(int i=0;i<9;i++)
{
    cout<<"\nIts Player"<<current_player<<"'s Turn . Enter your choice:";

    int slot;

    cin>>slot;

    if(slot <1 || slot>9) {

     cout<<"\nThat  slot doesn't exits. Try Another!!";
      i--;
     continue;
     }

    if(!placemarker(slot)){

       cout<<"\nThat  slot is filled. Try Another!!";
       i--;
        continue;
    }
    playboard();
    player_won=winner();

    if(player_won==1) {
          cout<<"\n\tCongratulations. Player ONE has Won the $GAME$\n\n\n\n";
         break;
    }
    if(player_won==2) {
            cout<<"\n\tCongratulations. Player TWO has Won the $GAME$\n\n\n\n";
           break;
           }

    swap_player_and_marker();

}


if(player_won==0) cout<<"\n\n\t\t\tGAME DRAW!!!!!\n\n\n\n";





}

int main()
{
     cout<<"\t\t\t\t\tWELCOME\n";
	cout<<"\t\t\tT I C K -- T A C -- T O E -- G A M E\t\t\t";
    cout<<"\n\t\t\t\tFOR 2 PLAYERS";
    cout<<"\n\t\t----------------------------------------------------\n\n";
  game();
}


























