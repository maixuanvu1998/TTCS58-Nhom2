#include <iostream>
#include <string>

#include "bai2.h"


using namespace std;

HoKhau *dauHoKhau;

int main() {
    khoiTao(dauHoKhau);
    nhapDSHK(dauHoKhau);

    // xuat ra thong tin chi tiet cua cac ho
    inHoKhau(dauHoKhau);

    // xuat ra thong tin ho khau chi dinh
    string tmp;
    cout << "nham so ho khau can xuat: ";
    getline(cin, tmp);
    inDSThanhVien(dauHoKhau, tmp);

    // kiem tra hang xe co o cac ho hay khong
    string hieuXe;
    cout << "Nhap hieu xe can kiem tra: ";
    getline(cin, hieuXe);
    cout << "co hieu xe: " << kiemTraXe(dauHoKhau, hieuXe) << endl;


    // xoa 1 xe chi dinh
    string maXe, soHoKhau;
    cout << "Nhap so ho khau co xe can xoa: ";
    getline(cin, soHoKhau);
    cout << "Nhap ma xe can xoa: ";
    getline(cin, maXe);
    xoaXe(dauHoKhau, maXe, soHoKhau);
    inHoKhau(dauHoKhau);

}
