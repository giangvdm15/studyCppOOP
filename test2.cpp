#include <iostream>
#include <iomanip>
#include <cstring>
#define max 100
using namespace std;

class sinhVien{
    friend void diemTangDan(sinhVien[], int);
    private:
        string ID;
        string ten;
        float diem;
    public:
        void nhap();
        void hienThi(){
            cout << ID << ", " << ten << ", " << diem << endl;
        }
};

void sinhVien::nhap(){
    cin.ignore();
    cout << "Nhap ID: "; getline(cin, ID);
    
    cout << "Nhap ten: "; getline(cin, ten);
    do{
        cout << "Nhap diem: ";
        cin >> diem;
    }
    while(diem < 0 || diem > 10);
}

void nhapDS(sinhVien ds[], int &n){
    cout << "Do dai danh sach = "; cin >> n;
    for(int i = 0; i < n; i++){
        cout << "#" << i+1 << endl;
            ds[i].nhap();
    }
}

void hienThiDS(sinhVien ds[], int n){
    for(int i = 0; i < n; i++){
        ds[i].hienThi();
    }
}

void diemTangDan(sinhVien ds[], int n){
    sinhVien tmp;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(ds[i].diem > ds[j].diem){
                tmp = ds[i];
                ds[i] = ds[j];
                ds[j] = tmp;
            }
        }
    }
}

main(){
    sinhVien sv[max];
    int n;
    nhapDS(sv, n);
    cout << "Danh sach vua nhap: " << endl;
    hienThiDS(sv, n);
    cout << endl << "Danh sach sau khi sap xep theo diem tang dan cua sinh vien: " << endl;
    diemTangDan(sv, n);
    hienThiDS(sv, n);
}