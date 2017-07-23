#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

class Nguoi{
    private:
        int ID;
        string ten;
        int gioiTinh; //0 = nu, 1 = nam
        static int dem;
    public:
        void nhap();
        void hienThi();
};

int Nguoi::dem = 1;

void Nguoi::nhap(){
    cout << "ID: " << dem << endl;
    ID = dem++; //ID tu dong tang
    cout << "Ho ten: "; getline(cin, ten);
    do{
        cout << "Gioi tinh (0: nu, 1: nam): ";
        cin >> gioiTinh;
    }
    while(gioiTinh > 1 || gioiTinh < 0);
}

void Nguoi::hienThi(){
    cout << ID << ", " << ten << ", ";
    (gioiTinh == 0) ? cout << "nu" : cout << "nam";
}

class sinhVien : public Nguoi{
    private:
        float diem;
        float hocPhi;
        string nganh;
    public:
        void nhap();
        void hienThi();
};

void sinhVien::nhap(){
    Nguoi::nhap();
    do{
        cout << "Diem: ";
        cin >> diem;
    }
    while(diem < 0 || diem > 10);
    do{
        cout << "Hoc phi: ";
        cin >> hocPhi;
    }
    while(hocPhi < 0);
    cout << "Nganh hoc: "; 
    cin.ignore();
    getline(cin, nganh);
}

void sinhVien::hienThi(){
    Nguoi::hienThi();
    cout << ", "<< diem << ", " << hocPhi << ", " << nganh;
}
main(){
    sinhVien human;
    human.nhap();
    human.hienThi();
    return 0;
}