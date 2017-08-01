#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#define max 10
using namespace std;

bool gameOver = false;

class Player{
    friend void highScore(Player[]);
    private:
        string name;
        int score;
    public:
        void typeInName();
        void displayName(){cout << name;};
};

void Player::typeInName(){
    cout << "Enter your name: ";
    getline(cin, name);
}

void highScore(Player p[]){
    ifstream infile;
    infile.open("tictactoe_highscore.dat");

    for(int i = 0; i < 10; i++){
        infile >> p[i].name;
        infile >> p[i].score;
    }
}

class TicTacToe{
    friend void operation(TicTacToe);
    private:
        int n; //size
        int Board[max+1][max+1];
    public:
        TicTacToe();
        void go(int &x, int &y);
        void typeInSize();
        void display();
        void Player1(Player);
        void Player2(Player);
        int check();
};

//Hàm tạo: reset bàn chơi
TicTacToe::TicTacToe(){
    for(int i = 1; i <= max; i++){
        for(int j = 1; j <= max; j++){
            Board[i][j] = 0;
        }
    }
}

void TicTacToe::typeInSize(){
    do{
        cin >> n;
    }
    while(n < 3 || n > 10);
}

//Hiển thị
void TicTacToe::display(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << Board[i][j] << " ";
        }
        cout << endl;
    }
}

//Chọn nước đi
void TicTacToe::go(int &x, int &y){
    //Nhập dòng
    do{
        cout << "Line: ";
        cin >> x;
    }
    while(x < 1 || x > n);
    //Nhập cột
    do{
        cout << "Column: ";
        cin >> y;
    }
    while(y < 1 || y > n);
}

void TicTacToe::Player1(Player p){
    int x, y;
    p.displayName();
    cout << "'s turn: " << endl; //Thông báo đến lượt chơi
    do{
        go(x, y); //Chọn nước đi
    }
    while(Board[x][y] != 0); //Trong khi nước đi được chọn bị đánh dấu

    //Bước đi hợp lệ?
    Board[x][y] = 1; //Đánh dấu ô đã đi bởi người chơi 1

    //Ghi bước đi vào file
    {
        ofstream outfile;
        outfile.open("tictactoe.dat", ios::app);
        outfile << 1; //Mã người chơi 1
        outfile << " " << x << " " << y << endl;
        outfile.close();
    }
}

void TicTacToe::Player2(Player p){
    int x, y;
    p.displayName();
    cout << "'s turn: " << endl; //Thông báo đến lượt chơi
    do{
        go(x, y); //Chọn nước đi
    }
    while(Board[x][y] != 0); //Trong khi nước đi được chọn bị đánh dấu

    //Bước đi hợp lệ?
    Board[x][y] = 2; //Đánh dấu ô đã đi bởi người chơi 2

    //Ghi bước đi vào file
    {
        ofstream outfile;
        outfile.open("tictactoe.dat", ios::app);
        outfile << 2; //Mã người chơi 2
        outfile << " " << x << " " << y << endl;
        outfile.close();
    }
}

//=============================================================//
//ATTENTION!!!
//CORE FUNCTION BELOW
//=============================================================//
int TicTacToe::check(){
    int track1, track2; //Biến track để theo dõi theo hàng, cột, đường chéo tương ứng cho mỗi người chơi
    
    //Check hàng ngang
    for(int i = 1; i <= n; i++){
        track1 = 0, track2 = 0; //Reset 2 biến track cho mỗi lần xuống dòng
        for(int j = 1; j <= n; j++){
            if(Board[i][j] == 1) track1++; //Nếu ô được đánh dấu bởi Player1 thì đếm
            else if(Board[i][j] == 2) track2++; //Nếu ô được đánh dấu bởi Player2 thì đếm
        }
        {
            if(track1 == n){ //Nếu cả hàng hiện tại được Player1 đánh dấu hết
                gameOver = true; //thì kết thúc game
                return 1; //Người thắng cuộc là Player1
            }
            else if(track2 == n){ //Nếu cả hàng hiện tại được Player2 đánh dấu hết
                gameOver = true; //thì kết thúc game
                return 2; //Người thắng cuộc là Player2
            }
        }   
    }
    //Duyệt xong hàng ngang

    //====
    //Nếu chưa tìm thấy người thắng cuộc thì duyệt tiếp cột dọc

    //Check cột dọc
    for(int i = 1; i <= n; i++){
        track1 = 0; track2 = 0;
        for(int j = 1; j <= n; j++){
            if(Board[j][i] == 1) track1++;
            else if(Board[j][i] == 2) track2++;
        }
        {
            if(track1 == n){
                gameOver = true;
                return 1;
            }
            else if(track2 == n){
                gameOver = true;
                return 2;
            }
        }
    }
    //Duyệt xong cột dọc

    //====
    //Nếu chưa tìm thấy người thắng cuộc thì duyệt tiếp đường chéo chính
    
    //Check đường chéo chính
    track1 = 0; track2 = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            
            if(i == j){
                if(Board[i][j] == 1) track1++;
                else if(Board[i][j] == 2) track2++;
            }
        }
    }
    {
        if(track1 == n){
            gameOver = true;
            return 1;
        }
        else if(track2 == n){
            gameOver = true;
            return 2;
        }
    }
    //Duyệt xong đường chéo chính

    //====
    //Nếu chưa tìm thấy người thắng cuộc thì duyệt tiếp đường chéo phụ

    //Check đường chéo phụ
    track1 = 0, track2 = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            
            if(i+j == n-1){
                if(Board[i][j] == 1) track1++;
                else if(Board[i][j] == 2) track2++;
            }
        }
    }
    {
        if(track1 == n){
            gameOver = true;
            return 1;
        }
        else if(track2 == n){
            gameOver = true;
            return 2;
        }
    }
    //Duyệt xong đường chéo phụ

    //Nếu hàm chạy được đến đây thì tức là vẫn chưa tìm được người thắng cuộc
    gameOver = false;
    return 0;
    //Game sẽ tiếp tục
}

void operation(TicTacToe newGame, Player p1, Player p2){
    int winner = 0;
    //Reset file dữ liệu trước khi chơi
    {
        fstream file;
        file.open("tictactoe.dat", ios::out | ios::trunc);
        file.close();
    }
    //Bắt đầu các lượt đi
    do{
        newGame.Player1(p1); //Player1 đi
        cout << endl;
        newGame.display(); //Hiển thị kết qua sau bước đi
        cout << endl;
        //Check mỗi lượt xem đã có người thắng cuộc chưa
        winner = newGame.check(); //Nếu có người thắng cuộc thì sẽ trả về mã tương ứng, và set gameOver = true
        if(winner == 1) break; //Nếu Player1 thắng thì kết thúc game luôn

        newGame.Player2(p2); //Player2 đi
        cout << endl;
        newGame.display(); //Hiển thị kết qua sau bước đi
        cout << endl;
        winner = newGame.check(); //Nếu có người thắng cuộc thì sẽ trả về mã tương ứng, và set gameOver = true
    }
    while(gameOver == false && winner == 0);

    //Đã tìm được người thắng cuộc
    cout << "We've found a winner!" << endl << endl;
    switch(winner){
        case 1:{
            cout << "Congratulations! ";
            p1.displayName();
            cout << " won!" << endl;
            break;
        }
        case 2:{
            cout << "Congratulations! ";
            p2.displayName();
            cout << " won!" << endl;
            break;
        }
    }
}

main(){
    int choice = 0;
    TicTacToe newGame;
    Player p1, p2;
    cout << "Welcome to TicTacToe - the might-be most retarded game ever created!" << endl;
    cout << "================" << endl;
    cout << "Are you guys here to play today?" << endl;
    cout << "Yes: 1, No: 0" << endl;
    do{
        cin >> choice;
    }
    while(choice < 0 || choice > 1);
    if(choice == 0){
        cout << "Goodbye!" << endl;
        exit(1);
    }

    cout << "Let us begin the game!!" << endl;
    cout << "================" << endl;

    cin.ignore();
    cout << "Player 1 - ";
    p1.typeInName();
    cout << "Player 2 - ";
    p2.typeInName();
    cout << endl;

    //Bắt đầu game
    while(choice == 1){
        //Chọn size của board để chơi
        cout << "How big is the board you want to play? (3-10)" << endl;
        newGame.typeInSize();
        cout << endl;

        //In ra board rỗng khởi đầu
        newGame.display();

        operation(newGame, p1, p2);
        //Game kết thúc
        cout << "Game over!" << endl << endl;
        cout << "Do you want to play again?" << endl;
        cout << "Yes: 1, No: 0" << endl;
        do{
            cin >> choice;
        }
        while(choice < 0 || choice > 1);
    }
    //Người chơi không muốn chơi tiếp
    cout << "Goodbye!" << endl;
}