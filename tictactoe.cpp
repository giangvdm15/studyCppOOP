#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

bool gameOver = false;

class TicTacToe{
    friend void operation(TicTacToe);
    private:
        int Board[3][3];
    public:
        TicTacToe();
        void go(int&, int&);
        void Player1();
        void Player2();
        int check();
};

//Hàm tạo: reset bàn chơi
TicTacToe::TicTacToe(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            Board[i][j] = 0;
        }
    }
}

//Chọn nước đi
void TicTacToe::go(int &x, int &y){
    //Nhập dòng
    do{
        cout << "Dong: ";
        cin >> x;
    }
    while(x < 0 || x > 2);
    //Nhập cột
    do{
        cout << "Cot: ";
        cin >> y;
    }
    while(y < 0 || y > 2);
}

void TicTacToe::Player1(){
    int x, y;
    cout << "Den luot Player1: " << endl; //Thông báo đến lượt chơi
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

void TicTacToe::Player2(){
    int x, y;
    cout << "Den luot Player2: " << endl; //Thông báo đến lượt chơi
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

int TicTacToe::check(){

}

void operation(TicTacToe newGame){
    int winner = 0;
    //Reset file dữ liệu trước khi chơi
    {
        ofstream outfile;
        outfile.open("tictactoe.dat", ios::out);
        outfile.close();
    }
    //Bắt đầu chơi
    while(!gameOver){
        newGame.Player1();
        newGame.Player2();
        winner = newGame.check();

    }

}

main(){
    int choice = 0;
    TicTacToe newGame;
    // cout << "Welcome to TicTacToe - the might-be most retarded game ever created!" << endl;
    // cout << "================" << endl;
    // cout << "Are you guys here to play today?" << endl;
    // cout << "Yes: 1, No: 0";
    // do{
    //     cin >> choice;
    // }
    // while(choice < 0 || choice > 1);
    // cout << "Let us begin the game!!" << endl;;
    // cout << "================" << endl;;
    if(choice == 0){
        cout << "Such a wise choice! Good bye and please don't come back!" << endl;
        exit(1);
    }
    //Bắt đầu game
    while(choice == 1){
        operation(newGame);
    }
    newGame.Player1();
    
}