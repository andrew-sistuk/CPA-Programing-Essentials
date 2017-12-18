#include <iostream>
#include <string>
class Game{
    public:
        void Start(){
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    playing_field[i][j] = '.';
                }
            }
        }
        void PrintPlayingField(){
            std::cout<<"    0   1   2\n";
            std::cout<<"  *---*---*---*\n";
            for(int i = 0; i<3; i++){
                    std::cout<<i<<" ";
                for(int j = 0; j<3; j++){
                    std::cout<<"| "<<playing_field[i][j]<<" ";
                }
                std::cout<<"|\n  *---*---*---*\n";
            }
        }
        bool CheckWinner(char symb){
            return CheckDiagonal(symb)||CheckLanes(symb);
        }
        bool HasGoes(){
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    if(playing_field[i][j] == '.')
                        return true;
                }
            }
            return false;
        }
        char playing_field[3][3];
    private:
        bool CheckDiagonal(char symb){
            bool toright = true, toleft = true;
            for (int i=0; i<3; i++) {
                toright &= (playing_field[i][i] == symb);
                toleft &= (playing_field[3-i-1][i] == symb);
            }
            return (toright || toleft);
        }
        bool CheckLanes(char symb) {
            bool cols, rows;
            for (int col=0; col<3; col++) {
                cols = true;
                rows = true;
                for (int row=0; row<3; row++) {
                    cols &= (playing_field[col][row] == symb);
                    rows &= (playing_field[row][col] == symb);
                }
            if (cols || rows) return true;
            }
            return false;
    }
};

class Player{
    public:
        Player(Game *game){
            this->game = game;
        }
        virtual bool Go(int cordX, int cordY)
        {
            if(cordX>2||cordX<0||cordY>2||cordY<0){
                std::cout<<"Incorrect coords, try again\n";
                return false;
            }
            if(game->playing_field[cordX][cordY]!='.')
                return false;
            return true;
        }
    protected:
        Game *game;
};
class RealPlayer: public Player{
    public:
        RealPlayer(Game *game):Player(game){}
        bool Go(int cordX, int cordY){
            if(!Player::Go(cordX, cordY))
                return false;

            game->playing_field[cordX][cordY] = 'X';
            return true;
        }
};
class Bot:public Player{
    public:
        Bot(Game *game):Player(game){}
        bool Go(int cordX, int cordY){
            if(!Player::Go(cordX, cordY))
                return false;
            game->playing_field[cordX][cordY] = 'O';
            return true;
        }
};
using namespace std;
int main()
{
    Game *game = new Game();
    Player *player = new RealPlayer(game);
    Player *bot = new Bot(game);
    string q;
    cout<<"Start new game? (yes/no)\n";
    cin>>q;
    int cordX, cordY;
    while(q == "yes"){
        game->Start();
        game->PrintPlayingField();

        while(true){
            do{
                cout<<"Please enter cordX: \n";
                cin>>cordX;
                cout<<"Please enter cordY: \n";
                cin>>cordY;
            }
            while(!player->Go(cordY, cordX));

            cout<<"\nYou:\n";
            game->PrintPlayingField();
            if(game->CheckWinner('X'))
            {
                cout<<"CONGRATULATION! YOU WIN!!!\n";
                break;
            }
            if(!game->HasGoes()){
                cout<<"NOT BAD! DEAD HEAT!!!\n";
                break;
            }

            do{
                cordX = rand() % 3;
                cordY = rand() % 3;
            }
            while(!bot->Go(cordX, cordY));

            cout<<"\nBot:\n";
            game->PrintPlayingField();

            if(game->CheckWinner('O'))
            {
                cout<<"SORRY! YOU LOSE!!!\n";
                break;
            }
            if(!game->HasGoes()){
                cout<<"NOT BAD! DEAD HEAT!!!\n";
                break;
            }

        }
        cout<<"Start new game? (yes/no)\n";
        cin>>q;
    }
    return 0;
}