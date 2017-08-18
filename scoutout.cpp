#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
using namespace std;

class User{
    protected:
        string email;
        string password;
    public:
        void signUp();
        void display();
};

void User::signUp(){
    cout << "Enter email: ";
    getline(cin, email);
    cout << "Enter password: ";
    getline(cin, password);
}

void User::display(){
    cout << "Email: " << email << endl;
    cout << "Password: ";
    for(int i = 0; i < password.length(); i++) cout << "*";
    cout << endl;
}

class Athlete :public User{
    friend class Game;
    private:
        string firstName;
        string lastName;
        string team;
        float height;
        float weight;
    public:
        void signUp();
        void input();
        void writeToFile();
        void display();
        //void addGame();
};

void Athlete::signUp(){
    User::signUp();
    Athlete::input();
    Athlete::writeToFile();
}

void Athlete::input(){
    cout << "First Name: ";
    getline(cin, firstName);
    cout << "Last Name: ";
    getline(cin, lastName);
    cout << "Current Team: ";
    getline(cin, team);
    cout << "Height: ";
    cin >> height;
    cout << "Weight: ";
    cin >> weight;
}

void Athlete::writeToFile(){
    ofstream outfile;
    outfile.open("athlete.dat", ios::app);
    outfile << email << " " << password << " ";
    outfile << firstName << " " << lastName << " " << team << " " << height << " " << weight;
    outfile.close();
}

void Athlete::display(){
    User::display();
    cout << "First Name: " << firstName << "\t" << "Last Name: " << lastName << endl;
    cout << "Current Team: " << team << endl;
    cout << "Height: " << height << "\t" << "Weight: " << weight << endl;
}

class Scout :public User{
    friend class Game;
    private:
        string firstName;
        string lastName;
        string designation;
    public:
        void signUp();
        void input();
        void display();
        void acceptGame();
};

class Game{
    private:
        string gameName;
    public:
        void add();
        void accept();
};

void Game::add(){
    ofstream outfile;
    outfile.open("game.dat", ios::app);
    outfile.close();
    getline(cin, gameName);

}

void athleteMenu(){
    cout << 
}

main(){
    Athlete ath;
    Scout sct;
    string chooseApp;
    short choice = 0;
    cout << "Welcome to ScoutOut!" << endl;
    cout << "Are you an Athlete or a Scout?" << endl;
    getline(cin, chooseApp);
    switch(chooseApp){
        case "athlete":{
            
        }
        case "scout":{

        }
    }
}