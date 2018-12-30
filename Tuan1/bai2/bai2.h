#ifndef BAI2_H_INCLUDED
#define BAI2_H_INCLUDED



#endif // BAI2_H_INCLUDED

#include "libbai2.h"

struct Xe;
struct Con;
struct HoKhau;
void khoiTao(HoKhau *&dauHoKhau);
void nhapDSC (Con *&dauCon);
void nhapDSX (Xe *&dauXe);
void nhapDSHK(HoKhau *&dauHoKhau);
void inXe(Xe *dauXe);
void inCon(Con *dauCon);
void inHoKhau(HoKhau *dauHoKhau);
void inDSThanhVien(HoKhau *&dauHoKhau, string soHoKhau);
bool kiemTraXe(HoKhau *&dauHoKhau, string hieuXe);
void xoaDau(HoKhau *&dauHoKhau ,Xe *& dauXe);
void xoaXe(HoKhau *&dauHoKhau, string maXe, string soHoKhau);
