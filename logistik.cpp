#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

class Package{
    private:
        //sender
        string senderName;
        string senderAddress;
        string senderCity;
        string senderProvince;
        //recipient
        string recName;
        string recAddress;
        string recCity;
        string recProvince;
        //package
        float mass; //(kg)
        float cost; //($/kg)
    public:
        Package();
        void input();
        void display();
        double calculateCost();
        float getMass(){return mass;};
};

Package::Package(){
    senderName = "GEM Vietnam";
    senderAddress = "26th Floor, Handico Tower";
    senderCity = "Hanoi";
    senderProvince = "Nam Tu Liem";
    recName = "Harvey Nash Vietnam";
    recAddress = "Xuan Thuy";
    recCity = "Hanoi";
    recProvince = "Cau Giay";
    cost = 1.5;
}

void Package::input(){
    do{
        cin >> mass;
    }
    while(mass <= 0);
}

void Package::display(){
    cout << "Sender's Info: " << endl;
    cout << "================" << endl;
    cout << "Name: " << senderName << endl;
    cout << "Address: " << senderAddress << ", " << senderProvince << ", " << senderCity << endl;
    cout << endl;
    cout << "Recipient's Info: " << endl;
    cout << "================" << endl;
    cout << "Name: " << recName << endl;
    cout << "Address: " << recAddress << ", " << recProvince << ", " << recCity << endl;
    cout << endl;
    cout << "Package's Info: " << endl;
    cout << "================" << endl;
    cout << "Mass (kg): " << mass << endl;
    cout << "Delivery cost ($/kg): " << cost << endl;
}

double Package::calculateCost(){
    return (mass*cost);
}

class TwoDayPackage :public Package{
    private:
        float storageCost; //per 2 days
    public:
        TwoDayPackage(){storageCost = 1.25;};
        void input(){Package::input();};
        void display();
        double calculateCost();
};

void TwoDayPackage::display(){
    Package::display();
    cout << "The Package will be stored for 2 days, thus the extra cost is ($): " << storageCost << endl;
}

double TwoDayPackage::calculateCost(){
    return Package::calculateCost()+storageCost;
}

class OvernightPackage :public Package{
    private:
        float extraCost; // ($/kg)
    public:
        OvernightPackage(){extraCost = 0.75;};
        void input(){Package::input();};
        void display();
        double calculateCost();
};

void OvernightPackage::display(){
    Package::display();
    cout << "The package will be delivered within today, thus the extra cost is ($): " << extraCost << endl;
}

double OvernightPackage::calculateCost(){
    return Package::calculateCost()+(getMass()*extraCost);
}

main(){
    int choice;
    double totalCost = 0;
    Package p0;
    TwoDayPackage p2;
    OvernightPackage p1;
    cout << "Turtle Logistics Company, at your serivce." << endl;
    cout << "================" << endl;
    cout << "Welcome GEM Vietnam! What do you want to do today?" << endl << endl;
    cout << "1. Deliver a Package within a day." << endl;
    cout << "2. Store a Package for 2 days." << endl;
    cout << "0. Exit" << endl;
    do{
        cin >> choice;
    }
    while(choice < 0 || choice > 2);

    if(choice == 0){
        cout << "Goodbye!";
        exit(1);
    }

    cout << "Please input your Package's mass: ";
    switch(choice){
        case 1:{
            p1.input();
            cout << endl << endl;
            p1.display();
            totalCost = p1.calculateCost();
            cout << endl << "Your total cost for this service is ($): " << totalCost << endl;
            cout << "Thank you for using our service. We're looking to serving you again!" << endl;
            break;
        }
        case 2:{
            p2.input();
            cout << endl << endl;
            p2.display();
            totalCost = p2.calculateCost();
            cout << endl << "Your total cost for this service is ($): " << totalCost << endl;
            cout << "Thank you for using our service. We're looking to serving you again!" << endl;
            break;
        }
    }
}