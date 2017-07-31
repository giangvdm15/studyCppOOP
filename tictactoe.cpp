#include <iostream>
#include <fstream>
#include <stdlib.h>
#define max 10
using namespace std;

bool gameOver = false;

class TicTacToe{
    friend void operation(TicTacToe);
    private:
        int n; //size
        int Board[max][max];
    public:
        TicTacToe();
        void go(int &x, int &y);
        void typeInSize();
        void display();
        void Player1();
        void Player2();
        int check();
};

//Hàm tạo: reset bàn chơi
TicTacToe::TicTacToe(){
    for(int i = 0; i < max; i++){
        for(int j = 0; j < max; j++){
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
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << Board[i][j] << " ";
        }
        cout << endl;
    }
}

//Chọn nước đi
void TicTacToe::go(int &x, int &y){
    //Nhập dòng
    do{
        cout << "Dong: ";
        cin >> x;
    }
    while(x < 0 || x > n);
    //Nhập cột
    do{
        cout << "Cot: ";
        cin >> y;
    }
    while(y < 0 || y > n);
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

//=============================================================//
//ATTENTION!!!
//CORE FUNCTION BELOW
//=============================================================//
int TicTacToe::check(){
    int track1, track2; //Biến track để theo dõi theo hàng, cột, đường chéo tương ứng cho mỗi người chơi
    
    //Check hàng ngang
    for(int i = 0; i < n; i++){
        track1 = 0, track2 = 0; //Reset 2 biến track cho mỗi lần xuống dòng
        for(int j = 0; j < n; j++){
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
    for(int i = 0; i < n; i++){
        track1 = 0; track2 = 0;
        for(int j = 0; j < n; j++){
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
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
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
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            
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

void operation(TicTacToe newGame){
    int winner = 0;
    //Reset file dữ liệu trước khi chơi
    {
        fstream file;
        file.open("tictactoe.dat", ios::out | ios::trunc);
        file.close();
    }
    //Bắt đầu các lượt đi
    do{
        newGame.Player1(); //Player1 đi
        cout << endl;
        newGame.display(); //Hiển thị kết qua sau bước đi
        cout << endl;
        //Check mỗi lượt xem đã có người thắng cuộc chưa
        winner = newGame.check(); //Nếu có người thắng cuộc thì sẽ trả về mã tương ứng, và set gameOver = true
        if(winner == 1) break; //Nếu Player1 thắng thì kết thúc game luôn

        newGame.Player2(); //Player2 đi
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
            cout << "Congratulations! Player1 won!" << endl;
            break;
        }
        case 2:{
            cout << "Congratulations! Player2 won!" << endl;
            break;
        }
    }
}

main(){
    int choice = 0;
    TicTacToe newGame;
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

    cout << "Let us begin the game!!" << endl;;
    cout << "================" << endl;;

    //Bắt đầu game
    while(choice == 1){
        //Chọn size của board để chơi
        cout << "How big is the board you want to play? (3-10)" << endl;
        newGame.typeInSize();

        //In ra board rỗng khởi đầu
        newGame.display();

        operation(newGame);
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