#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

ifstream f("input.txt");



// ===== NhanVien =====
class NhanVien {
    string maSo, hoTen;
    int heSoLuong;
    string chucVu;
    int heSoCV;
    static int luongCoBan;
public:
    void nhap();
    void xuat();
    int tinhLuong();
    friend class DSNV;
};

int NhanVien::luongCoBan = 1100;

void NhanVien::nhap() {
    string s;
    getline(f, s); maSo = s;
    getline(f, s); hoTen = s;
    getline(f, s); heSoLuong = atoi(s.c_str());
    getline(f, s); chucVu = s;
    getline(f, s); heSoCV = atoi(s.c_str());
}

void NhanVien::xuat() {
    cout << "Ma so: " << maSo << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "He so luong: " << heSoLuong << endl;
    cout << "Chuc vu: " << chucVu << endl;
    cout << "He so chuc vu: " << heSoCV << endl;
}

int NhanVien::tinhLuong() {
    return luongCoBan* (heSoLuong + heSoCV);
}

// ===== DSNV =====

class DSNV {
    int n;
    vector <NhanVien> ds;
public:
    void nhapDs();
    void xuatDs();
    void inLuongTangDan();

//    friend bool kiemTra();
};

void DSNV::nhapDs() {
    if (f.fail()) {
        cout << "Faild to open this file !" << endl;
    } else {
        string s;
        getline(f, s); n = atoi(s.c_str());
        ds.resize(n);
        for (int i = 0; i < n; i++) {
            ds[i].nhap();
        }
    }

    f.close();
}
void DSNV::xuatDs() {
    cout << "DANH SACH NHAN VIEN" << endl;
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
        cout << "=====" << endl;
    }
}


bool kiemTra(int m, int arr[], int n) {
    for (int i = 0 ; i < n ; i++ ) {
        if (arr[i] == m) {
            return 1;
        }
    }
    return 0;
}

void DSNV::inLuongTangDan() {
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }


    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++) {
            if (ds[arr[j]].tinhLuong() < ds[arr[j+1]].tinhLuong())
                swap(arr[j], arr[j+1]);
        }

    cout << "Bang Luong: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Ma so: " << ds[arr[i]].maSo << endl;
        cout << "Ho ten: " << ds[arr[i]].hoTen << endl;
        cout << "Luong: " << ds[arr[i]].tinhLuong() << endl;
    }

}





/*
    tao arr[], arr[1, 2, 3, 4, 5, 6, n]
    arr[
    if ds[i].sdf < ds[i].sdlf
        swap
*/



int main() {
    DSNV ds;
    ds.nhapDs();
    ds.xuatDs();
    ds.inLuongTangDan();
}
