#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
using namespace std;

class Time{
    private:
        int hour, minute, second;
    public:
        void input();
        void display24();
};

void Time::input(){
    do{
        cout << "Hour = ";
        cin >> hour;
    }
    while(hour >= 24 || hour < 0);
    do{
        cout << "Minute = ";
        cin >> minute;
    }
    while(minute >= 60 || minute < 0);
    do{
        cout << "Second = ";
        cin >> second;
    }
    while(second >= 60 || second < 0);
}

void Time::display24(){
    cout << setfill('0') << setw(2) << hour << ":";
    cout << setfill('0') << setw(2) << minute << ":";
    cout << setfill('0') << setw(2) << second << endl;
}

main(){
    Time t;
    t.input();
    cout << "The time is: ";
    t.display24();
}