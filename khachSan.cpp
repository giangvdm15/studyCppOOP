#include <iostream>
#include <fstream>
#include <cstring>
#define max 100
using namespace std;

class Nguoi{
    private:
        string ten;
        string email;
        char sdt[11];
    public:
        void nhap();
        void docFile();
        void hienThi();
};

void Nguoi::nhap(){
    cout << "Nhap ten: ";
    //cin.ignore();
    getline(cin, ten);
    cout << "Nhap email: ";
    getline(cin, email);
    cout << "Nhap so dien thoai: ";
    cin >> sdt;
}

void Nguoi::docFile(){
    ifstream infile;
    infile.open("kh.dat");
    while(infile.eof() == 0){
        getline(cin, ten);
        getline(cin, email);
        infile >> sdt;
    }
    infile.close();
}

void Nguoi::hienThi(){
    cout << "Ten: " << ten << endl;
    cout << "Email: " << email << endl;
    cout << "So dien thoai: " << sdt << endl;
}

class khachHang :public Nguoi{
    friend class BangSapXep;
    private:
        int maKH;
        int kieuPhong;
        string moTa;
        static int count;
    public:
        static void genMaKH(){count++;};
        void nhap();
        void ghiFile();
        void docFile();
        void hienThi();
};

int khachHang::count = 100;

void khachHang::nhap(){
    khachHang::genMaKH();
    Nguoi::nhap();
    cout << "Nhap kieu phong can thue";
    cout << endl << " (1: Phong don, 2: Phong doi, 3: Phong VIP): ";
    do{
        cin >> kieuPhong;
    }
    while(kieuPhong < 1 || kieuPhong > 3);
    cout << "Mo ta them: ";
    cin.ignore();
    getline(cin, moTa);
    maKH = count;
}

void khachHang::ghiFile(){
    ofstream outfile;
    outfile.open("kh.dat", ios::app);
    outfile << maKH << " " << ten << " " << email << " " << sdt << " " << kieuPhong << " " << moTa << endl;
    outfile.close();
}

void khachHang::docFile(){
    ifstream infile;
    infile.open("kh.dat");
    cout << "Danh sach khach hang thue phong: " << endl;
    while(infile.eof() == 0){
        infile >> maKH;
        Nguoi::docFile();
        infile >> kieuPhong;
        getline(cin, moTa);
        khachHang::hienThi();
    }
    infile.close();
}

void khachHang::hienThi(){
    cout << "Ma so: " << maKH << endl;
    Nguoi::hienThi();
    cout << "Kieu phong can thue: " << kieuPhong << endl;
    cout << "Mo ta them: " << moTa << endl;
}

class Phong{
    friend class BangSapXep;
    private:
        int maPhong;
        int kieu;
        int phi;
        static int count;
    public:
        static void genMaPhong(){count++;};
        void nhap();
        void ghiFile();
        void docFile();
        void tren1Trieu();
        void hienThi();
};

int Phong::count = 101;

void Phong::nhap(){
    Phong::genMaPhong();
    maPhong = count;
    cout << "Nhap kieu phong ";
    cout << endl << "(1: Phong don, 2: Phong doi, 3: Phong VIP): ";
    do{
        cin >> kieu;
    }
    while(kieu < 1 || kieu > 3);
    cout << "Nhap phi thue phong (nghin VND): ";
    do{
        cin >> phi;
    }
    while(phi <= 0);
}

void Phong::hienThi(){
    cout << "Ma phong: " << maPhong << endl;
    cout << "Kieu phong: ";
    switch(kieu){
        case 1:{
            cout << "Phong don" << endl;
            break;
        }
        case 2:{
            cout << "Phong doi" << endl;
            break;
        }
        case 3:{
            cout << "Phong VIP" << endl;
            break;
        }
    }
    cout << "Phi thue phong: " << phi << endl;
}

void Phong::ghiFile(){
    ofstream outfile;
    outfile.open("ph.dat", ios::app);
    outfile << maPhong << " " << kieu << " " << phi << endl;
    outfile.close();
}

void Phong::tren1Trieu(){
    ifstream infile;
    infile.open("ph.dat");
    cout << "Danh sach phong co phi tren 1 trieu: " << endl;
    while(infile.eof() == 0){
        infile >> maPhong;
        infile >> kieu;
        infile >> phi;
        if(phi > 1000){
            Phong::hienThi();
            cout << endl;
        }
    }
    //cout << phi << "  ";
    //cout << maPhong << " " << kieu << " " << phi << endl;
    infile.close();
}

// void Phong::tren1Trieu(){
//     cout << phi;
//     if(phi > 1000){
//         cout << "Danh sach phong co phi tren 1 trieu: " << endl;
//         Phong::hienThi();
//         cout << endl;
//     }
// }

class BangSapXep{

};

main(){
    khachHang guest;
    int soKhach;
    cin >> soKhach;
    for(int i = 0; i < soKhach; i++){
        guest.nhap();
        guest.ghiFile();
    }
    cout << endl;


    Phong room;
    int soPhong;
    cin >> soPhong;
    for(int i = 0; i < soPhong; i++){
        room.nhap();
        room.ghiFile();
    }
    room.tren1Trieu();
}